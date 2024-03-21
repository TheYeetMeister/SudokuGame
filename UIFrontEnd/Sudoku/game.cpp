#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent, QString message)
    : QDialog(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
    ui->DiffLabel->setText(message);
}

game::~game()
{
    delete ui;
}
