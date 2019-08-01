#ifndef GAMEPAD_FLIGHTCONTROL_H
#define GAMEPAD_FLIGHTCONTROL_H

#include <QObject>

// ------------------------------------------------------------------------------
//   QGamepad files
// ------------------------------------------------------------------------------
#include <QGamepad>
#include <QGamepadKeyNavigation>

// ------------------------------------------------------------------------------
//   DirectInput files
// ------------------------------------------------------------------------------
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
// These libraries were added in the .pro file, under the LIBS category:
//#pragma comment (lib, "dinput8.lib")
//#pragma comment (lib, "dxguid.lib")

#include <QDebug>


class Gamepad_FlightControl : public QObject
{
    Q_OBJECT
public:
    explicit Gamepad_FlightControl(QObject *parent = nullptr);

    bool Direct_Input_initialize(HINSTANCE, int, int);
    void Shutdown();
    bool Frame();

    bool IsEscapePressed();
    void GetMouseLocation(int&, int&);

signals:
    void update_gamepadlist(QList<int> gamepadlist);
    void update_commandedcontrols(QList<double> commanded_controls);

public slots:
    void setup_gamepad(QGamepad *dialog_selected_gamepad);
    void run_gamepad();
    void update();

private:
    QList<LPDIRECTINPUTDEVICE8> gamepad_controllers_available;

    IDirectInput8* direct_input_interface; // Main DirectInput device.
    IDirectInputDevice8* keyboard;
    IDirectInputDevice8* mouse;

    unsigned char current_keyboardState[256];
    DIMOUSESTATE current_mouseState;

    DIJOYSTATE gameControllerStateCurrent, gameControllerStatePrevious;

    int current_screenWidth, current_screenHeight;
    int current_mouseX, current_mouseY;

    QGamepad *selected_gamepad = new QGamepad(1, this);

    bool ReadKeyboard();
    bool ReadMouse();
    void ProcessInput();
    static BOOL CALLBACK staticEnumerateGameControllers(LPCDIDEVICEINSTANCE devInst, LPVOID pvRef);
    bool enumerateGameControllers(LPCDIDEVICEINSTANCE device_instance);
};

#endif // GAMEPAD_FLIGHTCONTROL_H
