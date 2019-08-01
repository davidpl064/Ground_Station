/********************************************************************************
** Form generated from reading UI file 'dialog_graphics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GRAPHICS_H
#define UI_DIALOG_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_Dialog_Graphics
{
public:
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *grid_layout_figures;
    QChartView *chartview_1;
    QChartView *chartview_2;
    QChartView *chartview_3;
    QChartView *chartview_4;
    QChartView *chartview_5;
    QChartView *chartview_6;
    QFrame *frame_buttons;
    QPushButton *pushButton_start_graphics;

    void setupUi(QDialog *Dialog_Graphics)
    {
        if (Dialog_Graphics->objectName().isEmpty())
            Dialog_Graphics->setObjectName(QString::fromUtf8("Dialog_Graphics"));
        Dialog_Graphics->resize(1228, 780);
        gridLayout_2 = new QGridLayout(Dialog_Graphics);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(Dialog_Graphics);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        grid_layout_figures = new QGridLayout(layoutWidget);
        grid_layout_figures->setSpacing(30);
        grid_layout_figures->setObjectName(QString::fromUtf8("grid_layout_figures"));
        grid_layout_figures->setContentsMargins(0, 0, 0, 0);
        chartview_1 = new QChartView(layoutWidget);
        chartview_1->setObjectName(QString::fromUtf8("chartview_1"));

        grid_layout_figures->addWidget(chartview_1, 0, 0, 1, 1);

        chartview_2 = new QChartView(layoutWidget);
        chartview_2->setObjectName(QString::fromUtf8("chartview_2"));

        grid_layout_figures->addWidget(chartview_2, 0, 1, 1, 1);

        chartview_3 = new QChartView(layoutWidget);
        chartview_3->setObjectName(QString::fromUtf8("chartview_3"));

        grid_layout_figures->addWidget(chartview_3, 0, 2, 1, 1);

        chartview_4 = new QChartView(layoutWidget);
        chartview_4->setObjectName(QString::fromUtf8("chartview_4"));

        grid_layout_figures->addWidget(chartview_4, 1, 0, 1, 1);

        chartview_5 = new QChartView(layoutWidget);
        chartview_5->setObjectName(QString::fromUtf8("chartview_5"));

        grid_layout_figures->addWidget(chartview_5, 1, 1, 1, 1);

        chartview_6 = new QChartView(layoutWidget);
        chartview_6->setObjectName(QString::fromUtf8("chartview_6"));

        grid_layout_figures->addWidget(chartview_6, 1, 2, 1, 1);

        splitter->addWidget(layoutWidget);
        frame_buttons = new QFrame(splitter);
        frame_buttons->setObjectName(QString::fromUtf8("frame_buttons"));
        frame_buttons->setMinimumSize(QSize(0, 0));
        frame_buttons->setMaximumSize(QSize(200, 16777215));
        frame_buttons->setFrameShape(QFrame::StyledPanel);
        frame_buttons->setFrameShadow(QFrame::Raised);
        pushButton_start_graphics = new QPushButton(frame_buttons);
        pushButton_start_graphics->setObjectName(QString::fromUtf8("pushButton_start_graphics"));
        pushButton_start_graphics->setGeometry(QRect(20, 30, 91, 41));
        splitter->addWidget(frame_buttons);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(Dialog_Graphics);

        QMetaObject::connectSlotsByName(Dialog_Graphics);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Graphics)
    {
        Dialog_Graphics->setWindowTitle(QApplication::translate("Dialog_Graphics", "Dialog", nullptr));
        pushButton_start_graphics->setText(QApplication::translate("Dialog_Graphics", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Graphics: public Ui_Dialog_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GRAPHICS_H
