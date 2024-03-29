#include "sudokumainwindow.h"
#include "ui_sudokumainwindow.h"

SudokuMainWindow::SudokuMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SudokuMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Menu");

    //for easy recall reset of current button values
    diffValues = {{1, ui->VEasyBtn},
                  {2, ui->EasyBtn},
                  {3, ui->MedBtn},
                  {4, ui->HardBtn},
                  {5, ui->EvilBtn}};

    //sets the loading label to invisible to allow the user to press the button
    ui->loadingGifAnim->setVisible(false);

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
    //including concurrent library so the loading screen AND the sudoku builder can run at the same time (really cool library)
    //sets up loading screen
    std::unique_ptr<QMovie> loadingScrn(new QMovie(QCoreApplication::applicationDirPath() + "../../loadingGif/loading.gif")); //creates the UI of the loading screen
    ui->loadingGifAnim->setMovie(loadingScrn.get());
    ui->loadingGifAnim->setVisible(true);
    ui->loadingGifAnim->raise();
    loadingScrn->start();

    //closing loading screen as soon as the game window is ready
    gameWindow = std::unique_ptr<game>(new game(this, difficulty));
    gameWindow->show();
    this->hide();

    connect(gameWindow.get(), &game::openMainMenu, this, &SudokuMainWindow::showWindow);

    ui->loadingGifAnim->setVisible(false);
    loadingScrn->stop();
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
    btn->setAutoFillBackground(false);
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


void SudokuMainWindow::on_MedBtn_clicked()
{
    if (difficulty != 3) {
        reset_Btn();

        difficulty = 3;
        QPushButton* btn = ui->MedBtn;

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::yellow));
        btn->setAutoFillBackground(true);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}


void SudokuMainWindow::on_HardBtn_clicked()
{
    if (difficulty != 4) {
        reset_Btn();

        difficulty = 4;
        QPushButton* btn = ui->HardBtn;

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::red));
        btn->setAutoFillBackground(true);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}


void SudokuMainWindow::on_EvilBtn_clicked()
{
    if (difficulty != 5) {
        reset_Btn();

        difficulty = 5;
        QPushButton* btn = ui->EvilBtn;

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkRed));
        btn->setAutoFillBackground(true);
        btn->setPalette(btnPalette);
        btn->setFlat(true);
        btn->update();
    }
}

