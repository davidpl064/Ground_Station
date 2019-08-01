#ifndef DIALOG_FLIGHTCONTROL_H
#define DIALOG_FLIGHTCONTROL_H

#include <QDialog>
#include "gamepad_flightcontrol.h"

#include <QGamepad>
#include <QGamepadKeyNavigation>
#include <QGamepadManager>

#include <QThread>
#include <QTimer>

#include <QDebug>

#include "ui_dialog_flightcontrol.h"

// Define QList Meta-Type:
Q_DECLARE_METATYPE(QList<double>)

namespace Ui
{
    class Dialog_FlightControl;
}

class Dialog_FlightControl : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_FlightControl(QWidget *parent = nullptr);
    ~Dialog_FlightControl();

protected:
    void showEvent(QShowEvent *ev);

signals:
    void show_dialog();
    void setup_gamepad(QGamepad*);
    void send_mainwindow_commandedcontrols(QList<double> last_commanded_controls);

private slots:
    void setup_gamepad_dialog();
    void on_pushButton_updategamepads_clicked();
    void update_gamepadslist();
    void read_commandedcontrols(QList<double> commanded_controls);

    void on_pushButton_connectgamepad_clicked();

private:
    int gamepad_rate; //Read/send rate for gamepad commands.

    QList<int> gamepads_list;
    QList<double> last_commanded_controls;

    Ui::Dialog_FlightControl *ui;
    Gamepad_FlightControl *gamepad_obj = new Gamepad_FlightControl;
    QGamepad *dialog_selected_gamepad;
    QThread *thread_gamepad = new QThread;
    QTimer *timer_commandedcontrols = new QTimer(this);
};

#endif // DIALOG_FLIGHTCONTROL_H
