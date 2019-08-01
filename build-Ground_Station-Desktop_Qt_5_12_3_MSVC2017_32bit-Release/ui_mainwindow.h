/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QFrame *frame_map;
    QGridLayout *gridLayout_3;
    QQuickWidget *map;
    QFrame *frame_general_information;
    QGridLayout *gridLayout;
    QSplitter *splitter_available_systems;
    QFrame *frame_available_systems;
    QLabel *label_available_systems;
    QComboBox *comboBox_available_systems;
    QPushButton *pushButton_system_connect;
    QFrame *frame_control;
    QGridLayout *gridLayout_5;
    QSplitter *splitter_4;
    QGroupBox *groupBox_mapcontrols;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_comms;
    QComboBox *comboBox_serialports;
    QLabel *label_available_ports;
    QLabel *label_comm_type;
    QComboBox *comboBox_comm_type;
    QLabel *label_comm_status;
    QProgressBar *bar_comm_status;
    QPushButton *pushButton_open_port;
    QLabel *label_edit_last_packreceived;
    QLabel *label_baudrate;
    QLabel *label_last_packreceived;
    QLineEdit *lineEdit_baudrate;
    QGroupBox *groupBox_current_system;
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_general_system_info;
    QLabel *label_flight_mode;
    QLabel *lable_edit_flight_mode;
    QWidget *layoutWidget;
    QGridLayout *layout_system_main_info;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_system_ID;
    QLabel *label_edit_system_ID;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_component_ID;
    QLabel *label_edit_component_ID;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_status_system;
    QLabel *label_edit_status_system;
    QLabel *label_edit_latency_connection;
    QLabel *label_latency_connection;
    QPushButton *pushButton_ping;
    QGroupBox *groupBox_baterry_info;
    QWidget *layoutWidget_6;
    QHBoxLayout *Layout_battery_remaining;
    QLabel *label_battery_remaining;
    QProgressBar *bar_battery_remaining;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_8;
    QHBoxLayout *Layout_charge_state;
    QLabel *label_charge_state;
    QLabel *label_edit_charge_state;
    QHBoxLayout *Layout_total_voltage;
    QLabel *label_total_voltage;
    QLabel *label_edit_total_voltage;
    QLabel *label_total_voltage_units;
    QHBoxLayout *Layout_voltage_cell;
    QLabel *label_voltage_cell;
    QLabel *label_edit_voltage_cell;
    QLabel *label_voltage_cell_units;
    QMenuBar *menuBar;
    QMenu *menu_Data_visualization;
    QMenu *menu_Infotaxis;
    QMenu *menu_Control;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1237, 751);
        MainWindow->setBaseSize(QSize(0, 70));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 5);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setSizeIncrement(QSize(0, 0));
        splitter_2->setFrameShape(QFrame::NoFrame);
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(2);
        splitter->setOrientation(Qt::Horizontal);
        frame_map = new QFrame(splitter);
        frame_map->setObjectName(QString::fromUtf8("frame_map"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(frame_map->sizePolicy().hasHeightForWidth());
        frame_map->setSizePolicy(sizePolicy1);
        frame_map->setBaseSize(QSize(0, 0));
        frame_map->setFrameShape(QFrame::Box);
        frame_map->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(frame_map);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        map = new QQuickWidget(frame_map);
        map->setObjectName(QString::fromUtf8("map"));
        map->setBaseSize(QSize(0, 0));
        map->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_3->addWidget(map, 0, 0, 1, 1);

        splitter->addWidget(frame_map);
        frame_general_information = new QFrame(splitter);
        frame_general_information->setObjectName(QString::fromUtf8("frame_general_information"));
        frame_general_information->setFrameShape(QFrame::Box);
        frame_general_information->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame_general_information);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_available_systems = new QSplitter(frame_general_information);
        splitter_available_systems->setObjectName(QString::fromUtf8("splitter_available_systems"));
        splitter_available_systems->setOrientation(Qt::Vertical);
        frame_available_systems = new QFrame(splitter_available_systems);
        frame_available_systems->setObjectName(QString::fromUtf8("frame_available_systems"));
        sizePolicy.setHeightForWidth(frame_available_systems->sizePolicy().hasHeightForWidth());
        frame_available_systems->setSizePolicy(sizePolicy);
        frame_available_systems->setMinimumSize(QSize(0, 0));
        frame_available_systems->setFrameShape(QFrame::StyledPanel);
        frame_available_systems->setFrameShadow(QFrame::Raised);
        label_available_systems = new QLabel(frame_available_systems);
        label_available_systems->setObjectName(QString::fromUtf8("label_available_systems"));
        label_available_systems->setGeometry(QRect(10, 0, 111, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_available_systems->setFont(font);
        comboBox_available_systems = new QComboBox(frame_available_systems);
        comboBox_available_systems->setObjectName(QString::fromUtf8("comboBox_available_systems"));
        comboBox_available_systems->setGeometry(QRect(60, 40, 101, 31));
        QFont font1;
        font1.setPointSize(10);
        comboBox_available_systems->setFont(font1);
        pushButton_system_connect = new QPushButton(frame_available_systems);
        pushButton_system_connect->setObjectName(QString::fromUtf8("pushButton_system_connect"));
        pushButton_system_connect->setGeometry(QRect(20, 110, 81, 31));
        splitter_available_systems->addWidget(frame_available_systems);

        gridLayout->addWidget(splitter_available_systems, 0, 0, 1, 1);

        splitter->addWidget(frame_general_information);
        splitter_2->addWidget(splitter);
        frame_control = new QFrame(splitter_2);
        frame_control->setObjectName(QString::fromUtf8("frame_control"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_control->sizePolicy().hasHeightForWidth());
        frame_control->setSizePolicy(sizePolicy2);
        frame_control->setFrameShape(QFrame::Box);
        frame_control->setFrameShadow(QFrame::Sunken);
        gridLayout_5 = new QGridLayout(frame_control);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter_4 = new QSplitter(frame_control);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        sizePolicy.setHeightForWidth(splitter_4->sizePolicy().hasHeightForWidth());
        splitter_4->setSizePolicy(sizePolicy);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setOpaqueResize(true);
        groupBox_mapcontrols = new QGroupBox(splitter_4);
        groupBox_mapcontrols->setObjectName(QString::fromUtf8("groupBox_mapcontrols"));
        sizePolicy.setHeightForWidth(groupBox_mapcontrols->sizePolicy().hasHeightForWidth());
        groupBox_mapcontrols->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_mapcontrols->setFont(font2);
        gridLayout_6 = new QGridLayout(groupBox_mapcontrols);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        splitter_4->addWidget(groupBox_mapcontrols);
        groupBox_comms = new QGroupBox(splitter_4);
        groupBox_comms->setObjectName(QString::fromUtf8("groupBox_comms"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_comms->sizePolicy().hasHeightForWidth());
        groupBox_comms->setSizePolicy(sizePolicy3);
        groupBox_comms->setMinimumSize(QSize(0, 0));
        groupBox_comms->setFont(font2);
        comboBox_serialports = new QComboBox(groupBox_comms);
        comboBox_serialports->setObjectName(QString::fromUtf8("comboBox_serialports"));
        comboBox_serialports->setGeometry(QRect(200, 60, 101, 41));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        comboBox_serialports->setFont(font3);
        label_available_ports = new QLabel(groupBox_comms);
        label_available_ports->setObjectName(QString::fromUtf8("label_available_ports"));
        label_available_ports->setGeometry(QRect(180, 30, 141, 21));
        label_available_ports->setFont(font1);
        label_available_ports->setAlignment(Qt::AlignCenter);
        label_comm_type = new QLabel(groupBox_comms);
        label_comm_type->setObjectName(QString::fromUtf8("label_comm_type"));
        label_comm_type->setGeometry(QRect(20, 30, 141, 21));
        label_comm_type->setFont(font1);
        label_comm_type->setAlignment(Qt::AlignCenter);
        comboBox_comm_type = new QComboBox(groupBox_comms);
        comboBox_comm_type->setObjectName(QString::fromUtf8("comboBox_comm_type"));
        comboBox_comm_type->setGeometry(QRect(40, 60, 101, 41));
        comboBox_comm_type->setFont(font3);
        label_comm_status = new QLabel(groupBox_comms);
        label_comm_status->setObjectName(QString::fromUtf8("label_comm_status"));
        label_comm_status->setGeometry(QRect(280, 140, 121, 21));
        label_comm_status->setFont(font1);
        label_comm_status->setAlignment(Qt::AlignCenter);
        bar_comm_status = new QProgressBar(groupBox_comms);
        bar_comm_status->setObjectName(QString::fromUtf8("bar_comm_status"));
        bar_comm_status->setGeometry(QRect(280, 170, 121, 31));
        bar_comm_status->setValue(0);
        bar_comm_status->setTextVisible(false);
        pushButton_open_port = new QPushButton(groupBox_comms);
        pushButton_open_port->setObjectName(QString::fromUtf8("pushButton_open_port"));
        pushButton_open_port->setGeometry(QRect(90, 140, 111, 71));
        label_edit_last_packreceived = new QLabel(groupBox_comms);
        label_edit_last_packreceived->setObjectName(QString::fromUtf8("label_edit_last_packreceived"));
        label_edit_last_packreceived->setGeometry(QRect(250, 250, 181, 51));
        label_edit_last_packreceived->setFont(font3);
        label_edit_last_packreceived->setFrameShape(QFrame::Panel);
        label_edit_last_packreceived->setFrameShadow(QFrame::Sunken);
        label_edit_last_packreceived->setAlignment(Qt::AlignCenter);
        label_baudrate = new QLabel(groupBox_comms);
        label_baudrate->setObjectName(QString::fromUtf8("label_baudrate"));
        label_baudrate->setGeometry(QRect(340, 30, 101, 21));
        label_baudrate->setFont(font1);
        label_baudrate->setAlignment(Qt::AlignCenter);
        label_last_packreceived = new QLabel(groupBox_comms);
        label_last_packreceived->setObjectName(QString::fromUtf8("label_last_packreceived"));
        label_last_packreceived->setGeometry(QRect(50, 250, 151, 51));
        label_last_packreceived->setFont(font1);
        label_last_packreceived->setAlignment(Qt::AlignCenter);
        lineEdit_baudrate = new QLineEdit(groupBox_comms);
        lineEdit_baudrate->setObjectName(QString::fromUtf8("lineEdit_baudrate"));
        lineEdit_baudrate->setGeometry(QRect(340, 60, 113, 41));
        lineEdit_baudrate->setFont(font3);
        lineEdit_baudrate->setFrame(true);
        lineEdit_baudrate->setAlignment(Qt::AlignCenter);
        splitter_4->addWidget(groupBox_comms);
        groupBox_current_system = new QGroupBox(splitter_4);
        groupBox_current_system->setObjectName(QString::fromUtf8("groupBox_current_system"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_current_system->sizePolicy().hasHeightForWidth());
        groupBox_current_system->setSizePolicy(sizePolicy4);
        groupBox_current_system->setMinimumSize(QSize(0, 0));
        groupBox_current_system->setFont(font2);
        groupBox_current_system->setFlat(false);
        gridLayout_7 = new QGridLayout(groupBox_current_system);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(groupBox_current_system);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 829, 304));
        scrollAreaWidgetContents->setMinimumSize(QSize(578, 246));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_general_system_info = new QGroupBox(scrollAreaWidgetContents);
        groupBox_general_system_info->setObjectName(QString::fromUtf8("groupBox_general_system_info"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_general_system_info->sizePolicy().hasHeightForWidth());
        groupBox_general_system_info->setSizePolicy(sizePolicy5);
        groupBox_general_system_info->setFont(font1);
        label_flight_mode = new QLabel(groupBox_general_system_info);
        label_flight_mode->setObjectName(QString::fromUtf8("label_flight_mode"));
        label_flight_mode->setGeometry(QRect(20, 140, 119, 16));
        QFont font4;
        font4.setPointSize(9);
        label_flight_mode->setFont(font4);
        label_flight_mode->setAlignment(Qt::AlignCenter);
        lable_edit_flight_mode = new QLabel(groupBox_general_system_info);
        lable_edit_flight_mode->setObjectName(QString::fromUtf8("lable_edit_flight_mode"));
        lable_edit_flight_mode->setGeometry(QRect(20, 170, 120, 50));
        lable_edit_flight_mode->setMinimumSize(QSize(70, 50));
        lable_edit_flight_mode->setMaximumSize(QSize(120, 50));
        lable_edit_flight_mode->setFont(font1);
        lable_edit_flight_mode->setFrameShape(QFrame::Panel);
        lable_edit_flight_mode->setFrameShadow(QFrame::Sunken);
        lable_edit_flight_mode->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox_general_system_info);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 31, 221, 82));
        layout_system_main_info = new QGridLayout(layoutWidget);
        layout_system_main_info->setSpacing(6);
        layout_system_main_info->setContentsMargins(11, 11, 11, 11);
        layout_system_main_info->setObjectName(QString::fromUtf8("layout_system_main_info"));
        layout_system_main_info->setVerticalSpacing(10);
        layout_system_main_info->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_system_ID = new QLabel(layoutWidget);
        label_system_ID->setObjectName(QString::fromUtf8("label_system_ID"));
        label_system_ID->setFont(font4);

        horizontalLayout_5->addWidget(label_system_ID);

        label_edit_system_ID = new QLabel(layoutWidget);
        label_edit_system_ID->setObjectName(QString::fromUtf8("label_edit_system_ID"));
        label_edit_system_ID->setFrameShape(QFrame::Panel);
        label_edit_system_ID->setFrameShadow(QFrame::Sunken);
        label_edit_system_ID->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_edit_system_ID);


        layout_system_main_info->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_component_ID = new QLabel(layoutWidget);
        label_component_ID->setObjectName(QString::fromUtf8("label_component_ID"));
        label_component_ID->setFont(font4);

        horizontalLayout_7->addWidget(label_component_ID);

        label_edit_component_ID = new QLabel(layoutWidget);
        label_edit_component_ID->setObjectName(QString::fromUtf8("label_edit_component_ID"));
        label_edit_component_ID->setFrameShape(QFrame::Panel);
        label_edit_component_ID->setFrameShadow(QFrame::Sunken);
        label_edit_component_ID->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_edit_component_ID);


        layout_system_main_info->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_status_system = new QLabel(layoutWidget);
        label_status_system->setObjectName(QString::fromUtf8("label_status_system"));
        label_status_system->setFont(font4);

        horizontalLayout_9->addWidget(label_status_system);

        label_edit_status_system = new QLabel(layoutWidget);
        label_edit_status_system->setObjectName(QString::fromUtf8("label_edit_status_system"));
        label_edit_status_system->setFrameShape(QFrame::Panel);
        label_edit_status_system->setFrameShadow(QFrame::Sunken);
        label_edit_status_system->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_edit_status_system);


        layout_system_main_info->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        label_edit_latency_connection = new QLabel(groupBox_general_system_info);
        label_edit_latency_connection->setObjectName(QString::fromUtf8("label_edit_latency_connection"));
        label_edit_latency_connection->setGeometry(QRect(210, 170, 120, 50));
        label_edit_latency_connection->setMinimumSize(QSize(70, 50));
        label_edit_latency_connection->setMaximumSize(QSize(120, 50));
        label_edit_latency_connection->setFont(font1);
        label_edit_latency_connection->setFrameShape(QFrame::Panel);
        label_edit_latency_connection->setFrameShadow(QFrame::Sunken);
        label_edit_latency_connection->setAlignment(Qt::AlignCenter);
        label_latency_connection = new QLabel(groupBox_general_system_info);
        label_latency_connection->setObjectName(QString::fromUtf8("label_latency_connection"));
        label_latency_connection->setGeometry(QRect(210, 140, 131, 16));
        label_latency_connection->setFont(font4);
        label_latency_connection->setAlignment(Qt::AlignCenter);
        pushButton_ping = new QPushButton(groupBox_general_system_info);
        pushButton_ping->setObjectName(QString::fromUtf8("pushButton_ping"));
        pushButton_ping->setGeometry(QRect(290, 50, 61, 51));

        horizontalLayout_3->addWidget(groupBox_general_system_info);

        groupBox_baterry_info = new QGroupBox(scrollAreaWidgetContents);
        groupBox_baterry_info->setObjectName(QString::fromUtf8("groupBox_baterry_info"));
        sizePolicy5.setHeightForWidth(groupBox_baterry_info->sizePolicy().hasHeightForWidth());
        groupBox_baterry_info->setSizePolicy(sizePolicy5);
        groupBox_baterry_info->setFont(font1);
        layoutWidget_6 = new QWidget(groupBox_baterry_info);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 20, 215, 51));
        Layout_battery_remaining = new QHBoxLayout(layoutWidget_6);
        Layout_battery_remaining->setSpacing(6);
        Layout_battery_remaining->setContentsMargins(11, 11, 11, 11);
        Layout_battery_remaining->setObjectName(QString::fromUtf8("Layout_battery_remaining"));
        Layout_battery_remaining->setContentsMargins(0, 0, 0, 0);
        label_battery_remaining = new QLabel(layoutWidget_6);
        label_battery_remaining->setObjectName(QString::fromUtf8("label_battery_remaining"));
        label_battery_remaining->setFont(font4);

        Layout_battery_remaining->addWidget(label_battery_remaining);

        bar_battery_remaining = new QProgressBar(layoutWidget_6);
        bar_battery_remaining->setObjectName(QString::fromUtf8("bar_battery_remaining"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(bar_battery_remaining->sizePolicy().hasHeightForWidth());
        bar_battery_remaining->setSizePolicy(sizePolicy6);
        bar_battery_remaining->setFont(font4);
        bar_battery_remaining->setValue(24);

        Layout_battery_remaining->addWidget(bar_battery_remaining);

        layoutWidget1 = new QWidget(groupBox_baterry_info);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 215, 131));
        gridLayout_8 = new QGridLayout(layoutWidget1);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(6);
        gridLayout_8->setVerticalSpacing(15);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        Layout_charge_state = new QHBoxLayout();
        Layout_charge_state->setSpacing(6);
        Layout_charge_state->setObjectName(QString::fromUtf8("Layout_charge_state"));
        label_charge_state = new QLabel(layoutWidget1);
        label_charge_state->setObjectName(QString::fromUtf8("label_charge_state"));
        label_charge_state->setMinimumSize(QSize(96, 31));
        label_charge_state->setFont(font4);

        Layout_charge_state->addWidget(label_charge_state);

        label_edit_charge_state = new QLabel(layoutWidget1);
        label_edit_charge_state->setObjectName(QString::fromUtf8("label_edit_charge_state"));
        label_edit_charge_state->setFrameShape(QFrame::Panel);
        label_edit_charge_state->setFrameShadow(QFrame::Sunken);
        label_edit_charge_state->setAlignment(Qt::AlignCenter);

        Layout_charge_state->addWidget(label_edit_charge_state);


        gridLayout_8->addLayout(Layout_charge_state, 0, 0, 1, 1);

        Layout_total_voltage = new QHBoxLayout();
        Layout_total_voltage->setSpacing(6);
        Layout_total_voltage->setObjectName(QString::fromUtf8("Layout_total_voltage"));
        label_total_voltage = new QLabel(layoutWidget1);
        label_total_voltage->setObjectName(QString::fromUtf8("label_total_voltage"));
        label_total_voltage->setMinimumSize(QSize(96, 31));
        label_total_voltage->setFont(font4);

        Layout_total_voltage->addWidget(label_total_voltage);

        label_edit_total_voltage = new QLabel(layoutWidget1);
        label_edit_total_voltage->setObjectName(QString::fromUtf8("label_edit_total_voltage"));
        sizePolicy.setHeightForWidth(label_edit_total_voltage->sizePolicy().hasHeightForWidth());
        label_edit_total_voltage->setSizePolicy(sizePolicy);
        label_edit_total_voltage->setMinimumSize(QSize(95, 31));
        label_edit_total_voltage->setBaseSize(QSize(0, 0));
        label_edit_total_voltage->setFrameShape(QFrame::Panel);
        label_edit_total_voltage->setFrameShadow(QFrame::Sunken);
        label_edit_total_voltage->setAlignment(Qt::AlignCenter);

        Layout_total_voltage->addWidget(label_edit_total_voltage);

        label_total_voltage_units = new QLabel(layoutWidget1);
        label_total_voltage_units->setObjectName(QString::fromUtf8("label_total_voltage_units"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_total_voltage_units->sizePolicy().hasHeightForWidth());
        label_total_voltage_units->setSizePolicy(sizePolicy7);
        label_total_voltage_units->setFont(font4);

        Layout_total_voltage->addWidget(label_total_voltage_units);


        gridLayout_8->addLayout(Layout_total_voltage, 1, 0, 1, 1);

        Layout_voltage_cell = new QHBoxLayout();
        Layout_voltage_cell->setSpacing(6);
        Layout_voltage_cell->setObjectName(QString::fromUtf8("Layout_voltage_cell"));
        label_voltage_cell = new QLabel(layoutWidget1);
        label_voltage_cell->setObjectName(QString::fromUtf8("label_voltage_cell"));
        label_voltage_cell->setMinimumSize(QSize(96, 31));
        label_voltage_cell->setFont(font4);

        Layout_voltage_cell->addWidget(label_voltage_cell);

        label_edit_voltage_cell = new QLabel(layoutWidget1);
        label_edit_voltage_cell->setObjectName(QString::fromUtf8("label_edit_voltage_cell"));
        label_edit_voltage_cell->setMinimumSize(QSize(95, 31));
        label_edit_voltage_cell->setFrameShape(QFrame::Panel);
        label_edit_voltage_cell->setFrameShadow(QFrame::Sunken);
        label_edit_voltage_cell->setAlignment(Qt::AlignCenter);

        Layout_voltage_cell->addWidget(label_edit_voltage_cell);

        label_voltage_cell_units = new QLabel(layoutWidget1);
        label_voltage_cell_units->setObjectName(QString::fromUtf8("label_voltage_cell_units"));
        sizePolicy7.setHeightForWidth(label_voltage_cell_units->sizePolicy().hasHeightForWidth());
        label_voltage_cell_units->setSizePolicy(sizePolicy7);
        label_voltage_cell_units->setFont(font4);

        Layout_voltage_cell->addWidget(label_voltage_cell_units);


        gridLayout_8->addLayout(Layout_voltage_cell, 2, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_baterry_info);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 1, 0, 1, 1);

        splitter_4->addWidget(groupBox_current_system);

        gridLayout_5->addWidget(splitter_4, 0, 0, 1, 1);

        splitter_2->addWidget(frame_control);

        gridLayout_2->addWidget(splitter_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1237, 21));
        menu_Data_visualization = new QMenu(menuBar);
        menu_Data_visualization->setObjectName(QString::fromUtf8("menu_Data_visualization"));
        menu_Data_visualization->setTearOffEnabled(false);
        menu_Infotaxis = new QMenu(menuBar);
        menu_Infotaxis->setObjectName(QString::fromUtf8("menu_Infotaxis"));
        menu_Control = new QMenu(menuBar);
        menu_Control->setObjectName(QString::fromUtf8("menu_Control"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Control->menuAction());
        menuBar->addAction(menu_Data_visualization->menuAction());
        menuBar->addAction(menu_Infotaxis->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_available_systems->setText(QApplication::translate("MainWindow", "Available Sytems", nullptr));
        pushButton_system_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_mapcontrols->setTitle(QApplication::translate("MainWindow", "Map Controls", nullptr));
        groupBox_comms->setTitle(QApplication::translate("MainWindow", "Communications", nullptr));
        label_available_ports->setText(QApplication::translate("MainWindow", "Available Serial Ports", nullptr));
        label_comm_type->setText(QApplication::translate("MainWindow", "Communication Type", nullptr));
        label_comm_status->setText(QApplication::translate("MainWindow", "Connection Status", nullptr));
        pushButton_open_port->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_edit_last_packreceived->setText(QString());
        label_baudrate->setText(QApplication::translate("MainWindow", "Baudrate", nullptr));
        label_last_packreceived->setText(QApplication::translate("MainWindow", "Last Package Received", nullptr));
        groupBox_current_system->setTitle(QApplication::translate("MainWindow", "Actual System", nullptr));
        groupBox_general_system_info->setTitle(QApplication::translate("MainWindow", "General information", nullptr));
        label_flight_mode->setText(QApplication::translate("MainWindow", "Actual Flight Mode", nullptr));
        lable_edit_flight_mode->setText(QString());
        label_system_ID->setText(QApplication::translate("MainWindow", "System ID", nullptr));
        label_edit_system_ID->setText(QString());
        label_component_ID->setText(QApplication::translate("MainWindow", "Component ID", nullptr));
        label_edit_component_ID->setText(QString());
        label_status_system->setText(QApplication::translate("MainWindow", "Status", nullptr));
        label_edit_status_system->setText(QString());
        label_edit_latency_connection->setText(QString());
        label_latency_connection->setText(QApplication::translate("MainWindow", "Connection Latency", nullptr));
        pushButton_ping->setText(QApplication::translate("MainWindow", "PING", nullptr));
        groupBox_baterry_info->setTitle(QApplication::translate("MainWindow", "Battery", nullptr));
        label_battery_remaining->setText(QApplication::translate("MainWindow", "Battery Status", nullptr));
        label_charge_state->setText(QApplication::translate("MainWindow", "Charge State", nullptr));
        label_edit_charge_state->setText(QString());
        label_total_voltage->setText(QApplication::translate("MainWindow", "Total Voltage", nullptr));
        label_edit_total_voltage->setText(QString());
        label_total_voltage_units->setText(QApplication::translate("MainWindow", "V", nullptr));
        label_voltage_cell->setText(QApplication::translate("MainWindow", "Voltage per cell", nullptr));
        label_edit_voltage_cell->setText(QString());
        label_voltage_cell_units->setText(QApplication::translate("MainWindow", "V", nullptr));
        menu_Data_visualization->setTitle(QApplication::translate("MainWindow", "Data Visualization", nullptr));
        menu_Infotaxis->setTitle(QApplication::translate("MainWindow", "Infotaxis", nullptr));
        menu_Control->setTitle(QApplication::translate("MainWindow", "Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
