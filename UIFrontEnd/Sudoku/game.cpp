#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent, unsigned difficulty)
    : QDialog(parent)
    , ui(new Ui::game)
    , difficulty(difficulty)
{
    ui->setupUi(this);
    connect(this, &game::finished, this, [this](){
        emit openMainMenu();
    });

    //easy recall of buttons to grids
    buttonUIs = {{1, ui->grid1},
                 {2, ui->grid2}};
}

game::~game()
{
    delete ui;
}

void game::on_QuitBtn_clicked()
{
    this->close();
}


void game::on_QuitAllBtn_clicked()
{
    qApp->exit();
}

