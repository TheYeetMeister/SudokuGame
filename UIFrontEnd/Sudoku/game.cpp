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

void game::resetPrevBtn() {
    if (currentGrid != 0) {
        QPushButton* btn = buttonUIs[currentGrid];

        QPalette btnPalette = QApplication::palette(btn);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}


void game::on_grid1_clicked()
{
    if (currentGrid != 0 && currentGrid != 1) {
        currentGrid = 1;


    }
}

