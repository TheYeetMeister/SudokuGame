/********************************************************************************
** Form generated from reading UI file 'sudokumainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUMAINWINDOW_H
#define UI_SUDOKUMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *StartBtn;
    QLabel *label;
    QLabel *label_2;
    QPushButton *VEasyBtn;
    QPushButton *EasyBtn;
    QPushButton *MedBtn;
    QPushButton *HardBtn;
    QPushButton *EvilBtn;
    QPushButton *QuitBtn;

    void setupUi(QMainWindow *SudokuMainWindow)
    {
        if (SudokuMainWindow->objectName().isEmpty())
            SudokuMainWindow->setObjectName("SudokuMainWindow");
        SudokuMainWindow->resize(800, 600);
        centralwidget = new QWidget(SudokuMainWindow);
        centralwidget->setObjectName("centralwidget");
        StartBtn = new QPushButton(centralwidget);
        StartBtn->setObjectName("StartBtn");
        StartBtn->setGeometry(QRect(410, 320, 211, 81));
        QFont font;
        font.setPointSize(30);
        StartBtn->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 30, 401, 161));
        QFont font1;
        font1.setPointSize(70);
        font1.setBold(true);
        font1.setItalic(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 200, 191, 51));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(true);
        label_2->setFont(font2);
        VEasyBtn = new QPushButton(centralwidget);
        VEasyBtn->setObjectName("VEasyBtn");
        VEasyBtn->setGeometry(QRect(180, 270, 111, 41));
        QFont font3;
        font3.setPointSize(15);
        VEasyBtn->setFont(font3);
        VEasyBtn->setAutoFillBackground(false);
        EasyBtn = new QPushButton(centralwidget);
        EasyBtn->setObjectName("EasyBtn");
        EasyBtn->setGeometry(QRect(180, 320, 111, 41));
        EasyBtn->setFont(font3);
        MedBtn = new QPushButton(centralwidget);
        MedBtn->setObjectName("MedBtn");
        MedBtn->setGeometry(QRect(180, 370, 111, 41));
        MedBtn->setFont(font3);
        HardBtn = new QPushButton(centralwidget);
        HardBtn->setObjectName("HardBtn");
        HardBtn->setGeometry(QRect(180, 420, 111, 41));
        HardBtn->setFont(font3);
        EvilBtn = new QPushButton(centralwidget);
        EvilBtn->setObjectName("EvilBtn");
        EvilBtn->setGeometry(QRect(180, 470, 111, 41));
        EvilBtn->setFont(font3);
        QuitBtn = new QPushButton(centralwidget);
        QuitBtn->setObjectName("QuitBtn");
        QuitBtn->setGeometry(QRect(620, 40, 111, 41));
        QuitBtn->setFont(font3);
        SudokuMainWindow->setCentralWidget(centralwidget);

        retranslateUi(SudokuMainWindow);

        QMetaObject::connectSlotsByName(SudokuMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuMainWindow)
    {
        SudokuMainWindow->setWindowTitle(QCoreApplication::translate("SudokuMainWindow", "SudokuMainWindow", nullptr));
        StartBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Start Game", nullptr));
        label->setText(QCoreApplication::translate("SudokuMainWindow", "Sudoku", nullptr));
        label_2->setText(QCoreApplication::translate("SudokuMainWindow", "Difficulty:", nullptr));
        VEasyBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Very Easy", nullptr));
        EasyBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Easy", nullptr));
        MedBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Medium", nullptr));
        HardBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Hard", nullptr));
        EvilBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Evil", nullptr));
        QuitBtn->setText(QCoreApplication::translate("SudokuMainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokuMainWindow: public Ui_SudokuMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUMAINWINDOW_H
