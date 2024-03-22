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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QLabel *DiffLabel;
    QPushButton *QuitBtn;
    QPushButton *QuitAllBtn;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName("game");
        game->resize(788, 544);
        DiffLabel = new QLabel(game);
        DiffLabel->setObjectName("DiffLabel");
        DiffLabel->setGeometry(QRect(150, 140, 191, 71));
        QFont font;
        font.setPointSize(30);
        DiffLabel->setFont(font);
        QuitBtn = new QPushButton(game);
        QuitBtn->setObjectName("QuitBtn");
        QuitBtn->setGeometry(QRect(640, 40, 111, 41));
        QFont font1;
        font1.setPointSize(15);
        QuitBtn->setFont(font1);
        QuitAllBtn = new QPushButton(game);
        QuitAllBtn->setObjectName("QuitAllBtn");
        QuitAllBtn->setGeometry(QRect(640, 100, 111, 41));
        QuitAllBtn->setFont(font1);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        DiffLabel->setText(QCoreApplication::translate("game", "TextLabel", nullptr));
        QuitBtn->setText(QCoreApplication::translate("game", "Quit", nullptr));
        QuitAllBtn->setText(QCoreApplication::translate("game", "Quit All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
