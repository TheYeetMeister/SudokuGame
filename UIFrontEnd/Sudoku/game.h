#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <vector>
#include <set>

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

    void on_newGameBtn_clicked();

    void on_QuitAllBtn_clicked();

    void on_eraseBtn_clicked();

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

    void on_remErrorsBtn_clicked();

    void on_grid1_clicked();

    void on_grid2_clicked();

    void on_grid3_clicked();

    void on_grid4_clicked();

    void on_grid5_clicked();

    void on_grid6_clicked();

    void on_grid7_clicked();

    void on_grid8_clicked();

    void on_grid9_clicked();

private:
    void deactivateLockedGrids();

    void deactivateNumBtns();

    void activateNumBtns();

    void boardIsSolved();

    void markGridErrors(bool showErrors);

    void resetCurrBtn();

    void activateBtn(int gridNumber);

    void changeCurrGridInt(int value);

    Ui::game *ui;

    unsigned int difficulty;
    std::vector<QPushButton*> gridButtonUIs;
    std::vector<QPushButton*> numButtonUIs;
    int currentGrid = 0;
    bool solved = true;
    bool showErrors = false;
    std::set<int> lockedGrids;
    std::set<int> wrongGrids;
};

#endif // GAME_H
