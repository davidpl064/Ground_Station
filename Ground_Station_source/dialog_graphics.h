#ifndef DIALOG_GRAPHICS_H
#define DIALOG_GRAPHICS_H

#include <QDialog>
#include <QDebug>

// Time related libraries:
#include <QTimer>
#include <QElapsedTimer>

// Include .ui file of the dialog:
#include "ui_dialog_graphics.h"


// ------------------------------------------------------------------------------
//   Data Structures
// ------------------------------------------------------------------------------

struct State_variables {
    float position[3];
    float velocity[3];
    float orientation_Euler[3];
    float angular_velocity[3];
};

struct Commands {
    float throttle;
    float roll;
    float pitch;
    float yaw;
};

// Define custom structs Meta-Type:
Q_DECLARE_METATYPE(State_variables)
Q_DECLARE_METATYPE(Commands)

namespace Ui
{
    class Dialog_Graphics;
}

class Dialog_Graphics : public QDialog
{
    Q_OBJECT
public:    
    explicit Dialog_Graphics(QWidget *parent = nullptr);
    ~Dialog_Graphics();

public slots:
    void setup_dialog();
    void read_data(QVector<QVector<QPointF>>, QVector<QVector<QPointF>>);
    void update_charts();
    void commands_tracking();

private slots:
    void on_pushButton_start_graphics_clicked();

private:
    uint16_t buffer_size;

    uint8_t manual_commands = 0;

    uint32_t bias_boot_time;

    uint32_t current_elapsed_seconds;
    uint32_t min_displayed_seconds;

    QVector<QVector<QPointF>> buffer_commands;
    QVector<QVector<QPointF>> buffer_state_variables;

    QPointF state_variables_data;
    QPointF commands_data;

    QLineSeries *series_commands_1 = new QLineSeries();
    QLineSeries *series_state_variables_1 = new QLineSeries();

    QLineSeries *series_commands_2 = new QLineSeries();
    QLineSeries *series_state_variables_2 = new QLineSeries();

    QLineSeries *series_commands_3 = new QLineSeries();
    QLineSeries *series_state_variables_3 = new QLineSeries();

    QLineSeries *series_commands_4 = new QLineSeries();
    QLineSeries *series_state_variables_4 = new QLineSeries();

    QLineSeries *series_commands_5 = new QLineSeries();
    QLineSeries *series_state_variables_5 = new QLineSeries();

    QLineSeries *series_commands_6 = new QLineSeries();
    QLineSeries *series_state_variables_6 = new QLineSeries();

    QChart *chart_1 = new QChart();
    QChart *chart_2 = new QChart();
    QChart *chart_3 = new QChart();
    QChart *chart_4 = new QChart();
    QChart *chart_5 = new QChart();
    QChart *chart_6 = new QChart();

    QValueAxis *axis_X_1;
    QValueAxis *axis_Y_1;
    QValueAxis *axis_X_2;
    QValueAxis *axis_Y_2;
    QValueAxis *axis_X_3;
    QValueAxis *axis_Y_3;
    QValueAxis *axis_X_4;
    QValueAxis *axis_Y_4;
    QValueAxis *axis_X_5;
    QValueAxis *axis_Y_5;
    QValueAxis *axis_X_6;
    QValueAxis *axis_Y_6;

    QTimer *timer_update_charts;

    QElapsedTimer elapsed_timer;

    Ui::Dialog_Graphics *ui;

    void setup_charts(QChart*, QChartView*, QLineSeries*, int, QValueAxis*, QValueAxis*);
};

#endif // DIALOG_GRAPHICS_H
