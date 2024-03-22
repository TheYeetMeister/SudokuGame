#include "sudokumainwindow.h"
#include "ui_sudokumainwindow.h"

SudokuMainWindow::SudokuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SudokuMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");

    diffValues[1] = ui->VEasyBtn;
    diffValues[2] = ui->EasyBtn;
    diffValues[3] = ui->MedBtn;
    diffValues[4] = ui->HardBtn;
    diffValues[5] = ui->EvilBtn;

    //sets color of btn
    QPalette btn = ui->VEasyBtn->palette();
    btn.setColor(QPalette::Button, QColor(Qt::green));
    ui->VEasyBtn->setAutoFillBackground(true);
    ui->VEasyBtn->setPalette(btn);
    ui->VEasyBtn->setFlat(true);
    ui->VEasyBtn->update();
}

SudokuMainWindow::~SudokuMainWindow()
{
    delete ui;
}

void SudokuMainWindow::on_StartBtn_clicked()
{
    gameWindow = std::unique_ptr<game>(new game(this, "Easy"));
    gameWindow->show();
    this->hide();

    connect(gameWindow.get(), &game::openMainMenu, this, &SudokuMainWindow::showWindow);
}


void SudokuMainWindow::on_QuitBtn_clicked()
{
    this->close();
}

void SudokuMainWindow::showWindow() {
    this->show();
}

void SudokuMainWindow::reset_Btn() {
    QPushButton* btn = diffValues[difficulty];

    QPalette btnPalette = QApplication::palette(btn);
    btn->setPalette(btnPalette);
    btn->setFlat(false);
    btn->update();
}

void SudokuMainWindow::on_VEasyBtn_clicked()
{
    if (difficulty != 1) {
        reset_Btn();

        difficulty = 1;
        QPushButton* btn = ui->VEasyBtn;

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::green));
        btn->setAutoFillBackground(true);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}


void SudokuMainWindow::on_EasyBtn_clicked()
{
    if (difficulty != 2) {
        reset_Btn();

        difficulty = 2;
        QPushButton* btn = ui->EasyBtn;

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGreen));
        btn->setAutoFillBackground(true);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}

