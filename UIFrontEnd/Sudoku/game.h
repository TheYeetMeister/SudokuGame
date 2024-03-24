#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <unordered_map>

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

private:
    void resetPrevBtn();

    void activateBtn(int gridNumber);

    Ui::game *ui;

    unsigned int difficulty;
    std::unordered_map<int, QPushButton*> buttonUIs;
    int currentGrid = 0;
};

#endif // GAME_H
