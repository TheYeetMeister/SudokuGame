/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QPushButton *QuitBtn;
    QPushButton *QuitAllBtn;
    QPushButton *grid1;
    QPushButton *grid2;
    QPushButton *numOneBtn;
    QPushButton *numTwoBtn;
    QPushButton *numThreeBtn;
    QPushButton *numFourBtn;
    QPushButton *numFiveBtn;
    QPushButton *numSixBtn;
    QPushButton *numSevenBtn;
    QPushButton *numEightBtn;
    QPushButton *numNineBtn;
    QPushButton *submitBtn;
    QPushButton *grid3;
    QPushButton *remErrorsBtn;
    QPushButton *newGameBtn;
    QPushButton *eraseBtn;
    QPushButton *grid4;
    QPushButton *grid5;
    QPushButton *grid6;
    QPushButton *grid7;
    QPushButton *grid8;
    QPushButton *grid9;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName("game");
        game->resize(1143, 775);
        QuitBtn = new QPushButton(game);
        QuitBtn->setObjectName("QuitBtn");
        QuitBtn->setGeometry(QRect(980, 90, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("MV Boli")});
        font.setPointSize(15);
        QuitBtn->setFont(font);
        QuitAllBtn = new QPushButton(game);
        QuitAllBtn->setObjectName("QuitAllBtn");
        QuitAllBtn->setGeometry(QRect(980, 30, 111, 41));
        QuitAllBtn->setFont(font);
        grid1 = new QPushButton(game);
        grid1->setObjectName("grid1");
        grid1->setGeometry(QRect(110, 80, 51, 51));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid1->setPalette(palette);
        QFont font1;
        font1.setPointSize(30);
        grid1->setFont(font1);
        grid1->setAutoFillBackground(true);
        grid1->setAutoDefault(false);
        grid1->setFlat(true);
        grid2 = new QPushButton(game);
        grid2->setObjectName("grid2");
        grid2->setGeometry(QRect(170, 80, 51, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid2->setPalette(palette1);
        grid2->setFont(font1);
        grid2->setAutoFillBackground(true);
        grid2->setAutoDefault(false);
        grid2->setFlat(true);
        numOneBtn = new QPushButton(game);
        numOneBtn->setObjectName("numOneBtn");
        numOneBtn->setGeometry(QRect(120, 470, 61, 61));
        QFont font2;
        font2.setPointSize(33);
        numOneBtn->setFont(font2);
        numTwoBtn = new QPushButton(game);
        numTwoBtn->setObjectName("numTwoBtn");
        numTwoBtn->setGeometry(QRect(200, 470, 61, 61));
        numTwoBtn->setFont(font2);
        numThreeBtn = new QPushButton(game);
        numThreeBtn->setObjectName("numThreeBtn");
        numThreeBtn->setGeometry(QRect(280, 470, 61, 61));
        numThreeBtn->setFont(font2);
        numFourBtn = new QPushButton(game);
        numFourBtn->setObjectName("numFourBtn");
        numFourBtn->setGeometry(QRect(360, 470, 61, 61));
        numFourBtn->setFont(font2);
        numFiveBtn = new QPushButton(game);
        numFiveBtn->setObjectName("numFiveBtn");
        numFiveBtn->setGeometry(QRect(440, 470, 61, 61));
        numFiveBtn->setFont(font2);
        numSixBtn = new QPushButton(game);
        numSixBtn->setObjectName("numSixBtn");
        numSixBtn->setGeometry(QRect(520, 470, 61, 61));
        numSixBtn->setFont(font2);
        numSevenBtn = new QPushButton(game);
        numSevenBtn->setObjectName("numSevenBtn");
        numSevenBtn->setGeometry(QRect(600, 470, 61, 61));
        numSevenBtn->setFont(font2);
        numEightBtn = new QPushButton(game);
        numEightBtn->setObjectName("numEightBtn");
        numEightBtn->setGeometry(QRect(680, 470, 61, 61));
        numEightBtn->setFont(font2);
        numNineBtn = new QPushButton(game);
        numNineBtn->setObjectName("numNineBtn");
        numNineBtn->setGeometry(QRect(760, 470, 61, 61));
        numNineBtn->setFont(font2);
        submitBtn = new QPushButton(game);
        submitBtn->setObjectName("submitBtn");
        submitBtn->setGeometry(QRect(910, 470, 151, 61));
        QFont font3;
        font3.setPointSize(17);
        submitBtn->setFont(font3);
        grid3 = new QPushButton(game);
        grid3->setObjectName("grid3");
        grid3->setGeometry(QRect(230, 80, 51, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid3->setPalette(palette2);
        grid3->setFont(font1);
        grid3->setAutoFillBackground(true);
        grid3->setAutoDefault(false);
        grid3->setFlat(true);
        remErrorsBtn = new QPushButton(game);
        remErrorsBtn->setObjectName("remErrorsBtn");
        remErrorsBtn->setGeometry(QRect(900, 400, 171, 41));
        QFont font4;
        font4.setPointSize(12);
        remErrorsBtn->setFont(font4);
        newGameBtn = new QPushButton(game);
        newGameBtn->setObjectName("newGameBtn");
        newGameBtn->setGeometry(QRect(870, 280, 231, 91));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("MV Boli")});
        font5.setPointSize(30);
        newGameBtn->setFont(font5);
        eraseBtn = new QPushButton(game);
        eraseBtn->setObjectName("eraseBtn");
        eraseBtn->setGeometry(QRect(400, 550, 131, 61));
        eraseBtn->setFont(font2);
        grid4 = new QPushButton(game);
        grid4->setObjectName("grid4");
        grid4->setGeometry(QRect(290, 80, 51, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid4->setPalette(palette3);
        grid4->setFont(font1);
        grid4->setAutoFillBackground(true);
        grid4->setAutoDefault(false);
        grid4->setFlat(true);
        grid5 = new QPushButton(game);
        grid5->setObjectName("grid5");
        grid5->setGeometry(QRect(350, 80, 51, 51));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid5->setPalette(palette4);
        grid5->setFont(font1);
        grid5->setAutoFillBackground(true);
        grid5->setAutoDefault(false);
        grid5->setFlat(true);
        grid6 = new QPushButton(game);
        grid6->setObjectName("grid6");
        grid6->setGeometry(QRect(410, 80, 51, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid6->setPalette(palette5);
        grid6->setFont(font1);
        grid6->setAutoFillBackground(true);
        grid6->setAutoDefault(false);
        grid6->setFlat(true);
        grid7 = new QPushButton(game);
        grid7->setObjectName("grid7");
        grid7->setGeometry(QRect(470, 80, 51, 51));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid7->setPalette(palette6);
        grid7->setFont(font1);
        grid7->setAutoFillBackground(true);
        grid7->setAutoDefault(false);
        grid7->setFlat(true);
        grid8 = new QPushButton(game);
        grid8->setObjectName("grid8");
        grid8->setGeometry(QRect(530, 80, 51, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid8->setPalette(palette7);
        grid8->setFont(font1);
        grid8->setAutoFillBackground(true);
        grid8->setAutoDefault(false);
        grid8->setFlat(true);
        grid9 = new QPushButton(game);
        grid9->setObjectName("grid9");
        grid9->setGeometry(QRect(590, 80, 51, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        grid9->setPalette(palette8);
        grid9->setFont(font1);
        grid9->setAutoFillBackground(true);
        grid9->setAutoDefault(false);
        grid9->setFlat(true);

        retranslateUi(game);

        grid1->setDefault(false);
        grid2->setDefault(false);
        grid3->setDefault(false);
        grid4->setDefault(false);
        grid5->setDefault(false);
        grid6->setDefault(false);
        grid7->setDefault(false);
        grid8->setDefault(false);
        grid9->setDefault(false);


        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        QuitBtn->setText(QCoreApplication::translate("game", "Quit", nullptr));
        QuitAllBtn->setText(QCoreApplication::translate("game", "Quit All", nullptr));
        grid1->setText(QString());
        grid2->setText(QString());
        numOneBtn->setText(QCoreApplication::translate("game", "1", nullptr));
        numTwoBtn->setText(QCoreApplication::translate("game", "2", nullptr));
        numThreeBtn->setText(QCoreApplication::translate("game", "3", nullptr));
        numFourBtn->setText(QCoreApplication::translate("game", "4", nullptr));
        numFiveBtn->setText(QCoreApplication::translate("game", "5", nullptr));
        numSixBtn->setText(QCoreApplication::translate("game", "6", nullptr));
        numSevenBtn->setText(QCoreApplication::translate("game", "7", nullptr));
        numEightBtn->setText(QCoreApplication::translate("game", "8", nullptr));
        numNineBtn->setText(QCoreApplication::translate("game", "9", nullptr));
        submitBtn->setText(QCoreApplication::translate("game", "Submit board", nullptr));
        grid3->setText(QString());
        remErrorsBtn->setText(QCoreApplication::translate("game", "Remove Error Highlight", nullptr));
        newGameBtn->setText(QCoreApplication::translate("game", "New Game?", nullptr));
        eraseBtn->setText(QCoreApplication::translate("game", "Erase", nullptr));
        grid4->setText(QString());
        grid5->setText(QString());
        grid6->setText(QString());
        grid7->setText(QString());
        grid8->setText(QString());
        grid9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
