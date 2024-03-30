#include "game.h"
#include "ui_game.h"


constexpr double VERYEASY_PERCENTAGE_MISSING = 0.50;
constexpr double EASY_PERCENTAGE_MISSING = 0.54;
constexpr double MEDIUM_PERCENTAGE_MISSING = 0.62;
constexpr double HARD_PERCENTAGE_MISSING = 0.70;
constexpr double EVIL_PERCENTAGE_MISSING = 0.75;

game::game(QWidget *parent, unsigned difficulty)
    : QDialog(parent)
    , ui(new Ui::game)
    , difficulty(difficulty)
{
    ui->setupUi(this);
    this->setWindowTitle("Sudoku");

    //easy recall of buttons to grids
    gridButtonUIs = {ui->grid1, ui->grid2, ui->grid3, ui->grid4, ui->grid5, ui->grid6, ui->grid7, ui->grid8, ui->grid9,
                    ui->grid10, ui->grid11, ui->grid12, ui->grid13, ui->grid14, ui->grid15, ui->grid16, ui->grid17, ui->grid18,
                    ui->grid19, ui->grid20, ui->grid21, ui->grid22, ui->grid23, ui->grid24, ui->grid25, ui->grid26, ui->grid27,
                    ui->grid28, ui->grid29, ui->grid30, ui->grid31, ui->grid32, ui->grid33, ui->grid34, ui->grid35, ui->grid36,
                    ui->grid37, ui->grid38, ui->grid39, ui->grid40, ui->grid41, ui->grid42, ui->grid43, ui->grid44, ui->grid45,
                    ui->grid46, ui->grid47, ui->grid48, ui->grid49, ui->grid50, ui->grid51, ui->grid52, ui->grid53, ui->grid54,
                    ui->grid55, ui->grid56, ui->grid57, ui->grid58, ui->grid59, ui->grid60, ui->grid61, ui->grid62, ui->grid63,
                    ui->grid64, ui->grid65, ui->grid66, ui->grid67, ui->grid68, ui->grid69, ui->grid70, ui->grid71, ui->grid72,
                    ui->grid73, ui->grid74, ui->grid75, ui->grid76, ui->grid77, ui->grid78, ui->grid79, ui->grid80, ui->grid81};

    numButtonUIs = {ui->eraseBtn,
                    ui->numOneBtn,
                    ui->numTwoBtn,
                    ui->numThreeBtn,
                    ui->numFourBtn,
                    ui->numFiveBtn,
                    ui->numSixBtn,
                    ui->numSevenBtn,
                    ui->numEightBtn,
                    ui->numNineBtn};

    ui->remErrorsBtn->setEnabled(false);

    ui->newGameBtn->setVisible(false);

    //call game creation (yay!)
    mainGame = SudokuBoard(3);

    createGame(mainGame, difficulty);

    //set anchored grids and their values
    lockedGrids = mainGame.getAnchoredcoor();
    int** board = mainGame.getGameBoard();

    for (auto it = lockedGrids.begin(); it != lockedGrids.end(); ++it) {
        getGridNum(board, *it);
    }

    //sets font color for buttons to black for dark mode users
    for (QPushButton* btn: gridButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::ButtonText, QColor(Qt::black));
        btn->setPalette(btnPalette);
        btn->update();
    }

    deactivateNumBtns();
    deactivateLockedGrids();
}

game::~game()
{
    if (winScrn) {
        winScrn->close();
    }

    delete ui;
}
void game::createGame(SudokuBoard &mainGame, unsigned difficulty) {
    switch(difficulty) {
        case 1:
            mainGame.generateNewPlayableBoard(VERYEASY_PERCENTAGE_MISSING, 5, 2);
            break;

        case 2:
            mainGame.generateNewPlayableBoard(EASY_PERCENTAGE_MISSING, 4, 2);
            break;

        case 3:
            mainGame.generateNewPlayableBoard(MEDIUM_PERCENTAGE_MISSING, 3, 1);
            break;

        case 4:
            mainGame.generateNewPlayableBoard(HARD_PERCENTAGE_MISSING, 2, 1);
            break;

        case 5:
            mainGame.generateNewPlayableBoard(EVIL_PERCENTAGE_MISSING);
            break;

        default:
            throw std::invalid_argument("invalid selected difficulty");
    }
}

void game::getGridNum(int** board, int gridNumber) {
    int row = gridNumber / 9;
    int col = gridNumber % 9;

    int num = board[row][col];

    QPushButton* btn = gridButtonUIs[gridNumber];
    btn->setText(QString::number(num));
}

void game::deactivateLockedGrids() {
    for (auto it = lockedGrids.begin(); it != lockedGrids.end(); ++it) {
        QPushButton* btn = gridButtonUIs[*it];

        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGray));
        btnPalette.setColor(QPalette::ButtonText, QColor(Qt::white));
        btn->setPalette(btnPalette);
        btn->update();

        btn->setEnabled(false);
    }
}

void game::deactivateNumBtns() {
    for (QPushButton* btn :numButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::darkGray));
        btn->setPalette(btnPalette);
        btn->update();

        btn->setEnabled(false);
    }
}

void game::activateNumBtns() {
    for (QPushButton* btn :numButtonUIs) {
        btn->setPalette(QApplication::palette(btn));
        btn->update();

        btn->setEnabled(true);
    }
}

void game::on_QuitBtn_clicked()
{
    this->close();
}

void game::on_newGameBtn_clicked()
{
    this->close();
}


void game::on_QuitAllBtn_clicked()
{
    qApp->exit();
}

void game::boardIsSolved() {
    for (QPushButton* btn :gridButtonUIs) {
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::green));
        btnPalette.setColor(QPalette::ButtonText, QColor(Qt::black));
        btn->setPalette(btnPalette);
        btn->update();

        btn->setEnabled(false);
    }

    deactivateNumBtns();
}

void game::markGridErrors() {
    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        QPushButton* btn = gridButtonUIs[*i];
        QPalette btnPalette = btn->palette();
        btnPalette.setColor(QPalette::Button, QColor(Qt::red));
        btn->setPalette(btnPalette);
        btn->update();
    }
}

void game::eraseErrorMarks() {
    auto anchoredIter = lockedGrids.begin();
    for(int i = 0; i < 81; ++i) {
        if (anchoredIter == lockedGrids.end() || i < *anchoredIter) {
            QPushButton* btn = gridButtonUIs[i];
            QPalette btnPalette = btn->palette();
            btnPalette.setColor(QPalette::Button, QColor(Qt::white));
            btn->setPalette(btnPalette);
            btn->update();
        } else {
            ++anchoredIter;
        }
    }
}

void game::changeCurrGridInt(int value) {
    if (currentGrid != 0) {
        QPushButton* btn = gridButtonUIs[currentGrid - 1];

        if (value) {
            btn->setText(QString::number(value));
            mainGame.playerInsertNumber(value, (currentGrid - 1) / 9 + 1, (currentGrid - 1) % 9 + 1);
        } else {
            btn->setText("");
            mainGame.playerRemoveNumber((currentGrid - 1) / 9 + 1, (currentGrid - 1) % 9 + 1);
        }
    }
}

void game::activateBtn(int gridNumber) {
    activateNumBtns();

    QPushButton* btn = gridButtonUIs[gridNumber - 1];

    QPalette btnPalette = btn->palette();
    btnPalette.setColor(QPalette::Button, QColor(Qt::cyan));
    btn->setPalette(btnPalette);
    btn->update();
}

void game::resetCurrBtn() {
    if (currentGrid != 0 ) {
        QPushButton* btn = gridButtonUIs[currentGrid - 1];

        QPalette btnPalette = btn->palette();

        if (showErrors && wrongGrids.find(currentGrid - 1) != wrongGrids.end()) {
            btnPalette.setColor(QPalette::Button, QColor(Qt::red));
        } else {
            btnPalette.setColor(QPalette::Button, QColor(Qt::white));
        }

        btn->setPalette(btnPalette);
        btn->update();
    }
}

void game::on_eraseBtn_clicked()
{
    changeCurrGridInt(0);
}

void game::on_numOneBtn_clicked()
{
    changeCurrGridInt(1);
}


void game::on_numTwoBtn_clicked()
{
    changeCurrGridInt(2);
}


void game::on_numThreeBtn_clicked()
{
    changeCurrGridInt(3);
}


void game::on_numFourBtn_clicked()
{
    changeCurrGridInt(4);
}


void game::on_numFiveBtn_clicked()
{
    changeCurrGridInt(5);
}


void game::on_numSixBtn_clicked()
{
    changeCurrGridInt(6);
}


void game::on_numSevenBtn_clicked()
{
    changeCurrGridInt(7);
}


void game::on_numEightBtn_clicked()
{
    changeCurrGridInt(8);
}


void game::on_numNineBtn_clicked()
{
    changeCurrGridInt(9);
}


void game::on_submitBtn_clicked()
{
    resetCurrBtn();
    deactivateNumBtns();
    currentGrid = 0;
    //solved = mainGame.isTheWholeBoardSolved();

    if (solved) {
        boardIsSolved();
        ui->remErrorsBtn->setEnabled(false);
        ui->submitBtn->setEnabled(false);
        ui->QuitBtn->setEnabled(false);
        ui->newGameBtn->setVisible(true);

        //shows victory screen, saves the ptr in a class ptr
        winScrn = std::unique_ptr<VictoryScreen>(new VictoryScreen(this, difficulty));
        winScrn->show();
    } else {
        eraseErrorMarks();
        wrongGrids = mainGame.getAllWrongGrids();
        showErrors = true;
        markGridErrors();
        ui->remErrorsBtn->setEnabled(true);
    }
}

void game::on_remErrorsBtn_clicked()
{
    showErrors = false;
    eraseErrorMarks();
    ui->remErrorsBtn->setEnabled(false);
}

void game::closeEvent (QCloseEvent *event) {
    if (winScrn) {
        winScrn->close();
    }
    emit openMainMenu();
    event->accept();
}

void game::on_grid1_clicked()
{
    if (currentGrid != 1) {
        resetCurrBtn();

        currentGrid = 1;

        activateBtn(1);
    }
}


void game::on_grid2_clicked()
{
    if (currentGrid != 2) {
        resetCurrBtn();

        currentGrid = 2;

        activateBtn(2);
    }
}

void game::on_grid3_clicked()
{
    if (currentGrid != 3) {
        resetCurrBtn();

        currentGrid = 3;

        activateBtn(3);
    }
}


void game::on_grid4_clicked()
{
    if (currentGrid != 4) {
        resetCurrBtn();

        currentGrid = 4;

        activateBtn(4);
    }
}


void game::on_grid5_clicked()
{
    if (currentGrid != 5) {
        resetCurrBtn();

        currentGrid = 5;

        activateBtn(5);
    }
}


void game::on_grid6_clicked()
{
    if (currentGrid != 6) {
        resetCurrBtn();

        currentGrid = 6;

        activateBtn(6);
    }
}


void game::on_grid7_clicked()
{
    if (currentGrid != 7) {
        resetCurrBtn();

        currentGrid = 7;

        activateBtn(7);
    }
}


void game::on_grid8_clicked()
{
    if (currentGrid != 8) {
        resetCurrBtn();

        currentGrid = 8;

        activateBtn(8);
    }
}


void game::on_grid9_clicked()
{
    if (currentGrid != 9) {
        resetCurrBtn();

        currentGrid = 9;

        activateBtn(9);
    }
}


void game::on_grid10_clicked()
{
    if (currentGrid != 10) {
        resetCurrBtn();

        currentGrid = 10;

        activateBtn(10);
    }
}


void game::on_grid11_clicked()
{
    if (currentGrid != 11) {
        resetCurrBtn();

        currentGrid = 11;

        activateBtn(11);
    }
}


void game::on_grid12_clicked()
{
    if (currentGrid != 12) {
        resetCurrBtn();

        currentGrid = 12;

        activateBtn(12);
    }
}


void game::on_grid13_clicked()
{
    if (currentGrid != 13) {
        resetCurrBtn();

        currentGrid = 13;

        activateBtn(13);
    }
}


void game::on_grid14_clicked()
{
    if (currentGrid != 14) {
        resetCurrBtn();

        currentGrid = 14;

        activateBtn(14);
    }
}


void game::on_grid15_clicked()
{
    if (currentGrid != 15) {
        resetCurrBtn();

        currentGrid = 15;

        activateBtn(15);
    }
}


void game::on_grid16_clicked()
{
    if (currentGrid != 16) {
        resetCurrBtn();

        currentGrid = 16;

        activateBtn(16);
    }
}


void game::on_grid17_clicked()
{
    if (currentGrid != 17) {
        resetCurrBtn();

        currentGrid = 17;

        activateBtn(17);
    }
}


void game::on_grid18_clicked()
{
    if (currentGrid != 18) {
        resetCurrBtn();

        currentGrid = 18;

        activateBtn(18);
    }
}


void game::on_grid19_clicked()
{
    if (currentGrid != 19) {
        resetCurrBtn();

        currentGrid = 19;

        activateBtn(19);
    }
}


void game::on_grid20_clicked()
{
    if (currentGrid != 20) {
        resetCurrBtn();

        currentGrid = 20;

        activateBtn(20);
    }
}


void game::on_grid21_clicked()
{
    if (currentGrid != 21) {
        resetCurrBtn();

        currentGrid = 21;

        activateBtn(21);
    }
}


void game::on_grid22_clicked()
{
    if (currentGrid != 22) {
        resetCurrBtn();

        currentGrid = 22;

        activateBtn(22);
    }
}


void game::on_grid23_clicked()
{
    if (currentGrid != 23) {
        resetCurrBtn();

        currentGrid = 23;

        activateBtn(23);
    }
}


void game::on_grid24_clicked()
{
    if (currentGrid != 24) {
        resetCurrBtn();

        currentGrid = 24;

        activateBtn(24);
    }
}


void game::on_grid25_clicked()
{
    if (currentGrid != 25) {
        resetCurrBtn();

        currentGrid = 25;

        activateBtn(25);
    }
}


void game::on_grid26_clicked()
{
    if (currentGrid != 26) {
        resetCurrBtn();

        currentGrid = 26;

        activateBtn(26);
    }
}


void game::on_grid27_clicked()
{
    if (currentGrid != 27) {
        resetCurrBtn();

        currentGrid = 27;

        activateBtn(27);
    }
}


void game::on_grid28_clicked()
{
    if (currentGrid != 28) {
        resetCurrBtn();

        currentGrid = 28;

        activateBtn(28);
    }
}


void game::on_grid29_clicked()
{
    if (currentGrid != 29) {
        resetCurrBtn();

        currentGrid = 29;

        activateBtn(29);
    }
}


void game::on_grid30_clicked()
{
    if (currentGrid != 30) {
        resetCurrBtn();

        currentGrid = 30;

        activateBtn(30);
    }
}


void game::on_grid31_clicked()
{
    if (currentGrid != 31) {
        resetCurrBtn();

        currentGrid = 31;

        activateBtn(31);
    }
}


void game::on_grid32_clicked()
{
    if (currentGrid != 32) {
        resetCurrBtn();

        currentGrid = 32;

        activateBtn(32);
    }
}


void game::on_grid33_clicked()
{
    if (currentGrid != 33) {
        resetCurrBtn();

        currentGrid = 33;

        activateBtn(33);
    }
}


void game::on_grid34_clicked()
{
    if (currentGrid != 34) {
        resetCurrBtn();

        currentGrid = 34;

        activateBtn(34);
    }
}


void game::on_grid35_clicked()
{
    if (currentGrid != 35) {
        resetCurrBtn();

        currentGrid = 35;

        activateBtn(35);
    }
}


void game::on_grid36_clicked()
{
    if (currentGrid != 36) {
        resetCurrBtn();

        currentGrid = 36;

        activateBtn(36);
    }
}


void game::on_grid37_clicked()
{
    if (currentGrid != 37) {
        resetCurrBtn();

        currentGrid = 37;

        activateBtn(37);
    }
}


void game::on_grid38_clicked()
{
    if (currentGrid != 38) {
        resetCurrBtn();

        currentGrid = 38;

        activateBtn(38);
    }
}


void game::on_grid39_clicked()
{
    if (currentGrid != 39) {
        resetCurrBtn();

        currentGrid = 39;

        activateBtn(39);
    }
}


void game::on_grid40_clicked()
{
    if (currentGrid != 40) {
        resetCurrBtn();

        currentGrid = 40;

        activateBtn(40);
    }
}


void game::on_grid41_clicked()
{
    if (currentGrid != 41) {
        resetCurrBtn();

        currentGrid = 41;

        activateBtn(41);
    }
}


void game::on_grid42_clicked()
{
    if (currentGrid != 42) {
        resetCurrBtn();

        currentGrid = 42;

        activateBtn(42);
    }
}


void game::on_grid43_clicked()
{
    if (currentGrid != 43) {
        resetCurrBtn();

        currentGrid = 43;

        activateBtn(43);
    }
}


void game::on_grid44_clicked()
{
    if (currentGrid != 44) {
        resetCurrBtn();

        currentGrid = 44;

        activateBtn(44);
    }
}


void game::on_grid45_clicked()
{
    if (currentGrid != 45) {
        resetCurrBtn();

        currentGrid = 45;

        activateBtn(45);
    }
}


void game::on_grid46_clicked()
{
    if (currentGrid != 46) {
        resetCurrBtn();

        currentGrid = 46;

        activateBtn(46);
    }
}


void game::on_grid47_clicked()
{
    if (currentGrid != 47) {
        resetCurrBtn();

        currentGrid = 47;

        activateBtn(47);
    }
}


void game::on_grid48_clicked()
{
    if (currentGrid != 48) {
        resetCurrBtn();

        currentGrid = 48;

        activateBtn(48);
    }
}


void game::on_grid49_clicked()
{
    if (currentGrid != 49) {
        resetCurrBtn();

        currentGrid = 49;

        activateBtn(49);
    }
}


void game::on_grid50_clicked()
{
    if (currentGrid != 50) {
        resetCurrBtn();

        currentGrid = 50;

        activateBtn(50);
    }
}


void game::on_grid51_clicked()
{
    if (currentGrid != 51) {
        resetCurrBtn();

        currentGrid = 51;

        activateBtn(51);
    }
}


void game::on_grid52_clicked()
{
    if (currentGrid != 52) {
        resetCurrBtn();

        currentGrid = 52;

        activateBtn(52);
    }
}


void game::on_grid53_clicked()
{
    if (currentGrid != 53) {
        resetCurrBtn();

        currentGrid = 53;

        activateBtn(53);
    }
}


void game::on_grid54_clicked()
{
    if (currentGrid != 54) {
        resetCurrBtn();

        currentGrid = 54;

        activateBtn(54);
    }
}


void game::on_grid55_clicked()
{
    if (currentGrid != 55) {
        resetCurrBtn();

        currentGrid = 55;

        activateBtn(55);
    }
}


void game::on_grid56_clicked()
{
    if (currentGrid != 56) {
        resetCurrBtn();

        currentGrid = 56;

        activateBtn(56);
    }
}


void game::on_grid57_clicked()
{
    if (currentGrid != 57) {
        resetCurrBtn();

        currentGrid = 57;

        activateBtn(57);
    }
}


void game::on_grid58_clicked()
{
    if (currentGrid != 58) {
        resetCurrBtn();

        currentGrid = 58;

        activateBtn(58);
    }
}


void game::on_grid59_clicked()
{
    if (currentGrid != 59) {
        resetCurrBtn();

        currentGrid = 59;

        activateBtn(59);
    }
}


void game::on_grid60_clicked()
{
    if (currentGrid != 60) {
        resetCurrBtn();

        currentGrid = 60;

        activateBtn(60);
    }
}


void game::on_grid61_clicked()
{
    if (currentGrid != 61) {
        resetCurrBtn();

        currentGrid = 61;

        activateBtn(61);
    }
}


void game::on_grid62_clicked()
{
    if (currentGrid != 62) {
        resetCurrBtn();

        currentGrid = 62;

        activateBtn(62);
    }
}


void game::on_grid63_clicked()
{
    if (currentGrid != 63) {
        resetCurrBtn();

        currentGrid = 63;

        activateBtn(63);
    }
}


void game::on_grid64_clicked()
{
    if (currentGrid != 64) {
        resetCurrBtn();

        currentGrid = 64;

        activateBtn(64);
    }
}


void game::on_grid65_clicked()
{
    if (currentGrid != 65) {
        resetCurrBtn();

        currentGrid = 65;

        activateBtn(65);
    }
}


void game::on_grid66_clicked()
{
    if (currentGrid != 66) {
        resetCurrBtn();

        currentGrid = 66;

        activateBtn(66);
    }
}


void game::on_grid67_clicked()
{
    if (currentGrid != 67) {
        resetCurrBtn();

        currentGrid = 67;

        activateBtn(67);
    }
}


void game::on_grid68_clicked()
{
    if (currentGrid != 68) {
        resetCurrBtn();

        currentGrid = 68;

        activateBtn(68);
    }
}


void game::on_grid69_clicked()
{
    if (currentGrid != 69) {
        resetCurrBtn();

        currentGrid = 69;

        activateBtn(69);
    }
}


void game::on_grid70_clicked()
{
    if (currentGrid != 70) {
        resetCurrBtn();

        currentGrid = 70;

        activateBtn(70);
    }
}


void game::on_grid71_clicked()
{
    if (currentGrid != 71) {
        resetCurrBtn();

        currentGrid = 71;

        activateBtn(71);
    }
}


void game::on_grid72_clicked()
{
    if (currentGrid != 72) {
        resetCurrBtn();

        currentGrid = 72;

        activateBtn(72);
    }
}


void game::on_grid73_clicked()
{
    if (currentGrid != 73) {
        resetCurrBtn();

        currentGrid = 73;

        activateBtn(73);
    }
}


void game::on_grid74_clicked()
{
    if (currentGrid != 74) {
        resetCurrBtn();

        currentGrid = 74;

        activateBtn(74);
    }
}


void game::on_grid75_clicked()
{
    if (currentGrid != 75) {
        resetCurrBtn();

        currentGrid = 75;

        activateBtn(75);
    }
}


void game::on_grid76_clicked()
{
    if (currentGrid != 76) {
        resetCurrBtn();

        currentGrid = 76;

        activateBtn(76);
    }
}


void game::on_grid77_clicked()
{
    if (currentGrid != 77) {
        resetCurrBtn();

        currentGrid = 77;

        activateBtn(77);
    }
}


void game::on_grid78_clicked()
{
    if (currentGrid != 78) {
        resetCurrBtn();

        currentGrid = 78;

        activateBtn(78);
    }
}


void game::on_grid79_clicked()
{
    if (currentGrid != 79) {
        resetCurrBtn();

        currentGrid = 79;

        activateBtn(79);
    }
}


void game::on_grid80_clicked()
{
    if (currentGrid != 80) {
        resetCurrBtn();

        currentGrid = 80;

        activateBtn(80);
    }
}


void game::on_grid81_clicked()
{
    if (currentGrid != 81) {
        resetCurrBtn();

        currentGrid = 81;

        activateBtn(81);
    }
}

