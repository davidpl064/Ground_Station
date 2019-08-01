/********************************************************************************
** Form generated from reading UI file 'dialog_infotaxis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_INFOTAXIS_H
#define UI_DIALOG_INFOTAXIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Infotaxis
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *surface_widget;
    QFrame *frame;
    QFrame *frame_control;
    QPushButton *pushButton_move;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_next_mov;
    QLabel *label_edit_next_mov;

    void setupUi(QDialog *Dialog_Infotaxis)
    {
        if (Dialog_Infotaxis->objectName().isEmpty())
            Dialog_Infotaxis->setObjectName(QString::fromUtf8("Dialog_Infotaxis"));
        Dialog_Infotaxis->resize(1145, 780);
        gridLayout = new QGridLayout(Dialog_Infotaxis);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(Dialog_Infotaxis);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        surface_widget = new QWidget(splitter);
        surface_widget->setObjectName(QString::fromUtf8("surface_widget"));
        splitter->addWidget(surface_widget);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_control = new QFrame(frame);
        frame_control->setObjectName(QString::fromUtf8("frame_control"));
        frame_control->setGeometry(QRect(10, 10, 171, 281));
        frame_control->setFrameShape(QFrame::StyledPanel);
        frame_control->setFrameShadow(QFrame::Raised);
        pushButton_move = new QPushButton(frame_control);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(50, 150, 71, 61));
        QFont font;
        font.setPointSize(9);
        pushButton_move->setFont(font);
        pushButton_move->setFlat(false);
        widget = new QWidget(frame_control);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 121, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_next_mov = new QLabel(widget);
        label_next_mov->setObjectName(QString::fromUtf8("label_next_mov"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_next_mov->setFont(font1);
        label_next_mov->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_next_mov);

        label_edit_next_mov = new QLabel(widget);
        label_edit_next_mov->setObjectName(QString::fromUtf8("label_edit_next_mov"));
        QFont font2;
        font2.setPointSize(10);
        label_edit_next_mov->setFont(font2);
        label_edit_next_mov->setFrameShape(QFrame::Panel);
        label_edit_next_mov->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(label_edit_next_mov);

        splitter->addWidget(frame);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(Dialog_Infotaxis);

        pushButton_move->setDefault(false);


        QMetaObject::connectSlotsByName(Dialog_Infotaxis);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Infotaxis)
    {
        Dialog_Infotaxis->setWindowTitle(QApplication::translate("Dialog_Infotaxis", "Dialog", nullptr));
        pushButton_move->setText(QApplication::translate("Dialog_Infotaxis", "Go", nullptr));
        label_next_mov->setText(QApplication::translate("Dialog_Infotaxis", "Next Movement", nullptr));
        label_edit_next_mov->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_Infotaxis: public Ui_Dialog_Infotaxis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_INFOTAXIS_H
