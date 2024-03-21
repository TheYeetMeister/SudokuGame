#include "sudokumainwindow.h"
#include "ui_sudokumainwindow.h"

SudokuMainWindow::SudokuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SudokuMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");
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
}


void SudokuMainWindow::on_QuitBtn_clicked()
{
    this->close();
}

