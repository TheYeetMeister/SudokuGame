/********************************************************************************
** Form generated from reading UI file 'victoryscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORYSCREEN_H
#define UI_VICTORYSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_VictoryScreen
{
public:
    QLabel *displayScreen;
    QLabel *star1;
    QLabel *star2;
    QLabel *star3;
    QLabel *star4;
    QLabel *star5;

    void setupUi(QDialog *VictoryScreen)
    {
        if (VictoryScreen->objectName().isEmpty())
            VictoryScreen->setObjectName("VictoryScreen");
        VictoryScreen->resize(775, 565);
        displayScreen = new QLabel(VictoryScreen);
        displayScreen->setObjectName("displayScreen");
        displayScreen->setGeometry(QRect(0, 120, 771, 441));
        star1 = new QLabel(VictoryScreen);
        star1->setObjectName("star1");
        star1->setGeometry(QRect(320, 70, 71, 71));
        star2 = new QLabel(VictoryScreen);
        star2->setObjectName("star2");
        star2->setGeometry(QRect(220, 80, 71, 71));
        star3 = new QLabel(VictoryScreen);
        star3->setObjectName("star3");
        star3->setGeometry(QRect(420, 80, 71, 71));
        star4 = new QLabel(VictoryScreen);
        star4->setObjectName("star4");
        star4->setGeometry(QRect(170, 170, 71, 71));
        star5 = new QLabel(VictoryScreen);
        star5->setObjectName("star5");
        star5->setGeometry(QRect(490, 170, 71, 71));

        retranslateUi(VictoryScreen);

        QMetaObject::connectSlotsByName(VictoryScreen);
    } // setupUi

    void retranslateUi(QDialog *VictoryScreen)
    {
        VictoryScreen->setWindowTitle(QCoreApplication::translate("VictoryScreen", "Dialog", nullptr));
        displayScreen->setText(QString());
        star1->setText(QString());
        star2->setText(QString());
        star3->setText(QString());
        star4->setText(QString());
        star5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VictoryScreen: public Ui_VictoryScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORYSCREEN_H
