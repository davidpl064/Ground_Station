#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "serialcomm.h"
#include "dialog_flightcontrol.h"
#include "dialog_graphics.h"
#include "dialog_infotaxis.h"

#include <QSerialPortInfo>
#include <QThread>

#include <QDebug>

// MAVLINK messaging protocol:
#include "mavlink_interface.h"

struct System_data{
    uint8_t system_ID;
    uint8_t type;
    uint32_t last_hearbeat;
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MAVlink_interface *mavlink_interface = new MAVlink_interface;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void start_mavlink_interface(const QString&, int);
    void close_serialport();
    void activate_command_tracking();
    void update_connected_system(QVector<uint8_t>);

public slots:
    void update_system_data(Mavlink_Messages current_system_data);
    void commtype_changed();

private slots:
    void on_pushButton_open_port_clicked();
    void on_pushButton_system_connect_clicked();
    void on_pushButton_ping_clicked();

private:
    QVector<uint8_t> connected_system;
    QVector<System_data> available_systems;

    Mavlink_Messages current_system_data;

    Lattice lattice_infotaxis;
    Model model_infotaxis;

    Ui::MainWindow *ui;
    Dialog_FlightControl *gamepad_dialog = new Dialog_FlightControl(this);
    Dialog_Graphics *graphics_dialog = new Dialog_Graphics(this);
    Dialog_Infotaxis *infotaxis_dialog = new Dialog_Infotaxis(this);

    QString flightcontrol_type;
    QStringList comm_types;

    QTimer *timer_data_visualization;
    QThread *thread_serial = new QThread;

    void activate_data_visualization();
    void open_infotaxis();
};

#endif // MAINWINDOW_H
