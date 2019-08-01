#include "dialog_flightcontrol.h"

Dialog_FlightControl::Dialog_FlightControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FlightControl)
{
    ui->setupUi(this);

    // Configure minimize button:
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);

    // Register QList in order to allow signal/slot connections:
    qRegisterMetaType<QList<double>>();

    connect(this, SIGNAL(show_dialog()), this, SLOT(setup_gamepad_dialog()));

    // Set rates for gamepad read/send commands:
    gamepad_rate = 1;
}

Dialog_FlightControl::~Dialog_FlightControl()
{
    delete ui;
}

void Dialog_FlightControl::showEvent(QShowEvent *ev)
{
    QDialog::showEvent(ev);

    // Setup the dialog:
    emit show_dialog();
}

void Dialog_FlightControl::setup_gamepad_dialog()
{
    // Connects the signals to update the gamepad dialog:
    connect(ui->pushButton_updategamepads, SIGNAL(clicked(bool)), this, SLOT(update_gamepadslist()));
    connect(timer_commandedcontrols, SIGNAL(timeout()), gamepad_obj, SLOT(run_gamepad()));
    connect(this, SIGNAL(setup_gamepad(QGamepad*)), gamepad_obj, SLOT(setup_gamepad(QGamepad*)));
    connect(gamepad_obj, SIGNAL(update_commandedcontrols(QList<double>)), this, SLOT(read_commandedcontrols(QList<double>)));

    // Initial determination of available gamepads:
    update_gamepadslist();

    //HINSTANCE instance = GetModuleHandle(NULL);
    //gamepad_obj->Direct_Input_initialize(instance, 5, 5);

    //connect(timer_commandedcontrols, SIGNAL(timeout()), gamepad_obj, SLOT(update()));

    // Move the gamepad object to another thread in order to avoid the Dialog_Gamepad from freezing:
    gamepad_obj->moveToThread(thread_gamepad);

    thread_gamepad->start();

    //timer_commandedcontrols->start(gamepad_rate);
}

void Dialog_FlightControl::update_gamepadslist()
{
    // Check the available gamepads:
    auto gamepads_list = QGamepadManager::instance()->connectedGamepads();

    ui->comboBox_gamepad_list->clear();
    for (auto i : gamepads_list) {
        QGamepad *gamepad = new QGamepad(i);
        ui->comboBox_gamepad_list->addItem("Gamepad: " + QString::number(gamepad->deviceId()));
        qDebug() << "  device id:   " << gamepad->deviceId();
//        qDebug() << "  name:        " << gamepad->name();
//        qDebug() << "  is connected?" << gamepad->isConnected();
    }
}

void Dialog_FlightControl::on_pushButton_updategamepads_clicked()
{

}

void Dialog_FlightControl::on_pushButton_connectgamepad_clicked()
{
    dialog_selected_gamepad = new QGamepad(ui->comboBox_gamepad_list->currentIndex());
    qDebug() << "  device id:   " << dialog_selected_gamepad->deviceId();
    qDebug() << "  name:        " << dialog_selected_gamepad->name();
    qDebug() << "  is connected?" << dialog_selected_gamepad->isConnected();
    emit this->setup_gamepad(dialog_selected_gamepad);

    // Activate read/send timer:
    timer_commandedcontrols->start(gamepad_rate);
}

void Dialog_FlightControl::read_commandedcontrols(QList<double> commanded_controls)
{
    ui->label_edit_buttonStart->setText(QString::number(commanded_controls.at(4)));
    ui->label_edit_buttonSelected->setText(QString::number(commanded_controls.at(5)));
    ui->label_edit_buttonA->setText(QString::number(commanded_controls.at(6)));
    ui->label_edit_buttonB->setText(QString::number(commanded_controls.at(7)));
    ui->label_edit_buttonX->setText(QString::number(commanded_controls.at(8)));
    ui->label_edit_buttonY->setText(QString::number(commanded_controls.at(9)));
    ui->label_edit_buttonL1->setText(QString::number(commanded_controls.at(10)));
    ui->label_edit_buttonL2->setText(QString::number(commanded_controls.at(11)));
    ui->label_edit_buttonR1->setText(QString::number(commanded_controls.at(12)));
    ui->label_edit_buttonR2->setText(QString::number(commanded_controls.at(13)));
    ui->label_edit_yaw->setText(QString::number(commanded_controls.at(2)));
    ui->label_edit_throttle->setText(QString::number(commanded_controls.at(3)));
    ui->label_edit_buttonL3->setText(QString::number(commanded_controls.at(14)));
    ui->label_edit_roll->setText(QString::number(commanded_controls.at(0)));
    ui->label_edit_pitch->setText(QString::number(commanded_controls.at(1)));
    ui->label_edit_buttonR3->setText(QString::number(commanded_controls.at(17)));
    ui->label_edit_buttonLeft->setText(QString::number(commanded_controls.at(15)));
    ui->label_edit_buttonRight->setText(QString::number(commanded_controls.at(16)));
    ui->label_edit_buttonDown->setText(QString::number(commanded_controls.at(18)));
    ui->label_edit_buttonUp->setText(QString::number(commanded_controls.at(19)));

    // Send received gamepad commands to MAVlink interface (if required):
    last_commanded_controls = commanded_controls;
    emit this->send_mainwindow_commandedcontrols(last_commanded_controls);
}
