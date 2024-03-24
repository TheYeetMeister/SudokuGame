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

void game::changeCurrGridInt(int value) {
    QPushButton* btn = buttonUIs[currentGrid];

    btn->setText(QString::number(value));
}

void game::activateBtn(int gridNumber) {
    QPushButton* btn = buttonUIs[gridNumber];

    QPalette btnPalette = btn->palette();
    btnPalette.setColor(QPalette::Button, QColor(Qt::cyan));
    btn->setPalette(btnPalette);
    btn->update();
}

void game::resetPrevBtn() {
    if (currentGrid != 0) {
        QPushButton* btn = buttonUIs[currentGrid];

        QPalette btnPalette = QApplication::palette(btn);
        btn->setPalette(btnPalette);
        btn->update();
    }
}


void game::on_grid1_clicked()
{
    if (currentGrid != 1) {
        resetPrevBtn();

        currentGrid = 1;

        activateBtn(1);
    }
}


void game::on_grid2_clicked()
{
    if (currentGrid != 2) {
        resetPrevBtn();

        currentGrid = 2;

        activateBtn(2);
    }
}

