/********************************************************************************
** Form generated from reading UI file 'WidgetHSI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETHSI_H
#define UI_WIDGETHSI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <qfi_HSI.h>

QT_BEGIN_NAMESPACE

class Ui_WidgetHSI
{
public:
    qfi_HSI *graphicsHSI;

    void setupUi(QWidget *WidgetHSI)
    {
        if (WidgetHSI->objectName().isEmpty())
            WidgetHSI->setObjectName(QString::fromUtf8("WidgetHSI"));
        WidgetHSI->resize(400, 300);
        graphicsHSI = new qfi_HSI(WidgetHSI);
        graphicsHSI->setObjectName(QString::fromUtf8("graphicsHSI"));
        graphicsHSI->setEnabled(false);
        graphicsHSI->setGeometry(QRect(60, 40, 256, 192));
        graphicsHSI->setFrameShape(QFrame::NoFrame);
        graphicsHSI->setFrameShadow(QFrame::Plain);
        graphicsHSI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsHSI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsHSI->setInteractive(false);

        retranslateUi(WidgetHSI);

        QMetaObject::connectSlotsByName(WidgetHSI);
    } // setupUi

    void retranslateUi(QWidget *WidgetHSI)
    {
        WidgetHSI->setWindowTitle(QApplication::translate("WidgetHSI", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetHSI: public Ui_WidgetHSI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETHSI_H
