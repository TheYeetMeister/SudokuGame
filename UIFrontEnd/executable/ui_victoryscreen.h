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
    QLabel *confettiLabel;
    QLabel *frogGif;
    QLabel *frogGif2;
    QLabel *crown;

    void setupUi(QDialog *VictoryScreen)
    {
        if (VictoryScreen->objectName().isEmpty())
            VictoryScreen->setObjectName("VictoryScreen");
        VictoryScreen->resize(775, 566);
        displayScreen = new QLabel(VictoryScreen);
        displayScreen->setObjectName("displayScreen");
        displayScreen->setGeometry(QRect(0, 0, 771, 571));
        star1 = new QLabel(VictoryScreen);
        star1->setObjectName("star1");
        star1->setGeometry(QRect(340, 270, 111, 111));
        star2 = new QLabel(VictoryScreen);
        star2->setObjectName("star2");
        star2->setGeometry(QRect(260, 320, 71, 71));
        star3 = new QLabel(VictoryScreen);
        star3->setObjectName("star3");
        star3->setGeometry(QRect(460, 320, 71, 71));
        star4 = new QLabel(VictoryScreen);
        star4->setObjectName("star4");
        star4->setGeometry(QRect(230, 400, 51, 51));
        star5 = new QLabel(VictoryScreen);
        star5->setObjectName("star5");
        star5->setGeometry(QRect(530, 400, 51, 51));
        confettiLabel = new QLabel(VictoryScreen);
        confettiLabel->setObjectName("confettiLabel");
        confettiLabel->setGeometry(QRect(0, 0, 771, 571));
        frogGif = new QLabel(VictoryScreen);
        frogGif->setObjectName("frogGif");
        frogGif->setGeometry(QRect(40, 360, 141, 151));
        frogGif2 = new QLabel(VictoryScreen);
        frogGif2->setObjectName("frogGif2");
        frogGif2->setGeometry(QRect(560, 340, 161, 181));
        crown = new QLabel(VictoryScreen);
        crown->setObjectName("crown");
        crown->setGeometry(QRect(340, 120, 101, 101));

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
        confettiLabel->setText(QString());
        frogGif->setText(QString());
        frogGif2->setText(QString());
        crown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VictoryScreen: public Ui_VictoryScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORYSCREEN_H
