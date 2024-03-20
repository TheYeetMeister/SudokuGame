#ifndef SUDOKUMAINWINDOW_H
#define SUDOKUMAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::SudokuMainWindow *ui;
};
#endif // SUDOKUMAINWINDOW_H
