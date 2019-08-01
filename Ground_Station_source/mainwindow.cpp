#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtQml/QQmlApplicationEngine>
#include <QSslSocket>
#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->map->engine()->rootContext()->setContextProperty("supportsSsl", QSslSocket::supportsSsl());
    ui->map->setSource(QUrl(QStringLiteral("qrc:/main.qml")));

    // Set items for communications types:
    comm_types << "Wire" << "Bluetooth" << "Wifi" << "Radio";
    ui->comboBox_comm_type->addItems(comm_types);

    // Get info about available serial ports in the specified communication type:
    const auto serial_obj = QSerialPortInfo::availablePorts();
    switch(comm_types.indexOf(ui->comboBox_comm_type->currentText())){
    case 0:
        break;
    case 1:
        for(const QSerialPortInfo &serialports_info : serial_obj){
            if(serialports_info.description().indexOf("Bluetooth") != -1){
                ui->comboBox_serialports->addItem(serialports_info.portName());
            }
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }

    // Default baudrate:
    ui->lineEdit_baudrate->setText("57600");

    // Initialize selected system data:
    connected_system = QVector<uint8_t>(2);

    // Add actions to the Ui Menu:
    // Sub-menu Data visualization:
    QAction *Open_data = new QAction(tr("&Open..."), this);
    Open_data->setShortcuts(QKeySequence::Open);
    connect(Open_data, &QAction::triggered, this, &MainWindow::activate_data_visualization);
    ui->menu_Data_visualization->addAction(Open_data);

    // Sub-menu Infotaxis:
    QAction *Open_infotaxis_dialog = new QAction(tr("&Open..."), this);
    connect(Open_infotaxis_dialog, &QAction::triggered, this, &MainWindow::open_infotaxis);
    ui->menu_Infotaxis->addAction(Open_infotaxis_dialog);

    // Sub-menu Control:
    QAction *Open_gamepad_dialog = new QAction(tr("&Open..."), this);
    connect(Open_gamepad_dialog, &QAction::triggered, gamepad_dialog, &Dialog_FlightControl::show);
    ui->menu_Control->addAction(Open_gamepad_dialog);

    // Connect all the GUI elements with the corresponding SLOTS:
    connect(ui->comboBox_comm_type, SIGNAL(activated(QString)), this, SLOT(commtype_changed()));

    // MAVLink interfaces:
    connect(this, SIGNAL(start_mavlink_interface(const QString&, int)), mavlink_interface, SLOT(setup(const QString&, int)));
    connect(mavlink_interface, SIGNAL(update_current_system_data(Mavlink_Messages)), this, SLOT(update_system_data(Mavlink_Messages)));
    connect(this, SIGNAL(close_serialport()), mavlink_interface, SLOT(close_serialcomm()));

    // Manual control links:
    connect(gamepad_dialog, SIGNAL(send_mainwindow_commandedcontrols(QList<double>)), mavlink_interface, SLOT(update_gamepad_commands(QList<double>)));
    connect(this, SIGNAL(activate_command_tracking()), graphics_dialog, SLOT(commands_tracking()));

    //connect(ui->menu_Data_visualization, SIGNAL(triggered()), graphics_dialog, SLOT(show()));

    //connect(mavlink_interface, SIGNAL(update_current_system_data(int)), this, SLOT(update_system_data(int)));

    //connect(serialcomm, SIGNAL(response(QString)), this, SLOT(showresponse(QString)));
    //connect(serialcomm, SIGNAL(finished()), thread_serial, SLOT(quit()));

    //connect(serialcomm, SIGNAL(finished()), serialcomm, SLOT(deleteLater()));
    //connect(thread_serial, SIGNAL(finished()), thread_serial, SLOT(deleteLater()));

    // Move the serial communications to a dedicated thread (assign a thread to serial communications in order to avoid the MainWindow from freezing:
    mavlink_interface->moveToThread(thread_serial);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::commtype_changed(){
    // Update info about available serial ports in the specified communication type:
    const auto serial_obj = QSerialPortInfo::availablePorts();
    switch(comm_types.indexOf(ui->comboBox_comm_type->currentText())){
    case 0:
        ui->comboBox_serialports->clear();
        for(const QSerialPortInfo &serialports_info : serial_obj){
            ui->comboBox_serialports->addItem(serialports_info.portName());
        }
        break;
    case 1:
        ui->comboBox_serialports->clear();
        for(const QSerialPortInfo &serialports_info : serial_obj){
            if(serialports_info.description().indexOf("Bluetooth") != -1){
                ui->comboBox_serialports->addItem(serialports_info.portName());
            }
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void MainWindow::on_pushButton_open_port_clicked()
{
    // Clicking connect initializes the serial comms:
    if(QString::compare(ui->pushButton_open_port->text(), "Connect", Qt::CaseInsensitive) == 0){
        // Initialize read/send serial communications:
        thread_serial->start();

        // Start read/send MAVLink interface:
        emit this->start_mavlink_interface(ui->comboBox_serialports->currentText(), ui->lineEdit_baudrate->text().toInt());

        ui->pushButton_open_port->setText("Close");
        ui->bar_comm_status->setValue(100);
    }
    // Close serial comms:
    else{
        ui->pushButton_open_port->setText("Connect");
        ui->bar_comm_status->setValue(0);
        emit close_serialport();
    }
}

void MainWindow::update_system_data(Mavlink_Messages current_system_data)
{
    if (available_systems.size() > 0) {
        uint8_t add_new_system = 1;

        if (connected_system[0] == current_system_data.system_ID) {
            // Display last received data from tracked system on MAIN GUI:
            ui->label_edit_system_ID->setText(QString::number(current_system_data.system_ID));
            ui->label_edit_component_ID->setText(QString::number(current_system_data.component_ID));
            ui->label_edit_status_system->setText(QString::number(current_system_data.heartbeat.system_status));
            ui->label_edit_charge_state->setText(QString::number(current_system_data.battery_status.charge_state));
            ui->bar_battery_remaining->setValue(current_system_data.battery_status.battery_remaining);

            ui->label_edit_latency_connection->setText(QString::number(current_system_data.ping.time_usec));

            add_new_system = 0;
        }
        else {
            for (uint8_t i = 0; i < available_systems.size(); i++)
            {
                if (available_systems[i].system_ID == current_system_data.system_ID) {
                    // Not connected to this system but already in database. Update its info:
                    available_systems[i].last_hearbeat = 0;
                    add_new_system = 0;
                }
            }
        }

        if (add_new_system == 1) {
            // New system detected, add to list of available systems:
            System_data new_system;

            new_system.system_ID = current_system_data.system_ID;
            new_system.type = current_system_data.heartbeat.type;
            new_system.last_hearbeat = 0;

            available_systems.append(new_system);

            // Add system to GUI comboBox:
            QString new_system_ID = current_system_data.system_ID;
            ui->comboBox_available_systems->addItem(new_system_ID);
        }
    }
    else {
        // New system detected, add to list of available systems:
        System_data new_system;

        new_system.system_ID = current_system_data.system_ID;
        new_system.type = current_system_data.heartbeat.type;
        new_system.last_hearbeat = 0;

        available_systems.append(new_system);

        // Add system to GUI comboBox:
        QString new_system_ID = QString::number(current_system_data.system_ID);
        ui->comboBox_available_systems->addItem(new_system_ID);
    }
}

void MainWindow::activate_data_visualization()
{
    // Setup dialog for data visualization:
    graphics_dialog->setup_dialog();

    // Start timer for data updates:
    timer_data_visualization = new QTimer;

    // Connect timer timeout with read new visualization data:
    connect(timer_data_visualization, SIGNAL(timeout()), mavlink_interface, SLOT(update_data_visualization()));
    connect(mavlink_interface, SIGNAL(send_data_visualization(QVector<QVector<QPointF>>, QVector<QVector<QPointF>>)), graphics_dialog, SLOT(read_data(QVector<QVector<QPointF>>, QVector<QVector<QPointF>>)));

    timer_data_visualization->start(100);
}

void MainWindow::open_infotaxis()
{
    infotaxis_dialog->setup(lattice_infotaxis, model_infotaxis);
}

void MainWindow::on_pushButton_system_connect_clicked()
{
    // Update connected system ID for displaying info on GUI:
    connected_system[0] = ui->comboBox_available_systems->currentText().toInt();

    emit this->update_connected_system(connected_system);
}

void MainWindow::on_pushButton_ping_clicked()
{
    // Request PING message to measure latency on telemetry communications:
    mavlink_interface->ping_request = 1;
}
