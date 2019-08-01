/********************************************************************************
** Form generated from reading UI file 'dialog_flightcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FLIGHTCONTROL_H
#define UI_DIALOG_FLIGHTCONTROL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_FlightControl
{
public:
    QGroupBox *groupBox_gamepad_control;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_gamepad;
    QComboBox *comboBox_gamepad_list;
    QPushButton *pushButton_updategamepads;
    QLabel *label_gamepad_list;
    QPushButton *pushButton_connectgamepad;
    QGroupBox *groupBox_commanded_controls;
    QLabel *label_roll;
    QLabel *label_pitch;
    QLabel *label_yaw;
    QLabel *label_edit_roll;
    QLabel *label_edit_pitch;
    QLabel *label_edit_yaw;
    QLabel *label_buttonA;
    QLabel *label_buttonB;
    QLabel *label_buttonX;
    QLabel *label_buttonY;
    QLabel *label_edit_buttonA;
    QLabel *label_edit_buttonB;
    QLabel *label_edit_buttonX;
    QLabel *label_edit_buttonY;
    QLabel *label_edit_buttonR2;
    QLabel *label_buttonL1;
    QLabel *label_buttonL2;
    QLabel *label_edit_buttonL1;
    QLabel *label_edit_buttonR1;
    QLabel *label_buttonR1;
    QLabel *label_edit_buttonL2;
    QLabel *label_buttonR2;
    QLabel *label_buttonSelected;
    QLabel *label_edit_buttonSelected;
    QLabel *label_buttonStart;
    QLabel *label_edit_buttonStart;
    QLabel *label_edit_throttle;
    QLabel *label_throttle;
    QLabel *label_edit_buttonLeft;
    QLabel *label_buttonLeft;
    QLabel *label_edit_buttonRight;
    QLabel *label_buttonRight;
    QLabel *label_edit_buttonL3;
    QLabel *label_buttonL3;
    QLabel *label_edit_buttonR3;
    QLabel *label_buttonR3;
    QLabel *label_edit_buttonUp;
    QLabel *label_buttonUp;
    QLabel *label_buttonDown;
    QLabel *label_edit_buttonDown;
    QGroupBox *groupBox_additional_controls;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupbox_control_settings;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_control_mode;
    QRadioButton *radioButton_autonomous;
    QRadioButton *radioButton_manual;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_system_type;
    QComboBox *comboBox_system_type;

    void setupUi(QDialog *Dialog_FlightControl)
    {
        if (Dialog_FlightControl->objectName().isEmpty())
            Dialog_FlightControl->setObjectName(QString::fromUtf8("Dialog_FlightControl"));
        Dialog_FlightControl->resize(1093, 768);
        QFont font;
        font.setPointSize(12);
        Dialog_FlightControl->setFont(font);
        Dialog_FlightControl->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        groupBox_gamepad_control = new QGroupBox(Dialog_FlightControl);
        groupBox_gamepad_control->setObjectName(QString::fromUtf8("groupBox_gamepad_control"));
        groupBox_gamepad_control->setGeometry(QRect(10, 140, 411, 621));
        gridLayout = new QGridLayout(groupBox_gamepad_control);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_gamepad = new QGroupBox(groupBox_gamepad_control);
        groupBox_gamepad->setObjectName(QString::fromUtf8("groupBox_gamepad"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_gamepad->sizePolicy().hasHeightForWidth());
        groupBox_gamepad->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_gamepad->setFont(font1);
        comboBox_gamepad_list = new QComboBox(groupBox_gamepad);
        comboBox_gamepad_list->setObjectName(QString::fromUtf8("comboBox_gamepad_list"));
        comboBox_gamepad_list->setGeometry(QRect(20, 60, 210, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        comboBox_gamepad_list->setFont(font2);
        pushButton_updategamepads = new QPushButton(groupBox_gamepad);
        pushButton_updategamepads->setObjectName(QString::fromUtf8("pushButton_updategamepads"));
        pushButton_updategamepads->setGeometry(QRect(280, 100, 61, 51));
        QFont font3;
        font3.setPointSize(10);
        pushButton_updategamepads->setFont(font3);
        label_gamepad_list = new QLabel(groupBox_gamepad);
        label_gamepad_list->setObjectName(QString::fromUtf8("label_gamepad_list"));
        label_gamepad_list->setGeometry(QRect(60, 30, 128, 21));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_gamepad_list->setFont(font4);
        pushButton_connectgamepad = new QPushButton(groupBox_gamepad);
        pushButton_connectgamepad->setObjectName(QString::fromUtf8("pushButton_connectgamepad"));
        pushButton_connectgamepad->setGeometry(QRect(280, 30, 61, 51));
        pushButton_connectgamepad->setFont(font3);

        gridLayout->addWidget(groupBox_gamepad, 0, 0, 1, 1);

        groupBox_commanded_controls = new QGroupBox(groupBox_gamepad_control);
        groupBox_commanded_controls->setObjectName(QString::fromUtf8("groupBox_commanded_controls"));
        sizePolicy.setHeightForWidth(groupBox_commanded_controls->sizePolicy().hasHeightForWidth());
        groupBox_commanded_controls->setSizePolicy(sizePolicy);
        groupBox_commanded_controls->setMinimumSize(QSize(0, 425));
        groupBox_commanded_controls->setFont(font1);
        groupBox_commanded_controls->setCheckable(false);
        label_roll = new QLabel(groupBox_commanded_controls);
        label_roll->setObjectName(QString::fromUtf8("label_roll"));
        label_roll->setGeometry(QRect(30, 350, 61, 21));
        label_roll->setFont(font4);
        label_roll->setAlignment(Qt::AlignCenter);
        label_pitch = new QLabel(groupBox_commanded_controls);
        label_pitch->setObjectName(QString::fromUtf8("label_pitch"));
        label_pitch->setGeometry(QRect(120, 350, 61, 21));
        label_pitch->setFont(font4);
        label_pitch->setAlignment(Qt::AlignCenter);
        label_yaw = new QLabel(groupBox_commanded_controls);
        label_yaw->setObjectName(QString::fromUtf8("label_yaw"));
        label_yaw->setGeometry(QRect(210, 350, 61, 21));
        label_yaw->setFont(font4);
        label_yaw->setAlignment(Qt::AlignCenter);
        label_edit_roll = new QLabel(groupBox_commanded_controls);
        label_edit_roll->setObjectName(QString::fromUtf8("label_edit_roll"));
        label_edit_roll->setGeometry(QRect(30, 380, 51, 31));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        label_edit_roll->setFont(font5);
        label_edit_roll->setFrameShape(QFrame::Panel);
        label_edit_roll->setFrameShadow(QFrame::Sunken);
        label_edit_roll->setAlignment(Qt::AlignCenter);
        label_edit_pitch = new QLabel(groupBox_commanded_controls);
        label_edit_pitch->setObjectName(QString::fromUtf8("label_edit_pitch"));
        label_edit_pitch->setGeometry(QRect(120, 380, 51, 31));
        label_edit_pitch->setFont(font5);
        label_edit_pitch->setFrameShape(QFrame::Panel);
        label_edit_pitch->setFrameShadow(QFrame::Sunken);
        label_edit_pitch->setAlignment(Qt::AlignCenter);
        label_edit_yaw = new QLabel(groupBox_commanded_controls);
        label_edit_yaw->setObjectName(QString::fromUtf8("label_edit_yaw"));
        label_edit_yaw->setGeometry(QRect(210, 380, 51, 31));
        label_edit_yaw->setFont(font5);
        label_edit_yaw->setFrameShape(QFrame::Panel);
        label_edit_yaw->setFrameShadow(QFrame::Sunken);
        label_edit_yaw->setAlignment(Qt::AlignCenter);
        label_buttonA = new QLabel(groupBox_commanded_controls);
        label_buttonA->setObjectName(QString::fromUtf8("label_buttonA"));
        label_buttonA->setGeometry(QRect(20, 200, 71, 21));
        label_buttonA->setFont(font4);
        label_buttonA->setAlignment(Qt::AlignCenter);
        label_buttonB = new QLabel(groupBox_commanded_controls);
        label_buttonB->setObjectName(QString::fromUtf8("label_buttonB"));
        label_buttonB->setGeometry(QRect(110, 200, 71, 21));
        label_buttonB->setFont(font4);
        label_buttonB->setAlignment(Qt::AlignCenter);
        label_buttonX = new QLabel(groupBox_commanded_controls);
        label_buttonX->setObjectName(QString::fromUtf8("label_buttonX"));
        label_buttonX->setGeometry(QRect(200, 200, 71, 21));
        label_buttonX->setFont(font4);
        label_buttonX->setAlignment(Qt::AlignCenter);
        label_buttonY = new QLabel(groupBox_commanded_controls);
        label_buttonY->setObjectName(QString::fromUtf8("label_buttonY"));
        label_buttonY->setGeometry(QRect(290, 200, 71, 21));
        label_buttonY->setFont(font4);
        label_buttonY->setAlignment(Qt::AlignCenter);
        label_edit_buttonA = new QLabel(groupBox_commanded_controls);
        label_edit_buttonA->setObjectName(QString::fromUtf8("label_edit_buttonA"));
        label_edit_buttonA->setGeometry(QRect(30, 230, 51, 31));
        label_edit_buttonA->setFont(font5);
        label_edit_buttonA->setFrameShape(QFrame::Panel);
        label_edit_buttonA->setFrameShadow(QFrame::Sunken);
        label_edit_buttonA->setAlignment(Qt::AlignCenter);
        label_edit_buttonB = new QLabel(groupBox_commanded_controls);
        label_edit_buttonB->setObjectName(QString::fromUtf8("label_edit_buttonB"));
        label_edit_buttonB->setGeometry(QRect(120, 230, 51, 31));
        label_edit_buttonB->setFont(font5);
        label_edit_buttonB->setFrameShape(QFrame::Panel);
        label_edit_buttonB->setFrameShadow(QFrame::Sunken);
        label_edit_buttonB->setAlignment(Qt::AlignCenter);
        label_edit_buttonX = new QLabel(groupBox_commanded_controls);
        label_edit_buttonX->setObjectName(QString::fromUtf8("label_edit_buttonX"));
        label_edit_buttonX->setGeometry(QRect(210, 230, 51, 31));
        label_edit_buttonX->setFont(font5);
        label_edit_buttonX->setFrameShape(QFrame::Panel);
        label_edit_buttonX->setFrameShadow(QFrame::Sunken);
        label_edit_buttonX->setAlignment(Qt::AlignCenter);
        label_edit_buttonY = new QLabel(groupBox_commanded_controls);
        label_edit_buttonY->setObjectName(QString::fromUtf8("label_edit_buttonY"));
        label_edit_buttonY->setGeometry(QRect(300, 230, 51, 31));
        label_edit_buttonY->setFont(font5);
        label_edit_buttonY->setFrameShape(QFrame::Panel);
        label_edit_buttonY->setFrameShadow(QFrame::Sunken);
        label_edit_buttonY->setAlignment(Qt::AlignCenter);
        label_edit_buttonR2 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonR2->setObjectName(QString::fromUtf8("label_edit_buttonR2"));
        label_edit_buttonR2->setGeometry(QRect(300, 310, 51, 31));
        label_edit_buttonR2->setFont(font5);
        label_edit_buttonR2->setFrameShape(QFrame::Panel);
        label_edit_buttonR2->setFrameShadow(QFrame::Sunken);
        label_edit_buttonR2->setAlignment(Qt::AlignCenter);
        label_buttonL1 = new QLabel(groupBox_commanded_controls);
        label_buttonL1->setObjectName(QString::fromUtf8("label_buttonL1"));
        label_buttonL1->setGeometry(QRect(20, 280, 71, 21));
        label_buttonL1->setFont(font4);
        label_buttonL1->setAlignment(Qt::AlignCenter);
        label_buttonL2 = new QLabel(groupBox_commanded_controls);
        label_buttonL2->setObjectName(QString::fromUtf8("label_buttonL2"));
        label_buttonL2->setGeometry(QRect(110, 280, 71, 21));
        label_buttonL2->setFont(font4);
        label_buttonL2->setAlignment(Qt::AlignCenter);
        label_edit_buttonL1 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonL1->setObjectName(QString::fromUtf8("label_edit_buttonL1"));
        label_edit_buttonL1->setGeometry(QRect(30, 310, 51, 31));
        label_edit_buttonL1->setFont(font5);
        label_edit_buttonL1->setFrameShape(QFrame::Panel);
        label_edit_buttonL1->setFrameShadow(QFrame::Sunken);
        label_edit_buttonL1->setAlignment(Qt::AlignCenter);
        label_edit_buttonR1 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonR1->setObjectName(QString::fromUtf8("label_edit_buttonR1"));
        label_edit_buttonR1->setGeometry(QRect(210, 310, 51, 31));
        label_edit_buttonR1->setFont(font5);
        label_edit_buttonR1->setFrameShape(QFrame::Panel);
        label_edit_buttonR1->setFrameShadow(QFrame::Sunken);
        label_edit_buttonR1->setAlignment(Qt::AlignCenter);
        label_buttonR1 = new QLabel(groupBox_commanded_controls);
        label_buttonR1->setObjectName(QString::fromUtf8("label_buttonR1"));
        label_buttonR1->setGeometry(QRect(200, 280, 71, 21));
        label_buttonR1->setFont(font4);
        label_buttonR1->setAlignment(Qt::AlignCenter);
        label_edit_buttonL2 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonL2->setObjectName(QString::fromUtf8("label_edit_buttonL2"));
        label_edit_buttonL2->setGeometry(QRect(120, 310, 51, 31));
        label_edit_buttonL2->setFont(font5);
        label_edit_buttonL2->setFrameShape(QFrame::Panel);
        label_edit_buttonL2->setFrameShadow(QFrame::Sunken);
        label_edit_buttonL2->setAlignment(Qt::AlignCenter);
        label_buttonR2 = new QLabel(groupBox_commanded_controls);
        label_buttonR2->setObjectName(QString::fromUtf8("label_buttonR2"));
        label_buttonR2->setGeometry(QRect(290, 280, 71, 21));
        label_buttonR2->setFont(font4);
        label_buttonR2->setAlignment(Qt::AlignCenter);
        label_buttonSelected = new QLabel(groupBox_commanded_controls);
        label_buttonSelected->setObjectName(QString::fromUtf8("label_buttonSelected"));
        label_buttonSelected->setGeometry(QRect(100, 30, 111, 21));
        label_buttonSelected->setFont(font4);
        label_buttonSelected->setAlignment(Qt::AlignCenter);
        label_edit_buttonSelected = new QLabel(groupBox_commanded_controls);
        label_edit_buttonSelected->setObjectName(QString::fromUtf8("label_edit_buttonSelected"));
        label_edit_buttonSelected->setGeometry(QRect(120, 60, 51, 31));
        label_edit_buttonSelected->setFont(font5);
        label_edit_buttonSelected->setFrameShape(QFrame::Panel);
        label_edit_buttonSelected->setFrameShadow(QFrame::Sunken);
        label_edit_buttonSelected->setAlignment(Qt::AlignCenter);
        label_buttonStart = new QLabel(groupBox_commanded_controls);
        label_buttonStart->setObjectName(QString::fromUtf8("label_buttonStart"));
        label_buttonStart->setGeometry(QRect(10, 30, 91, 21));
        label_buttonStart->setFont(font4);
        label_buttonStart->setAlignment(Qt::AlignCenter);
        label_edit_buttonStart = new QLabel(groupBox_commanded_controls);
        label_edit_buttonStart->setObjectName(QString::fromUtf8("label_edit_buttonStart"));
        label_edit_buttonStart->setGeometry(QRect(30, 60, 51, 31));
        label_edit_buttonStart->setFont(font5);
        label_edit_buttonStart->setFrameShape(QFrame::Panel);
        label_edit_buttonStart->setFrameShadow(QFrame::Sunken);
        label_edit_buttonStart->setAlignment(Qt::AlignCenter);
        label_edit_throttle = new QLabel(groupBox_commanded_controls);
        label_edit_throttle->setObjectName(QString::fromUtf8("label_edit_throttle"));
        label_edit_throttle->setGeometry(QRect(300, 380, 51, 31));
        label_edit_throttle->setFont(font5);
        label_edit_throttle->setFrameShape(QFrame::Panel);
        label_edit_throttle->setFrameShadow(QFrame::Sunken);
        label_edit_throttle->setAlignment(Qt::AlignCenter);
        label_throttle = new QLabel(groupBox_commanded_controls);
        label_throttle->setObjectName(QString::fromUtf8("label_throttle"));
        label_throttle->setGeometry(QRect(290, 350, 61, 21));
        label_throttle->setFont(font4);
        label_throttle->setAlignment(Qt::AlignCenter);
        label_edit_buttonLeft = new QLabel(groupBox_commanded_controls);
        label_edit_buttonLeft->setObjectName(QString::fromUtf8("label_edit_buttonLeft"));
        label_edit_buttonLeft->setGeometry(QRect(40, 140, 51, 31));
        label_edit_buttonLeft->setFont(font5);
        label_edit_buttonLeft->setFrameShape(QFrame::Panel);
        label_edit_buttonLeft->setFrameShadow(QFrame::Sunken);
        label_edit_buttonLeft->setAlignment(Qt::AlignCenter);
        label_buttonLeft = new QLabel(groupBox_commanded_controls);
        label_buttonLeft->setObjectName(QString::fromUtf8("label_buttonLeft"));
        label_buttonLeft->setGeometry(QRect(20, 110, 81, 21));
        label_buttonLeft->setFont(font4);
        label_buttonLeft->setAlignment(Qt::AlignCenter);
        label_edit_buttonRight = new QLabel(groupBox_commanded_controls);
        label_edit_buttonRight->setObjectName(QString::fromUtf8("label_edit_buttonRight"));
        label_edit_buttonRight->setGeometry(QRect(120, 140, 51, 31));
        label_edit_buttonRight->setFont(font5);
        label_edit_buttonRight->setFrameShape(QFrame::Panel);
        label_edit_buttonRight->setFrameShadow(QFrame::Sunken);
        label_edit_buttonRight->setAlignment(Qt::AlignCenter);
        label_buttonRight = new QLabel(groupBox_commanded_controls);
        label_buttonRight->setObjectName(QString::fromUtf8("label_buttonRight"));
        label_buttonRight->setGeometry(QRect(100, 110, 91, 21));
        label_buttonRight->setFont(font4);
        label_buttonRight->setAlignment(Qt::AlignCenter);
        label_edit_buttonL3 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonL3->setObjectName(QString::fromUtf8("label_edit_buttonL3"));
        label_edit_buttonL3->setGeometry(QRect(220, 60, 51, 31));
        label_edit_buttonL3->setFont(font5);
        label_edit_buttonL3->setFrameShape(QFrame::Panel);
        label_edit_buttonL3->setFrameShadow(QFrame::Sunken);
        label_edit_buttonL3->setAlignment(Qt::AlignCenter);
        label_buttonL3 = new QLabel(groupBox_commanded_controls);
        label_buttonL3->setObjectName(QString::fromUtf8("label_buttonL3"));
        label_buttonL3->setGeometry(QRect(210, 30, 71, 21));
        label_buttonL3->setFont(font4);
        label_buttonL3->setAlignment(Qt::AlignCenter);
        label_edit_buttonR3 = new QLabel(groupBox_commanded_controls);
        label_edit_buttonR3->setObjectName(QString::fromUtf8("label_edit_buttonR3"));
        label_edit_buttonR3->setGeometry(QRect(300, 60, 51, 31));
        label_edit_buttonR3->setFont(font5);
        label_edit_buttonR3->setFrameShape(QFrame::Panel);
        label_edit_buttonR3->setFrameShadow(QFrame::Sunken);
        label_edit_buttonR3->setAlignment(Qt::AlignCenter);
        label_buttonR3 = new QLabel(groupBox_commanded_controls);
        label_buttonR3->setObjectName(QString::fromUtf8("label_buttonR3"));
        label_buttonR3->setGeometry(QRect(290, 30, 71, 21));
        label_buttonR3->setFont(font4);
        label_buttonR3->setAlignment(Qt::AlignCenter);
        label_edit_buttonUp = new QLabel(groupBox_commanded_controls);
        label_edit_buttonUp->setObjectName(QString::fromUtf8("label_edit_buttonUp"));
        label_edit_buttonUp->setGeometry(QRect(300, 140, 51, 31));
        label_edit_buttonUp->setFont(font5);
        label_edit_buttonUp->setFrameShape(QFrame::Panel);
        label_edit_buttonUp->setFrameShadow(QFrame::Sunken);
        label_edit_buttonUp->setAlignment(Qt::AlignCenter);
        label_buttonUp = new QLabel(groupBox_commanded_controls);
        label_buttonUp->setObjectName(QString::fromUtf8("label_buttonUp"));
        label_buttonUp->setGeometry(QRect(290, 110, 71, 21));
        label_buttonUp->setFont(font4);
        label_buttonUp->setAlignment(Qt::AlignCenter);
        label_buttonDown = new QLabel(groupBox_commanded_controls);
        label_buttonDown->setObjectName(QString::fromUtf8("label_buttonDown"));
        label_buttonDown->setGeometry(QRect(190, 110, 91, 21));
        label_buttonDown->setFont(font4);
        label_buttonDown->setAlignment(Qt::AlignCenter);
        label_edit_buttonDown = new QLabel(groupBox_commanded_controls);
        label_edit_buttonDown->setObjectName(QString::fromUtf8("label_edit_buttonDown"));
        label_edit_buttonDown->setGeometry(QRect(210, 140, 51, 31));
        label_edit_buttonDown->setFont(font5);
        label_edit_buttonDown->setFrameShape(QFrame::Panel);
        label_edit_buttonDown->setFrameShadow(QFrame::Sunken);
        label_edit_buttonDown->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(groupBox_commanded_controls, 1, 0, 1, 1);

        groupBox_additional_controls = new QGroupBox(Dialog_FlightControl);
        groupBox_additional_controls->setObjectName(QString::fromUtf8("groupBox_additional_controls"));
        groupBox_additional_controls->setGeometry(QRect(470, 140, 501, 611));
        widget = new QWidget(groupBox_additional_controls);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 101, 61));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font3);

        verticalLayout_2->addWidget(pushButton);

        groupbox_control_settings = new QGroupBox(Dialog_FlightControl);
        groupbox_control_settings->setObjectName(QString::fromUtf8("groupbox_control_settings"));
        groupbox_control_settings->setGeometry(QRect(20, 10, 351, 100));
        groupbox_control_settings->setMinimumSize(QSize(0, 80));
        groupbox_control_settings->setMaximumSize(QSize(16777215, 100));
        groupbox_control_settings->setBaseSize(QSize(200, 120));
        groupbox_control_settings->setFont(font1);
        groupbox_control_settings->setAutoFillBackground(false);
        groupbox_control_settings->setFlat(false);
        groupbox_control_settings->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupbox_control_settings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_control_mode = new QHBoxLayout();
        horizontalLayout_control_mode->setSpacing(15);
        horizontalLayout_control_mode->setObjectName(QString::fromUtf8("horizontalLayout_control_mode"));
        radioButton_autonomous = new QRadioButton(groupbox_control_settings);
        radioButton_autonomous->setObjectName(QString::fromUtf8("radioButton_autonomous"));
        radioButton_autonomous->setFont(font4);
        radioButton_autonomous->setChecked(true);

        horizontalLayout_control_mode->addWidget(radioButton_autonomous);

        radioButton_manual = new QRadioButton(groupbox_control_settings);
        radioButton_manual->setObjectName(QString::fromUtf8("radioButton_manual"));
        radioButton_manual->setFont(font3);

        horizontalLayout_control_mode->addWidget(radioButton_manual);


        horizontalLayout->addLayout(horizontalLayout_control_mode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_system_type = new QLabel(groupbox_control_settings);
        label_system_type->setObjectName(QString::fromUtf8("label_system_type"));
        label_system_type->setFont(font3);
        label_system_type->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_system_type);

        comboBox_system_type = new QComboBox(groupbox_control_settings);
        comboBox_system_type->setObjectName(QString::fromUtf8("comboBox_system_type"));

        verticalLayout->addWidget(comboBox_system_type);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog_FlightControl);

        QMetaObject::connectSlotsByName(Dialog_FlightControl);
    } // setupUi

    void retranslateUi(QDialog *Dialog_FlightControl)
    {
        Dialog_FlightControl->setWindowTitle(QApplication::translate("Dialog_FlightControl", "Gamepad Settings", nullptr));
        groupBox_gamepad_control->setTitle(QApplication::translate("Dialog_FlightControl", "Gamepad Control", nullptr));
        groupBox_gamepad->setTitle(QApplication::translate("Dialog_FlightControl", "Gamepad", nullptr));
        pushButton_updategamepads->setText(QApplication::translate("Dialog_FlightControl", "Update", nullptr));
        label_gamepad_list->setText(QApplication::translate("Dialog_FlightControl", "Selected Gamepad", nullptr));
        pushButton_connectgamepad->setText(QApplication::translate("Dialog_FlightControl", "Connect", nullptr));
        groupBox_commanded_controls->setTitle(QApplication::translate("Dialog_FlightControl", "Commanded Controls", nullptr));
        label_roll->setText(QApplication::translate("Dialog_FlightControl", "Roll [\302\272]", nullptr));
        label_pitch->setText(QApplication::translate("Dialog_FlightControl", "Pitch [\302\272]", nullptr));
        label_yaw->setText(QApplication::translate("Dialog_FlightControl", "Yaw [\302\272]", nullptr));
        label_edit_roll->setText(QString());
        label_edit_pitch->setText(QString());
        label_edit_yaw->setText(QString());
        label_buttonA->setText(QApplication::translate("Dialog_FlightControl", "Button A", nullptr));
        label_buttonB->setText(QApplication::translate("Dialog_FlightControl", "Button B", nullptr));
        label_buttonX->setText(QApplication::translate("Dialog_FlightControl", "Button X", nullptr));
        label_buttonY->setText(QApplication::translate("Dialog_FlightControl", "Button Y", nullptr));
        label_edit_buttonA->setText(QString());
        label_edit_buttonB->setText(QString());
        label_edit_buttonX->setText(QString());
        label_edit_buttonY->setText(QString());
        label_edit_buttonR2->setText(QString());
        label_buttonL1->setText(QApplication::translate("Dialog_FlightControl", "Button L1", nullptr));
        label_buttonL2->setText(QApplication::translate("Dialog_FlightControl", "Button L2", nullptr));
        label_edit_buttonL1->setText(QString());
        label_edit_buttonR1->setText(QString());
        label_buttonR1->setText(QApplication::translate("Dialog_FlightControl", "Button R1", nullptr));
        label_edit_buttonL2->setText(QString());
        label_buttonR2->setText(QApplication::translate("Dialog_FlightControl", "Button R2", nullptr));
        label_buttonSelected->setText(QApplication::translate("Dialog_FlightControl", "Button Selected", nullptr));
        label_edit_buttonSelected->setText(QString());
        label_buttonStart->setText(QApplication::translate("Dialog_FlightControl", "Button Start", nullptr));
        label_edit_buttonStart->setText(QString());
        label_edit_throttle->setText(QString());
        label_throttle->setText(QApplication::translate("Dialog_FlightControl", "Throttle", nullptr));
        label_edit_buttonLeft->setText(QString());
        label_buttonLeft->setText(QApplication::translate("Dialog_FlightControl", "Button Left", nullptr));
        label_edit_buttonRight->setText(QString());
        label_buttonRight->setText(QApplication::translate("Dialog_FlightControl", "Button Right", nullptr));
        label_edit_buttonL3->setText(QString());
        label_buttonL3->setText(QApplication::translate("Dialog_FlightControl", "Button L3", nullptr));
        label_edit_buttonR3->setText(QString());
        label_buttonR3->setText(QApplication::translate("Dialog_FlightControl", "Button R3", nullptr));
        label_edit_buttonUp->setText(QString());
        label_buttonUp->setText(QApplication::translate("Dialog_FlightControl", "Button Up", nullptr));
        label_buttonDown->setText(QApplication::translate("Dialog_FlightControl", "Button Down", nullptr));
        label_edit_buttonDown->setText(QString());
        groupBox_additional_controls->setTitle(QApplication::translate("Dialog_FlightControl", "Additional Controls", nullptr));
        label->setText(QApplication::translate("Dialog_FlightControl", "Langing Gear", nullptr));
        pushButton->setText(QApplication::translate("Dialog_FlightControl", "Deploy", nullptr));
        groupbox_control_settings->setTitle(QApplication::translate("Dialog_FlightControl", "Control Settings", nullptr));
        radioButton_autonomous->setText(QApplication::translate("Dialog_FlightControl", "Autonomous", nullptr));
        radioButton_manual->setText(QApplication::translate("Dialog_FlightControl", "Manual", nullptr));
        label_system_type->setText(QApplication::translate("Dialog_FlightControl", "System Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_FlightControl: public Ui_Dialog_FlightControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FLIGHTCONTROL_H
