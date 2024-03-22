#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent, unsigned difficulty)
    : QDialog(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);

    switch(difficulty) {
        case(1):
            ui->DiffLabel->setText("Very Easy");
            break;

        case(2):
            ui->DiffLabel->setText("Easy");
            break;

        case(3):
            ui->DiffLabel->setText("Medium");
            break;

        case(4):
            ui->DiffLabel->setText("Hard");
            break;

        case(5):
            ui->DiffLabel->setText("Evil");
            break;

        default:
            ui->DiffLabel->setText("Error");
    }

    this->setWindowTitle("Sudoku");

    connect(this, &game::finished, this, [this](){
        emit openMainMenu();
    });
}

game::~game()
{
    delete ui;
}

void game::on_QuitBtn_clicked()
{
    connect(this, &game::finished, this, [this](){
        emit closeWholeGame();
    });

    this->close();
}

