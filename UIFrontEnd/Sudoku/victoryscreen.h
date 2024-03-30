#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class VictoryScreen;
}

class VictoryScreen : public QDialog
{
    Q_OBJECT

public:
    explicit VictoryScreen(QWidget *parent, unsigned difficulty);
    ~VictoryScreen();

private:

    unsigned difficulty;
    Ui::VictoryScreen *ui;
};

#endif // VICTORYSCREEN_H
