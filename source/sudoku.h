#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>
#include <set>
#include <string>

class SudokuBoard {
public:
    SudokuBoard(int gridSize = 3);

    //used for testing
    SudokuBoard(int** exampleBoard);

    SudokuBoard(const SudokuBoard &s);

    SudokuBoard &operator=(const SudokuBoard &s);

    SudokuBoard(SudokuBoard &&s);

    SudokuBoard &operator=(SudokuBoard &&s);

    ~SudokuBoard();

    int** getGameBoard();

    std::set<int> getAnchoredcoor();

    int getBoardSize() const;

    void insertAnchoredNumber(int num, int row, int col);

    void playerInsertNumber(int num, int row, int col);

    void playerRemoveNumber(int row, int col);

    void print(std::ostream &out, bool markWrongValues = false) const;

    bool isTheWholeBoardSolved() const;

    std::set<int> getAllWrongGrids() const;
    //solving subfunctions (public for testing purposes)

    bool isConsecutiveSetsSolved(int rowDelta, int colDelta) const;
    bool isSetOfNumbersSolved(int row, int col, int rowDelta, int colDelta) const;

    bool areAllGridsSolved() const;
    bool isSingleGridSolved(int gridRow, int gridCol) const;

    //returning grids with wrong values (public for testing purposes)
    std::set<int> getWrongGridsInConsecutiveSets(int rowDelta, int colDelta) const;
    std::set<int> getWrongGridsInSet(int row, int col, int rowDelta, int colDelta) const;

    std::set<int> getAllWrongGridsInMacroGrids() const;
    std::set<int> getWrongGridsInMacroGrid(int gridRow, int gridCol) const;

    //generating newBoard class (public for testing purposes)

    void generateNewPlayableBoard(double percentageEmpty, int minimumNumOfRowColVals = 0, bool isRandom = false);
private:

    std::string adjustStringSize(const char value) const;

    std::string returnNumberComposition(int num, int gridCoor, bool markWrongValues) const;

    std::string composeNumber(int n) const;

    void printHeader(std::ostream &out) const;

    bool isValueInRange(int value) const;

    void checkRowColVal(int num, int row, int col) const;

    bool isGridAnchored(int row, int col) const;

    int calGridNumber(int row, int col) const;

    int size;
    const int gridSize;
    int** gameBoard;
    std::set<int> anchoredCoor;
    bool madeNotUsingNew;
};

std::ostream &operator<<(std::ostream& out, const SudokuBoard &b);

class GridPositionAlreadyTaken: public std::exception {
public:
    GridPositionAlreadyTaken(const std::string &msg = "") {
        message += msg;
    }

    std::string what() {
        return message;
    }
private:
    std::string message = "Grid Position in board already taken!: ";
};

class ValueOutOfBounds: public std::exception {
public:
    ValueOutOfBounds(const std::string &msg = "") {
        message += msg;
    }

    std::string what() {
        return message;
    }
private:
    std::string message = "Given game value out of bounds!: ";
};

#endif