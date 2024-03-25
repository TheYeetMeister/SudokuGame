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

    wrongGrids = {2};

    //easy recall of buttons to grids
    gridButtonUIs = {ui->grid1, ui->grid2, ui->grid3, ui->grid4, ui->grid5, ui->grid6, ui->grid7, ui->grid8, ui->grid9};

    numButtonUIs = {ui->eraseBtn,
                    ui->numOneBtn,
                    ui->numTwoBtn,
                    ui->numThreeBtn,
                    ui->numFourBtn,
                    ui->numFiveBtn,
                    ui->numSixBtn,
                    ui->numSevenBtn,
                    ui->numEightBtn,
                    ui->numNineBtn};

    ui->remErrorsBtn->setEnabled(false);
    deactivateNumBtns();
    deactivateLockedGrids();

    ui->newGameBtn->setVisible(false);
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

void game::on_newGameBtn_clicked()
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

        btn->setEnabled(false);
    }

    deactivateNumBtns();
}

void game::markGridErrors(bool showErrors) {
    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        if (!showErrors && *i == currentGrid) {
            continue;
        }

        QPushButton* btn = gridButtonUIs[*i - 1];
        QPalette btnPalette = btn->palette();

        if (showErrors) {
            btnPalette.setColor(QPalette::Button, QColor(Qt::red));
        } else {
            btnPalette.setColor(QPalette::Button, QColor(Qt::white));
        }

        btn->setPalette(btnPalette);
        btn->update();
    }
}

void game::changeCurrGridInt(int value) {
    if (currentGrid != 0) {
        QPushButton* btn = gridButtonUIs[currentGrid - 1];

        if (value) {
            btn->setText(QString::number(value));
        } else {
            btn->setText("");
        }
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

void game::resetCurrBtn() {
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

void game::on_eraseBtn_clicked()
{
    changeCurrGridInt(0);
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
    resetCurrBtn();
    deactivateNumBtns();

    if (solved) {
        boardIsSolved();
        ui->remErrorsBtn->setEnabled(false);
        ui->submitBtn->setEnabled(false);
        ui->QuitBtn->setEnabled(false);
        ui->newGameBtn->setVisible(true);
    } else {
        currentGrid = 0;
        showErrors = true;
        markGridErrors(true);
        ui->remErrorsBtn->setEnabled(true);
    }
}

void game::on_remErrorsBtn_clicked()
{
    showErrors = false;
    markGridErrors(false);
    ui->remErrorsBtn->setEnabled(false);
}

void game::on_grid1_clicked()
{
    if (currentGrid != 1) {
        resetCurrBtn();

        currentGrid = 1;

        activateBtn(1);
    }
}


void game::on_grid2_clicked()
{
    if (currentGrid != 2) {
        resetCurrBtn();

        currentGrid = 2;

        activateBtn(2);
    }
}

void game::on_grid3_clicked()
{
    if (currentGrid != 3) {
        resetCurrBtn();

        currentGrid = 3;

        activateBtn(3);
    }
}


void game::on_grid4_clicked()
{
    if (currentGrid != 4) {
        resetCurrBtn();

        currentGrid = 4;

        activateBtn(4);
    }
}


void game::on_grid5_clicked()
{
    if (currentGrid != 5) {
        resetCurrBtn();

        currentGrid = 5;

        activateBtn(5);
    }
}


void game::on_grid6_clicked()
{
    if (currentGrid != 6) {
        resetCurrBtn();

        currentGrid = 6;

        activateBtn(6);
    }
}


void game::on_grid7_clicked()
{
    if (currentGrid != 7) {
        resetCurrBtn();

        currentGrid = 7;

        activateBtn(7);
    }
}


void game::on_grid8_clicked()
{
    if (currentGrid != 8) {
        resetCurrBtn();

        currentGrid = 8;

        activateBtn(8);
    }
}


void game::on_grid9_clicked()
{
    if (currentGrid != 9) {
        resetCurrBtn();

        currentGrid = 9;

        activateBtn(9);
    }
}

