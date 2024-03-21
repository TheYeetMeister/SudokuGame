#ifndef SUDOKUMAINWINDOW_H
#define SUDOKUMAINWINDOW_H

#include <QMainWindow>
#include <memory>
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
    void on_StartBtn_clicked();

    void on_QuitBtn_clicked();

private:
    Ui::SudokuMainWindow *ui;
    std::unique_ptr<game> gameWindow;
};
#endif // SUDOKUMAINWINDOW_H
