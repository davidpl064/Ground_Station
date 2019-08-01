#include "dialog_graphics.h"

Dialog_Graphics::Dialog_Graphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Graphics)
{
    ui->setupUi(this);

    // Register custom structs in order to allow signal/slot connections:
    qRegisterMetaType<State_variables>();
    qRegisterMetaType<Commands>();
}

Dialog_Graphics::~Dialog_Graphics()
{
    delete ui;
}

void Dialog_Graphics::setup_dialog()
{           
    // Setup the charts:
    axis_X_1 = new QValueAxis();
    axis_Y_1 = new QValueAxis();
    axis_X_2 = new QValueAxis();
    axis_Y_2 = new QValueAxis();
    axis_X_3 = new QValueAxis();
    axis_Y_3 = new QValueAxis();
    axis_X_4 = new QValueAxis();
    axis_Y_4 = new QValueAxis();
    axis_X_5 = new QValueAxis();
    axis_Y_5 = new QValueAxis();
    axis_X_6 = new QValueAxis();
    axis_Y_6 = new QValueAxis();

    setup_charts(chart_1, ui->chartview_1, series_state_variables_1, 1, axis_X_1, axis_Y_1);
    setup_charts(chart_2, ui->chartview_2, series_state_variables_2, 2, axis_X_2, axis_Y_2);
    setup_charts(chart_3, ui->chartview_3, series_state_variables_3, 3, axis_X_3, axis_Y_3);
    setup_charts(chart_4, ui->chartview_4, series_state_variables_4, 4, axis_X_4, axis_Y_4);
    setup_charts(chart_5, ui->chartview_5, series_state_variables_5, 5, axis_X_5, axis_Y_5);
    setup_charts(chart_6, ui->chartview_6, series_state_variables_6, 6, axis_X_6, axis_Y_6);

    // Initialize variables:
    buffer_size = 50;

    buffer_commands = QVector<QVector<QPointF>>(6, QVector<QPointF>(buffer_size));
    buffer_state_variables = QVector<QVector<QPointF>>(6, QVector<QPointF>(buffer_size));

    // Initiate timers for read/update calls:
    timer_update_charts = new QTimer;

    connect(timer_update_charts, SIGNAL(timeout()), this, SLOT(update_charts()));

    // Show the dialog:
    this->show();

    series_commands_1->attachAxis(axis_X_1);
    series_commands_1->attachAxis(axis_Y_1);

    series_commands_2->attachAxis(axis_X_2);
    series_commands_2->attachAxis(axis_Y_2);

    series_commands_3->attachAxis(axis_X_3);
    series_commands_3->attachAxis(axis_Y_3);

    series_commands_4->attachAxis(axis_X_4);
    series_commands_4->attachAxis(axis_Y_4);

    series_commands_5->attachAxis(axis_X_5);
    series_commands_5->attachAxis(axis_Y_5);

    series_commands_6->attachAxis(axis_X_6);
    series_commands_6->attachAxis(axis_Y_6);

    axis_Y_1->setRange(-180, 180);
    axis_Y_2->setRange(-90, 90);
    axis_Y_3->setRange(-180, 180);
}

void Dialog_Graphics::setup_charts(QChart *chart, QChartView *chartview, QLineSeries *line_series, int chart_ID, QValueAxis *axis_X, QValueAxis *axis_Y)
{
    // Add line series to the chart:
    chart->addSeries(line_series);

    // Chart default settings:
    chart->legend()->hide();

    chart->addAxis(axis_X, Qt::AlignBottom);
    chart->addAxis(axis_Y, Qt::AlignLeft);
    line_series->attachAxis(axis_X);
    line_series->attachAxis(axis_Y);

    switch (chart_ID)
    {
    case 1: {
        chart->setTitle("Roll angle");
        break;
    }
    case 2: {
        chart->setTitle("Pitch angle");
        break;
    }
    case 3: {
        chart->setTitle("Yaw angle");
        break;
    }
    case 4: {
        chart->setTitle("Longitude");
        break;
    }
    case 5: {
        chart->setTitle("Latitude");
        break;
    }
    case 6: {
        chart->setTitle("Altitude");
        break;
    }
    }

    chartview->setChart(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
}

void Dialog_Graphics::read_data(QVector<QVector<QPointF>> buffer_state_variables_test, QVector<QVector<QPointF>> buffer_commands_test)
{
    buffer_state_variables = buffer_state_variables_test;
    buffer_commands = buffer_commands_test;
}

void Dialog_Graphics::update_charts()
{
    // Get actual elapsed seconds:
    current_elapsed_seconds = elapsed_timer.elapsed() + bias_boot_time + 1000;
    min_displayed_seconds = current_elapsed_seconds - (uint32_t)5000;

    axis_X_1->setRange(min_displayed_seconds, current_elapsed_seconds);
    axis_X_2->setRange(min_displayed_seconds, current_elapsed_seconds);
    axis_X_3->setRange(min_displayed_seconds, current_elapsed_seconds);
    axis_X_4->setRange(min_displayed_seconds, current_elapsed_seconds);
    axis_X_5->setRange(min_displayed_seconds, current_elapsed_seconds);
    axis_X_6->setRange(min_displayed_seconds, current_elapsed_seconds);

    series_state_variables_1->replace(buffer_state_variables[0]);
    series_state_variables_2->replace(buffer_state_variables[1]);
    series_state_variables_3->replace(buffer_state_variables[2]);
    series_state_variables_4->replace(buffer_state_variables[3]);
    series_state_variables_5->replace(buffer_state_variables[4]);
    series_state_variables_6->replace(buffer_state_variables[5]);

    if(manual_commands == 1)
    {
        series_commands_1->replace(buffer_commands[0]);
        series_commands_2->replace(buffer_commands[1]);
        series_commands_3->replace(buffer_commands[2]);
        series_commands_4->replace(buffer_commands[3]);
        series_commands_5->replace(buffer_commands[4]);
        series_commands_6->replace(buffer_commands[5]);
    }
}

void Dialog_Graphics::commands_tracking()
{
    // Attach the command series to the charts:
    chart_1->addSeries(series_commands_1);
    chart_2->addSeries(series_commands_2);
    chart_3->addSeries(series_commands_3);
    chart_4->addSeries(series_commands_4);
    chart_5->addSeries(series_commands_5);
    chart_6->addSeries(series_commands_6);

    manual_commands = 1;
}

void Dialog_Graphics::on_pushButton_start_graphics_clicked()
{
    // Start timers for updating chart data:
    timer_update_charts->start(100);

    // Initiate clock for timelines:
    elapsed_timer.start();

    bias_boot_time = buffer_state_variables[0].last().x();
}
