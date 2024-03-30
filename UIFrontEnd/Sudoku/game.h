#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <vector>
#include <set>
#include <QCloseEvent>
#include "../../source/sudoku.h"
#include "victoryscreen.h"

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

    virtual void closeEvent (QCloseEvent *event) override;

    void on_grid1_clicked();

    void on_grid2_clicked();

    void on_grid3_clicked();

    void on_grid4_clicked();

    void on_grid5_clicked();

    void on_grid6_clicked();

    void on_grid7_clicked();

    void on_grid8_clicked();

    void on_grid9_clicked();

    void on_grid10_clicked();

    void on_grid11_clicked();

    void on_grid12_clicked();

    void on_grid13_clicked();

    void on_grid14_clicked();

    void on_grid15_clicked();

    void on_grid16_clicked();

    void on_grid17_clicked();

    void on_grid18_clicked();

    void on_grid19_clicked();

    void on_grid20_clicked();

    void on_grid21_clicked();

    void on_grid22_clicked();

    void on_grid23_clicked();

    void on_grid24_clicked();

    void on_grid25_clicked();

    void on_grid26_clicked();

    void on_grid27_clicked();

    void on_grid28_clicked();

    void on_grid29_clicked();

    void on_grid30_clicked();

    void on_grid31_clicked();

    void on_grid32_clicked();

    void on_grid33_clicked();

    void on_grid34_clicked();

    void on_grid35_clicked();

    void on_grid36_clicked();

    void on_grid37_clicked();

    void on_grid38_clicked();

    void on_grid39_clicked();

    void on_grid40_clicked();

    void on_grid41_clicked();

    void on_grid42_clicked();

    void on_grid43_clicked();

    void on_grid44_clicked();

    void on_grid45_clicked();

    void on_grid46_clicked();

    void on_grid47_clicked();

    void on_grid48_clicked();

    void on_grid49_clicked();

    void on_grid50_clicked();

    void on_grid51_clicked();

    void on_grid52_clicked();

    void on_grid53_clicked();

    void on_grid54_clicked();

    void on_grid55_clicked();

    void on_grid56_clicked();

    void on_grid57_clicked();

    void on_grid58_clicked();

    void on_grid59_clicked();

    void on_grid60_clicked();

    void on_grid61_clicked();

    void on_grid62_clicked();

    void on_grid63_clicked();

    void on_grid64_clicked();

    void on_grid65_clicked();

    void on_grid66_clicked();

    void on_grid67_clicked();

    void on_grid68_clicked();

    void on_grid69_clicked();

    void on_grid70_clicked();

    void on_grid71_clicked();

    void on_grid72_clicked();

    void on_grid73_clicked();

    void on_grid74_clicked();

    void on_grid75_clicked();

    void on_grid76_clicked();

    void on_grid77_clicked();

    void on_grid78_clicked();

    void on_grid79_clicked();

    void on_grid80_clicked();

    void on_grid81_clicked();

private:
    void createGame(SudokuBoard &mainGame, unsigned difficulty);

    void getGridNum(int** board, int gridNumber);

    void deactivateLockedGrids();

    void deactivateNumBtns();

    void activateNumBtns();

    void boardIsSolved();

    void markGridErrors();

    void eraseErrorMarks();

    void resetCurrBtn();

    void activateBtn(int gridNumber);

    void changeCurrGridInt(int value);

    Ui::game *ui;

    SudokuBoard mainGame;
    unsigned int difficulty;
    std::vector<QPushButton*> gridButtonUIs;
    std::vector<QPushButton*> numButtonUIs;
    int currentGrid = 0;
    bool solved = true;
    bool showErrors = false;
    std::set<int> lockedGrids;
    std::set<int> wrongGrids;

    std::unique_ptr<VictoryScreen> winScrn = nullptr;
};

#endif // GAME_H
