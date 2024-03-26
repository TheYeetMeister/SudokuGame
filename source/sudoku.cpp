#include "sudoku.h"

#include <iostream>
#include <set>
#include <string>
#include <climits>
#include <cmath>
#include <unordered_map>
#include "sudoku_generator.cpp"

const int UPPER_LIMIT = INT_MAX;

constexpr int SIZE_OF_TEST_BOARD = 9;
constexpr int GRIDSIZE_OF_TEST_BOARD = 3;

SudokuBoard::SudokuBoard(int gridSize): size(gridSize*gridSize), gridSize(gridSize) {
    if (gridSize < 1 || gridSize > 99) {
        throw ValueOutOfBounds("Value given for board is out of bounds: " + std::to_string(gridSize));
    }

    gameBoard = new int*[size];

    for (int i = 0; i < size; ++i) {
        gameBoard[i] = new int[size]{0};
    }

    madeNotUsingNew = false;
}

SudokuBoard::SudokuBoard(int** exampleBoard): size(SIZE_OF_TEST_BOARD), gridSize(GRIDSIZE_OF_TEST_BOARD) {
    //size of given board HAS to be 9 x 9 (mainly for testing purposes)

    gameBoard = exampleBoard;
    madeNotUsingNew = true;
}

SudokuBoard::SudokuBoard(const SudokuBoard &s): size(s.size), gridSize(s.gridSize), madeNotUsingNew(s.madeNotUsingNew) {
    gameBoard = new int*[size];

    for (int i = 0; i < size; ++i) {
        gameBoard[i] = new int[size]{0};
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = s.gameBoard[i][j];
        }
    }

    for (auto it = s.anchoredCoor.begin(); it != s.anchoredCoor.end(); ++it) {
        anchoredCoor.insert(*it);
    }
}

SudokuBoard& SudokuBoard::operator=(const SudokuBoard &s) {
    if (s.gridSize != gridSize) {
        throw std::length_error("sizes of sudoku boards do not match");
    }

    if (this == &s) {
        return *this;
    }

    size = s.size;
    madeNotUsingNew = s.madeNotUsingNew;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = s.gameBoard[i][j];
        }
    }

    for (auto it = s.anchoredCoor.begin(); it != s.anchoredCoor.end(); ++it) {
        anchoredCoor.insert(*it);
    }

    return *this;
}

SudokuBoard::SudokuBoard(SudokuBoard &&s): size(s.size), gridSize(s.gridSize), 
                        madeNotUsingNew(s.madeNotUsingNew), anchoredCoor(s.anchoredCoor)  {
    gameBoard = new int*[size];

    for (int i = 0; i < size; ++i) {
        gameBoard[i] = new int[size]{0};
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = s.gameBoard[i][j];
        }
    }
}

SudokuBoard& SudokuBoard::operator=(SudokuBoard &&s) {
    if (s.gridSize != gridSize) {
        throw std::length_error("sizes of sudoku boards do not match");
    }

    if (this == &s) {
        return *this;
    }

    size = s.size;
    madeNotUsingNew = s.madeNotUsingNew;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = s.gameBoard[i][j];
        }
    }

    anchoredCoor = s.anchoredCoor;

    return *this;
}

SudokuBoard::~SudokuBoard() {
    if (madeNotUsingNew) return;

    for (int i = 0; i < size; ++i) {
        delete[] gameBoard[i];
    }
    delete[] gameBoard;
}

int** SudokuBoard::getGameBoard(){
    return gameBoard;
}

std::set<int> SudokuBoard::getAnchoredcoor() {
    return anchoredCoor;
}

int SudokuBoard::getBoardSize() const {
    return size;
}

void SudokuBoard::insertAnchoredNumber(int num, int row, int col) {
    checkRowColVal(num, row, col);

    gameBoard[row - 1][col - 1] = num;
    anchoredCoor.insert(calGridNumber(row - 1, col - 1));
}

void SudokuBoard::playerInsertNumber(int num, int row, int col) {
    checkRowColVal(num, row, col);

    if (!isGridAnchored(row - 1, col - 1)) {
        throw GridPositionAlreadyTaken("Position in sudoku grid already taken by anchored number at row: " + std::to_string(row) + " and col: " + std::to_string(col));
    }

    gameBoard[row - 1][col - 1] = num;
}

void SudokuBoard::playerRemoveNumber(int row, int col) {
    checkRowColVal(1, row, col);

    if (!isGridAnchored(row - 1, col - 1)) {
        throw GridPositionAlreadyTaken("Position in sudoku grid is an anchored number, can not be removed; row: " + std::to_string(row) + ", column: " + std::to_string(col));
    }

    gameBoard[row - 1][col - 1] = 0;
}

void SudokuBoard::print(std::ostream &out, bool markWrongValues) const {
    printHeader(out);

    std::set<int> wrongGrids;
    
    if (markWrongValues) {
        wrongGrids = getAllWrongGrids();
    }

    auto tempIndex = wrongGrids.begin();

    for (int i = 0; i < size; ++i) {
        if (i && (i % gridSize == 0)) {
            out << "  " << adjustStringSize(' ');

            for (int k = 0; k < gridSize - 1; ++k) out << "===";
            
            for (int k = 0; k < size; ++k) {
                out << "===" << adjustStringSize('=');
            }

            out << '\n';
        }

        out << composeNumber(i + 1) << "|";

        for(int j = 0; j < size; ++j) {
            if (j && (j % gridSize == 0)) {
                out << "|||";
            }

            if (markWrongValues && tempIndex != wrongGrids.end() && calGridNumber(i, j) == *tempIndex) {
                out << returnNumberComposition(gameBoard[i][j], calGridNumber(i, j), true);
                ++tempIndex;
            } else {
                out << returnNumberComposition(gameBoard[i][j], calGridNumber(i, j), false);
            }
        }

        out << '\n';
    }
}

bool SudokuBoard::isTheWholeBoardSolved() const {
    return (isConsecutiveSetsSolved(0, 1) &&
            isConsecutiveSetsSolved(1, 0) &&
            areAllGridsSolved());
}

std::set<int> SudokuBoard::getAllWrongGrids() const {
    std::set<int> wrongGrids;

    std::set<int> tempSet = getWrongGridsInConsecutiveSets(1, 0);
    wrongGrids.insert(tempSet.begin(), tempSet.end());

    tempSet = getWrongGridsInConsecutiveSets(0, 1);
    wrongGrids.insert(tempSet.begin(), tempSet.end());

    tempSet = getAllWrongGridsInMacroGrids();
    wrongGrids.insert(tempSet.begin(), tempSet.end());

    return wrongGrids;
}

bool SudokuBoard::isConsecutiveSetsSolved(int rowDelta, int colDelta) const {
    int limiter = 0;
    for(int row = 0, col = 0;
        valueInRange(row + 1) && valueInRange(col + 1) && UPPER_LIMIT > limiter;
        row += rowDelta, col += colDelta, ++limiter) {
        
        if (!isSetOfNumbersSolved(row, col, colDelta, rowDelta)) return false;
    }

    if (limiter == UPPER_LIMIT) return false;

    return true;
}

bool SudokuBoard::isSetOfNumbersSolved(int row, int col, int rowDelta, int colDelta) const {
    if (rowDelta > 0) row = 0;
    if (colDelta > 0) col = 0;

    std::set<int> rowColSet;

    int limiter = 0;

    for(;valueInRange(row + 1) && valueInRange(col + 1) && UPPER_LIMIT > limiter;
        row += rowDelta, col += colDelta, ++limiter) {
        if (!gameBoard[row][col]) return false;
        if (rowColSet.find(gameBoard[row][col]) != rowColSet.end()) return false;
        rowColSet.insert(gameBoard[row][col]);
    }

    if (limiter == UPPER_LIMIT) return false;

    return true;
}

bool SudokuBoard::areAllGridsSolved() const {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (!isSingleGridSolved(i, j)) return false;
        }
    }

    return true;
}

bool SudokuBoard::isSingleGridSolved(int gridRow, int gridCol) const {
    if(gridRow < 0 || gridRow >= gridSize) throw ValueOutOfBounds("GridRow out of bounds " + std::to_string(gridRow));
    if(gridCol < 0 || gridCol >= gridSize) throw ValueOutOfBounds("GridCol out of bounds " + std::to_string(gridCol));

    gridRow *= gridSize;
    gridCol *= gridSize;

    std::set<int> rowColSet;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (!gameBoard[gridRow + i][gridCol + j]) return false;
            if (rowColSet.find(gameBoard[gridRow + i][gridCol + j]) != rowColSet.end()) return false;
            rowColSet.insert(gameBoard[gridRow + i][gridCol + j]);
        }
    }

    return true;
}

std::set<int> SudokuBoard::getWrongGridsInConsecutiveSets(int rowDelta, int colDelta) const {
    std::set<int> wrongGrids;

    int limiter = 0;

    for (int row = 0, col = 0; row < size && col < size && limiter < UPPER_LIMIT;
        row += rowDelta, col += colDelta, ++limiter) {
        std::set<int> tempSet = getWrongGridsInSet(row, col, colDelta, rowDelta);

        wrongGrids.insert(tempSet.begin(), tempSet.end());
    }

    return wrongGrids;
}

std::set<int> SudokuBoard::getWrongGridsInSet(int row, int col, int rowDelta, int colDelta) const {
    if (rowDelta > 0) row = 0;
    if (colDelta > 0) col = 0;
    
    int limiter = 0;

    std::unordered_map<int, int> valueAndGridSpace;
    std::set<int> wrongGrids;

    for (;valueInRange(row + 1) && valueInRange(col + 1) && limiter < UPPER_LIMIT;
        row += rowDelta, col += colDelta, ++limiter) {
        if (!gameBoard[row][col]) {
            wrongGrids.insert(calGridNumber(row, col));

        } else if (valueAndGridSpace.find(gameBoard[row][col]) != valueAndGridSpace.end()) {
            wrongGrids.insert(calGridNumber(row, col));
            wrongGrids.insert(valueAndGridSpace.find(gameBoard[row][col])->second);

        } else {
            valueAndGridSpace[gameBoard[row][col]] = calGridNumber(row, col);
        }
    }

    if (limiter == UPPER_LIMIT) throw ValueOutOfBounds("Limit reached in loop");

    return wrongGrids;
}

std::set<int> SudokuBoard::getAllWrongGridsInMacroGrids() const {
    std::set<int> wrongGrids;

    for(int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::set<int> tempSet = getWrongGridsInMacroGrid(i, j);

            wrongGrids.insert(tempSet.begin(), tempSet.end());
        }
    }

    return wrongGrids;
}

std::set<int> SudokuBoard::getWrongGridsInMacroGrid(int gridRow, int gridCol) const {
    if (gridRow < 0 || gridRow >= gridSize) throw ValueOutOfBounds("given grid row out of bounds " + std::to_string(gridRow));
    if (gridCol < 0 || gridCol >= gridSize) throw ValueOutOfBounds("given grid col out of bounds " + std::to_string(gridCol));

    int limiter = 0;

    std::unordered_map<int, int> valueAndGridSpace;
    std::set<int> wrongGrids;

    gridRow *= gridSize;
    gridCol *= gridSize;

    for (int i = 0; i < gridSize && limiter < UPPER_LIMIT; ++i) {
        for (int j = 0; j < gridSize && limiter < UPPER_LIMIT; ++j) {
            int row = gridRow + i;
            int col = gridCol + j;

            if (!gameBoard[row][col]) {
                wrongGrids.insert(calGridNumber(row, col));
            } else if (valueAndGridSpace.find(gameBoard[row][col]) != valueAndGridSpace.end()) {
                wrongGrids.insert(calGridNumber(row, col));
                wrongGrids.insert(valueAndGridSpace.find(gameBoard[row][col])->second);
            } else {
                valueAndGridSpace[gameBoard[row][col]] = calGridNumber(row, col);
            }

            ++limiter;
        }
    }

    if (limiter == UPPER_LIMIT) throw ValueOutOfBounds("Limit reached in loop");

    return wrongGrids;
}

std::string SudokuBoard::adjustStringSize(const char value) const {
    std::string returnValue = "";

    for(int i = 0; i < int(log10(size)); ++i) {
        returnValue = returnValue + value;
    }

    return returnValue;
}

std::string SudokuBoard::returnNumberComposition(int num, int gridCoor, bool markWrongValue) const {
    std::string mainReturn = composeNumber(num);

    if (markWrongValue) {
        return "*" + mainReturn + "*";
    } else if (anchoredCoor.size() > 0 && anchoredCoor.find(gridCoor) != anchoredCoor.end()) {
        return "[" + mainReturn + "]";
    } 
    return " " + mainReturn + " ";
}

std::string SudokuBoard::composeNumber(int n) const {
    int numOfDigits = int(log10(size));
    std::string mainReturn;

    if (n <= 0) {
        n = 1;
        mainReturn = "x";
    } else {
        mainReturn = std::to_string(n);
    }

    for (int i = 0; i < numOfDigits - int(log10(n)); ++i) {
        mainReturn = " " + mainReturn;
    }

    return mainReturn;
}

void SudokuBoard::printHeader(std::ostream &out) const {
    out << "  " << adjustStringSize(' ');

    for (int i = 0; i < size; ++i) {
        if (i && (i % gridSize == 0)) {
            out << "   ";
        }

        out << ' ' << composeNumber(i + 1) << ' ';
    }

    out << '\n';

    out << "  " << adjustStringSize(' ');

    for (int i = 0; i < size; ++i) {
        if (i && (i % gridSize == 0)) {
            out << "   ";
        }

        out << "---" << adjustStringSize('-');;

    }

    out << '\n';
}

bool SudokuBoard::valueInRange(int value) const {
    //doesn't include zero as values inside sudoku board that are valid are never zero
    return (0 < value && value <= size);
}

void SudokuBoard::checkRowColVal(int num, int row, int col) const {
    if (!valueInRange(num)) throw ValueOutOfBounds("The value inserted into the board is out of bounds/invalid : " + std::to_string(num));

    if (!valueInRange(row)) throw ValueOutOfBounds("The given row is out of bounds/invalid : " + std::to_string(row));

    if (!valueInRange(col)) throw ValueOutOfBounds("The given col is out of bounds/invalid : " + std::to_string(col));
}

bool SudokuBoard::isGridAnchored(int row, int col) {
    return (anchoredCoor.find(calGridNumber(row, col)) == anchoredCoor.end());
}

int SudokuBoard::calGridNumber(int row, int col) const {
    return (row) * (size) + col;
}

void SudokuBoard::generateNewPlayableBoard(double percentageEmpty) {
    if (percentageEmpty < 0 || percentageEmpty > 1) {
        throw ValueOutOfBounds("Number of removed values is either too large or too small");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = 0;
        }
    }

    anchoredCoor.clear();


    newBoardGenerator generator = newBoardGenerator(gameBoard, size, gridSize);

    generator.createCompletedBoard();

    int numOfRemovedValues = int((size * size) * percentageEmpty + 0.5);
    anchoredCoor = generator.eraseNumOfSquares(numOfRemovedValues);
}

std::ostream &operator<<(std::ostream &out, const SudokuBoard &b) {
    b.print(out);

    return out;
}