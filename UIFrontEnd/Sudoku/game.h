#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <vector>

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent, unsigned difficulty);
    ~game();

signals:
    void openMainMenu();

private slots:
    void on_QuitBtn_clicked();

    void on_QuitAllBtn_clicked();

    void on_grid1_clicked();

    void on_grid2_clicked();

    void on_numOneBtn_clicked();

    void on_numTwoBtn_clicked();

    void on_numThreeBtn_clicked();

    void on_numFourBtn_clicked();

    void on_numFiveBtn_clicked();

    void on_numSixBtn_clicked();

    void on_numSevenBtn_clicked();

    void on_numEightBtn_clicked();

    void on_numNineBtn_clicked();

    void on_submitBtn_clicked();

private:
    void deactivateNumBtns();

    void resetPrevBtn();

    void activateBtn(int gridNumber);

    void changeCurrGridInt(int value);

    Ui::game *ui;

    unsigned int difficulty;
    std::vector<QPushButton*> buttonUIs;
    std::vector<QPushButton*> numButtonUIs;
    int currentGrid = 0;
    bool solved = false;
};

#endif // GAME_H
