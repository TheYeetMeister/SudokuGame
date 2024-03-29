#ifndef SUDOKUMAINWINDOW_H
#define SUDOKUMAINWINDOW_H

#include <QMainWindow>
#include <QSplashScreen>
#include <memory>
#include <unordered_map>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SudokuMainWindow;
}
QT_END_NAMESPACE

class SudokuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SudokuMainWindow(QWidget *parent = nullptr);
    ~SudokuMainWindow();

private slots:
    void reset_Btn();

    void on_StartBtn_clicked();

    void on_QuitBtn_clicked();

    void showWindow();

    void on_VEasyBtn_clicked();

    void on_EasyBtn_clicked();

    void on_MedBtn_clicked();

    void on_HardBtn_clicked();

    void on_EvilBtn_clicked();

private:
    Ui::SudokuMainWindow *ui;
    std::unique_ptr<game> gameWindow;
    //difficulty rated from a scale of 1-5, (Very Easy - Evil)
    unsigned int difficulty = 1;
    std::unordered_map<unsigned int, QPushButton*> diffValues;
};
#endif // SUDOKUMAINWINDOW_H
