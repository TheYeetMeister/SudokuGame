#include "victoryscreen.h"
#include "ui_victoryscreen.h"

VictoryScreen::VictoryScreen(QWidget *parent, unsigned difficulty)
    : QDialog(parent), difficulty(difficulty)
    , ui(new Ui::VictoryScreen)
{
    ui->setupUi(this);
}

VictoryScreen::~VictoryScreen()
{
    delete ui;
}
