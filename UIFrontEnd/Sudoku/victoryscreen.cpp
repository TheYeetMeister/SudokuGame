#include "victoryscreen.h"
#include "ui_victoryscreen.h"

VictoryScreen::VictoryScreen(QWidget *parent, unsigned difficulty)
    : QDialog(parent), difficulty(difficulty)
    , ui(new Ui::VictoryScreen)
{
    ui->setupUi(this);
    displayVictoryScreen();
}

VictoryScreen::~VictoryScreen()
{
    delete ui;
}

void VictoryScreen::displayVictoryScreen() {
    QString pathToImg;

    if (difficulty < 3) {
        pathToImg = ("../../imgs/win_imgs/veryeasy-easy.winimg.png");
    } else {
        pathToImg = ("../../imgs/win_imgs/med-evil-winimg.png");
    }

    QPixmap pm(pathToImg);
    ui->displayScreen->setPixmap(pm);
    ui->displayScreen->setScaledContents(true);
}
