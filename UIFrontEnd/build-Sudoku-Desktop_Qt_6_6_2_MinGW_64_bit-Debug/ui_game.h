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

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QLabel *DiffLabel;

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

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        DiffLabel->setText(QCoreApplication::translate("game", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
