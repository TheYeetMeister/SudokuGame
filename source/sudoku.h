#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>
#include <set>
#include <string>
#include <vector>

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

    void generateNewPlayableBoard(double percentageEmpty);

    class newBoardGenerator {
    public:
        newBoardGenerator(int** newGameBoard, int size, int gridSize, SudokuBoard &parent);

        ~newBoardGenerator();

        void createCompletedBoard();

        std::set<int> eraseNumOfSquares(int n);

        std::vector<int> getAvailableNumberSet(int gridSpace);

        void getTakenValues(bool* target, const bool* given) const;

        bool isUniqueSolution(std::vector<int> &emptyGrids);
    private:
        //picks a random number, INCLUDING the number argument given
        int pickRanVal(int n);

        void insertValueIntoGridSpace(int gridSpace, int value);

        void removeValueFromGridSpace(int gridSpace, int value);

        int calRowNumber(int gridSpace) const;

        int calColNumber(int gridSpace) const;

        int calMacroGridCoor(int gridSpace) const;

        int calGridNumber(int row, int col) const;

        bool** rowValues;
        bool** colValues;
        bool** grids;
        std::set<int> allIndivGrids;
        SudokuBoard &parent;

        int** newGameBoard;
        int size;
        int gridSize;
        int numberOfAvailableGrids;
    };
private:

    std::string adjustStringSize(const char value) const;

    std::string returnNumberComposition(int num, int gridCoor, bool markWrongValues) const;

    std::string composeNumber(int n) const;

    void printHeader(std::ostream &out) const;

    bool valueInRange(int value) const;

    void checkRowColVal(int num, int row, int col) const;

    bool isGridAnchored(int row, int col);

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