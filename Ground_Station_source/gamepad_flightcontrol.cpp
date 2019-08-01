#include "gamepad_flightcontrol.h"

Gamepad_FlightControl::Gamepad_FlightControl(QObject *parent) : QObject(parent)
{
    direct_input_interface = 0;
    keyboard = 0;
    mouse = 0;
}

void Gamepad_FlightControl::setup_gamepad(QGamepad *dialog_selected_gamepad)
{
    selected_gamepad = dialog_selected_gamepad;
}

void Gamepad_FlightControl::run_gamepad()
{
    QList<double> commanded_controls;
    commanded_controls << selected_gamepad->axisLeftX() << selected_gamepad->axisLeftY() << selected_gamepad->axisRightX() << selected_gamepad->axisRightY() <<
                          selected_gamepad->buttonStart() << selected_gamepad->buttonSelect() << selected_gamepad->buttonA() << selected_gamepad->buttonB() << selected_gamepad->buttonX() <<
                          selected_gamepad->buttonY() << selected_gamepad->buttonL1() << selected_gamepad->buttonL2() << selected_gamepad->buttonR1() << selected_gamepad->buttonR2() <<
                          selected_gamepad->buttonL3() << selected_gamepad->buttonLeft() << selected_gamepad->buttonRight() << selected_gamepad->buttonR3() <<
                          selected_gamepad->buttonDown() << selected_gamepad->buttonUp() << selected_gamepad->buttonCenter();

    emit this->update_commandedcontrols(commanded_controls);
}

bool Gamepad_FlightControl::Direct_Input_initialize(HINSTANCE h_instance, int screenWidth, int screenHeight)
{
    HRESULT result;

    // Store the screen size which will be used for positioning the mouse cursor.
    current_screenWidth = screenWidth;
    current_screenHeight = screenHeight;

    // Initialize the location of the mouse on the screen.
    current_mouseX = 0;
    current_mouseY = 0;

    // This function call will initialize the interface to Direct Input. Once you have a Direct Input object you can initialize other input devices.
    // Initialize the main Direct Input interface.
    result = DirectInput8Create(h_instance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&direct_input_interface, NULL);

    // Check fail result:
    if (FAILED(result))
    {
        return false;
    }

    // Enumerates available controller devices of type gamepad:
    direct_input_interface->EnumDevices(DI8DEVCLASS_GAMECTRL, &staticEnumerateGameControllers, this, DIEDFL_ATTACHEDONLY);

    // Take first controller:
    LPDIRECTINPUTDEVICE8 selected_gameController = gamepad_controllers_available[2];

    // Set cooperation level:
    //  - DISCL_BACKGROUND: receive notifications when the application is in the background as well as in the foreground.
    //  - DISCL_EXCLUSIVE: exclusive access: no other application can request exclusive access to the game controller.
    result = selected_gameController->SetCooperativeLevel(NULL, DISCL_BACKGROUND | DISCL_EXCLUSIVE);

    // Set data format:
    selected_gameController->SetDataFormat(&c_dfDIJoystick);

    QList<uint> axes;
    DIDEVCAPS capabilities;
    capabilities.dwSize = sizeof(DIDEVCAPS);

    for(uint8_t i = 0; i < gamepad_controllers_available.size(); i++)
    {
        if (FAILED(gamepad_controllers_available[i]->GetCapabilities(&capabilities)));
        else
        {
            axes.append(capabilities.dwAxes);
        }
    }

    // Acquire the game controller:
    gamepad_controllers_available[2]->Acquire();

    //Save last state:
    gameControllerStatePrevious = gameControllerStateCurrent;

    // Get controller state:
    gamepad_controllers_available[2]->GetDeviceState(sizeof(DIJOYSTATE), &gameControllerStateCurrent);

    return true;
}

BOOL Gamepad_FlightControl::staticEnumerateGameControllers(LPCDIDEVICEINSTANCE device_instance, LPVOID pvRef)
{
    Gamepad_FlightControl* inputHandlerInstance = (Gamepad_FlightControl*)pvRef;
    return inputHandlerInstance->enumerateGameControllers(device_instance);
}

bool Gamepad_FlightControl::enumerateGameControllers(LPCDIDEVICEINSTANCE device_instance)
{
    // Device variable:
    LPDIRECTINPUTDEVICE8 gameController;

    // Create interface for the current game controller:
    if (FAILED(direct_input_interface->CreateDevice(device_instance->guidInstance, &gameController, NULL)))
        return DIENUM_CONTINUE;
    else
    {
        // Store the game controller:
        gamepad_controllers_available.append(gameController);
        qDebug() << device_instance->tszInstanceName;
        return DIENUM_CONTINUE; // Continue to next game controller.
    }
}


void Gamepad_FlightControl::Shutdown()
{
    // Release the mouse.
    if(mouse)
    {
        mouse->Unacquire();
        mouse->Release();
        mouse = 0;
    }

    // Release the keyboard.
    if(keyboard)
    {
        keyboard->Unacquire();
        keyboard->Release();
        keyboard = 0;
    }

    // Release the main interface to direct input.
    if(direct_input_interface)
    {
        direct_input_interface->Release();
        direct_input_interface = 0;
    }

    return;
}

bool Gamepad_FlightControl::Frame()
{
    bool result;


    // Read the current state of the keyboard.
    result = ReadKeyboard();
    if(!result)
    {
        return false;
    }

    // Read the current state of the mouse.
    result = ReadMouse();
    if(!result)
    {
        return false;
    }

    // Process the changes in the mouse and keyboard.
    ProcessInput();

    return true;
}

bool Gamepad_FlightControl::ReadKeyboard()
{
    HRESULT result;

    // Read the keyboard device.
    result = keyboard->GetDeviceState(sizeof(current_keyboardState), (LPVOID)&current_keyboardState);
    if(FAILED(result))
    {
        // If the keyboard lost focus or was not acquired then try to get control back.
        if((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
        {
            keyboard->Acquire();
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool Gamepad_FlightControl::ReadMouse()
{
    HRESULT result;

    // Read the mouse device.
    result = mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&current_mouseState);
    if(FAILED(result))
    {
        // If the mouse lost focus or was not acquired then try to get control back.
        if((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
        {
            mouse->Acquire();
        }
        else
        {
            return false;
        }
    }

    return true;
}

void Gamepad_FlightControl::ProcessInput()
{
    // Update the location of the mouse cursor based on the change of the mouse location during the frame.
    current_mouseX += current_mouseState.lX;
    current_mouseY += current_mouseState.lY;

    // Ensure the mouse location doesn't exceed the screen width or height.
    if(current_mouseX < 0)  { current_mouseX = 0; }
    if(current_mouseY < 0)  { current_mouseY = 0; }

    if(current_mouseX > current_screenWidth)  { current_mouseX = current_screenWidth; }
    if(current_mouseY > current_screenHeight) { current_mouseY = current_screenHeight; }

    return;
}

void Gamepad_FlightControl::update()
{
    HRESULT result;

    result = gamepad_controllers_available[2]->Poll();

    if((result == DI_OK) || (result == DI_NOEFFECT))
    {
        DIJOYSTATE gameControllerState;

        result = gamepad_controllers_available[2]->GetDeviceState(sizeof(DIJOYSTATE), &gameControllerState);

        if(FAILED(result))
        {
            qDebug() << "Caca";
        }
    }
    else
    {
        if((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
        {
            gamepad_controllers_available[2]->Acquire();
        }
        else{
            qDebug() << "Menuda mierdaaaaaa";
        }
    }
}
