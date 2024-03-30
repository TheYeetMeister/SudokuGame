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

void VictoryScreen::displayStars() {
    std::vector<QLabel*> stars {ui->star1, ui->star2, ui->star3, ui->star4, ui->star5};
    QString pathToImg;

    switch(difficulty) {
        case 1:
            pathToImg = "../../imgs/win_imgs/veryeasy_star.png";
            break;
        default:
            throw std::out_of_range("given difficulty value is out of range");
    }

    QPixmap starImg(pathToImg);
    for (unsigned i = 0; i < difficulty; ++i) {
        stars[i]->setPixmap(starImg);
        stars[i]->setScaledContents(true);
    }
}
