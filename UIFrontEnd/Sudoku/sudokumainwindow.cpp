#include "sudokumainwindow.h"
#include "ui_sudokumainwindow.h"

SudokuMainWindow::SudokuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SudokuMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");

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
