#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent, unsigned difficulty)
    : QDialog(parent)
    , ui(new Ui::game)
    , difficulty(difficulty)
{
    ui->setupUi(this);
    this->setWindowTitle("Sudoku");

    connect(this, &game::finished, this, [this](){
        emit openMainMenu();
    });

    lockedGrids = {3};

    //easy recall of buttons to grids
    gridButtonUIs = {ui->grid1, ui->grid2, ui->grid3};

    numButtonUIs = {ui->numOneBtn,
                    ui->numTwoBtn,
                    ui->numThreeBtn,
                    ui->numFourBtn,
                    ui->numFiveBtn,
                    ui->numSixBtn,
                    ui->numSevenBtn,
                    ui->numEightBtn,
                    ui->numNineBtn};

    deactivateLockedGrids();
}

game::~game()
{
    delete ui;
}

void game::deactivateLockedGrids() {
    for (auto it = lockedGrids.begin(); it != lockedGrids.end(); ++it) {
        QPushButton* btn = gridButtonUIs[*it - 1];

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGray));
        btnPalette.setColor(QPalette::ButtonText, QColor(Qt::white));
        btn->setPalette(btnPalette);
        btn->update();

        btn->setEnabled(false);
    }
}

void game::deactivateNumBtns() {
    for (QPushButton* btn :numButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGray));
        btn->setPalette(btnPalette);
        btn->update();

        btn->setEnabled(false);
    }
}

void game::activateNumBtns() {
    for (QPushButton* btn :numButtonUIs) {
        btn->setPalette(QApplication::palette(btn));
        btn->update();

        btn->setEnabled(true);
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

void game::boardIsSolved() {
    for (QPushButton* btn :gridButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::green));
        btnPalette.setColor(QPalette::ButtonText, QColor(Qt::black));
        btn->setPalette(btnPalette);
        btn->update();
    }

    deactivateNumBtns();
}

void game::changeCurrGridInt(int value) {
    if (currentGrid != 0) {
        QPushButton* btn = gridButtonUIs[currentGrid - 1];

        btn->setText(QString::number(value));
    }
}

void game::activateBtn(int gridNumber) {
    activateNumBtns();

    QPushButton* btn = gridButtonUIs[gridNumber - 1];

    QPalette btnPalette = btn->palette();
    btnPalette.setColor(QPalette::Button, QColor(Qt::cyan));
    btn->setPalette(btnPalette);
    btn->update();
}

void game::resetPrevBtn() {
    if (currentGrid != 0 ) {
        QPushButton* btn = gridButtonUIs[currentGrid - 1];

        QPalette btnPalette = btn->palette();

        if (showErrors && wrongGrids.find(currentGrid) != wrongGrids.end()) {
            btnPalette.setColor(QPalette::Button, QColor(Qt::red));
        } else {
            btnPalette.setColor(QPalette::Button, QColor(Qt::white));
        }

        btn->setPalette(btnPalette);
        btn->update();
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
    if (solved) {
        boardIsSolved();
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

void game::on_grid3_clicked()
{
    if (currentGrid != 3) {
        resetPrevBtn();

        currentGrid = 3;

        activateBtn(3);
    }
}

