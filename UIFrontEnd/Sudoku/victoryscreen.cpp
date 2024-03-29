#include "victoryscreen.h"
#include "ui_victoryscreen.h"

VictoryScreen::VictoryScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VictoryScreen)
{
    ui->setupUi(this);
}

VictoryScreen::~VictoryScreen()
{
    delete ui;
}
