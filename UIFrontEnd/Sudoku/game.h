#ifndef GAME_H
#define GAME_H

#include <QDialog>

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

private:
    Ui::game *ui;
};

#endif // GAME_H
