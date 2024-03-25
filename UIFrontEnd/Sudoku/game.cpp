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
    buttonUIs = {ui->grid1, ui->grid2};

    numButtonUIs = {ui->numOneBtn,
                    ui->numTwoBtn,
                    ui->numThreeBtn,
                    ui->numFourBtn,
                    ui->numFiveBtn,
                    ui->numSixBtn,
                    ui->numSevenBtn,
                    ui->numEightBtn,
                    ui->numNineBtn};
}

game::~game()
{
    delete ui;
}

void game::deactivateNumBtns() {
    for (QPushButton* btn :numButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGray));
        btn->setPalette(btnPalette);
        btn->update();
    }
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
    if (currentGrid != 0) {
        QPushButton* btn = buttonUIs[currentGrid - 1];

        btn->setText(QString::number(value));
    }
}

void game::activateBtn(int gridNumber) {
    QPushButton* btn = buttonUIs[gridNumber - 1];

    QPalette btnPalette = btn->palette();
    btnPalette.setColor(QPalette::Button, QColor(Qt::cyan));
    btn->setPalette(btnPalette);
    btn->update();
}

void game::resetPrevBtn() {
    if (currentGrid != 0) {
        QPushButton* btn = buttonUIs[currentGrid - 1];

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::white));
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


void game::on_numOneBtn_clicked()
{
    changeCurrGridInt(1);
}


void game::on_numTwoBtn_clicked()
{
    changeCurrGridInt(2);
}


void game::on_numThreeBtn_clicked()
{
    changeCurrGridInt(3);
}


void game::on_numFourBtn_clicked()
{
    changeCurrGridInt(4);
}


void game::on_numFiveBtn_clicked()
{
    changeCurrGridInt(5);
}


void game::on_numSixBtn_clicked()
{
    changeCurrGridInt(6);
}


void game::on_numSevenBtn_clicked()
{
    changeCurrGridInt(7);
}


void game::on_numEightBtn_clicked()
{
    changeCurrGridInt(8);
}


void game::on_numNineBtn_clicked()
{
    changeCurrGridInt(9);
}


void game::on_submitBtn_clicked()
{

}

