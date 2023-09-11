#include "sudoku.h"

#include <iostream>
#include <set>
#include <string>
#include <climits>
#include <random>

const int UPPER_LIMIT = INT_MAX;

SudokuBoard::SudokuBoard(int gridSize) {
    size = gridSize * 3;

    gameBoard = new int*[size];

    for (int i = 0; i < size; ++i) {
        gameBoard[i] = new int[size]{0};
    }

    madeNotUsingNew = false;
}

SudokuBoard::SudokuBoard(int** exampleBoard) {
    //size of given board HAS to be 9 x 9 (mainly for testing purposes)
    size = 9;

    gameBoard = exampleBoard;
    madeNotUsingNew = true;
}

SudokuBoard::~SudokuBoard() {
    if (madeNotUsingNew) return;

    for (int i = 0; i < size; ++i) {
        delete gameBoard[i];
    }
    delete gameBoard;
}

int** SudokuBoard::getGameBoard(){
    return gameBoard;
}

std::set<int> SudokuBoard::getAnchoredcoor() {
    return anchoredCoor;
}

void SudokuBoard::insertAnchoredNumber(int num, int row, int col) {
    checkRowColVal(num, row, col);

    gameBoard[row - 1][col - 1] = num;
    anchoredCoor.insert(calGridNumber(row, col));
}

void SudokuBoard::playerInsertNumber(int num, int row, int col) {
    checkRowColVal(num, row, col);

    if (!isGridAnchored(row, col)) {
        throw GridPositionAlreadyTaken("Position in sudoku grid already taken at row: " + std::to_string(row) + " and col: " + std::to_string(col));
    }

    gameBoard[row - 1][col - 1] = num;
}

void SudokuBoard::print(std::ostream &out) const {
    printHeader(out);

    for (int i = 0; i < size; ++i) {
        if (i && (i % (size / 3) == 0)) {
            out << "  ";

            for (int k = 0; k < size * 4 / 3 - 1; ++k) {
                out << "===";
            }

            out << '\n';
        }

        out << i + 1 << "|";

        for(int j = 0; j < size; ++j) {
            if (j && (j % (size / 3) == 0)) {
                out << "|||";
            }

            if (gameBoard[i][j]) {
                out << ' ' << gameBoard[i][j] << ' ';
            } else {
                out << " x ";
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
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!isSingleGridSolved(i, j)) return false;
        }
    }

    return true;
}

bool SudokuBoard::isSingleGridSolved(int gridRow, int gridCol) const {
    if(gridRow < 0 || gridRow >= 3) throw ValueOutOfBounds("GridRow out of bounds " + std::to_string(gridRow));
    if(gridCol < 0 || gridCol >= 3) throw ValueOutOfBounds("GridCol out of bounds " + std::to_string(gridCol));

    int gridSize = size / 3;

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

std::string returnCharacter(char c) const {
    
}

void SudokuBoard::printHeader(std::ostream &out) const {
    out << "  ";
    for (int i = 0; i < size; ++i) {
        if (i && (i % (size / 3) == 0)) {
            out << "   ";
        }

        out << ' ' << i + 1 << ' ';
    }

    out << '\n';

    out << "  ";
    for (int i = 0; i < size; ++i) {
        if (i && (i % (size / 3) == 0)) {
            out << "   ";
        }

        out << "---";
    }

    out << '\n';
}

bool SudokuBoard::valueInRange(int value) const {
    return (0 < value && value <= size);
}

void SudokuBoard::checkRowColVal(int num, int row, int col) const {
    if (!valueInRange(num)) throw ValueOutOfBounds("The value inserted into the board is out of bounds/invalid : " + num);

    if (!valueInRange(row)) throw ValueOutOfBounds("The given row is out of bounds/invalid : " + row);

    if (!valueInRange(col)) throw ValueOutOfBounds("The given col is out of bounds/invalid : " + col);
}

bool SudokuBoard::isGridAnchored(int row, int col) {
    return (anchoredCoor.find(calGridNumber(row, col)) == anchoredCoor.end());
}

int SudokuBoard::calGridNumber(int row, int col) const {
    return (row - 1) * (size) + col - 1;
}

void SudokuBoard::generateNewPlayableBoard(int numOfRemovedValues) {
    if (numOfRemovedValues < 0 || numOfRemovedValues > size * size) {
        throw ValueOutOfBounds("Number of removed values is either too large or too small");
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            gameBoard[i][j] = 0;
        }
    }

    anchoredCoor.clear();


    newBoardGenerator generator = newBoardGenerator(gameBoard, size);

    generator.createCompletedBoard();

    anchoredCoor = generator.eraseNumOfSquares(numOfRemovedValues);
}

SudokuBoard::newBoardGenerator::newBoardGenerator(int** newGameBoard, int size)
                : newGameBoard(newGameBoard), size(size), numberOfAvailableGrids(size * size)
    {
        for(int i = 0; i < size * size; ++i) {
            allIndivGrids.insert(i);
        }

        for (int i = 1; i <= size; ++i) {
            allValues.insert(i);
        }

        rowValues = new std::set<int>[size];
        colValues = new std::set<int>[size];
    }

SudokuBoard::newBoardGenerator::~newBoardGenerator() {
    delete[] rowValues;
    delete[] colValues;
}

void SudokuBoard::newBoardGenerator::createCompletedBoard() {
    if (!size) return;

    std::set<int> **dp = new std::set<int>*[size];
    for(int i = 0; i < size; ++i) {
        dp[i] = new std::set<int>[size];
    }

    //backtracking algorithm, randomized for sudoku
    dp[0][0] = getAvailableNumberSet(0);
    for(int i = 0; i < size * size - 1;) {
        int row = calRowNumber(i);
        int col = calColNumber(i);

        int value = pickRanValidVal(dp[row][col]);

        if (value == -1) {
            --i;
            removeValueFromGridSpace(i, newGameBoard[calRowNumber(i)][calColNumber(i)]);
            continue;
        }

        dp[row][col].erase(value);
        insertValueIntoGridSpace(i, value);
        ++i;

        dp[calRowNumber(i)][calColNumber(i)] = getAvailableNumberSet(i);
    }
    insertValueIntoGridSpace(size * size - 1, 
                *dp[size-1][size-1].begin());
    //end of algorithm

    for(int i = 0; i < size; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
}

std::set<int> SudokuBoard::newBoardGenerator::eraseNumOfSquares(int n) {
    std::set<int> remainingGridNumbers = allIndivGrids;

    if (n < 0 || n > size * size) {
        throw ValueOutOfBounds("Number of values erased too large, or too small");
    }

    for (int i = 0; i < n; ++i) {
        int gridNumber = pickRanValidVal(remainingGridNumbers);

        newGameBoard[calRowNumber(gridNumber)][calColNumber(gridNumber)] = 0;

        remainingGridNumbers.erase(gridNumber);
    }

    return remainingGridNumbers;
}

int SudokuBoard::newBoardGenerator::pickRanValidVal(std::set<int> &values) {
    if (!values.size()) return -1;

    std::random_device generator;
    std::mt19937 rng(generator());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, values.size() - 1);

    auto tempIndex = values.begin();

    std::advance(tempIndex, distribution(generator));

    return *tempIndex;
}

void SudokuBoard::newBoardGenerator::insertValueIntoGridSpace(int gridSpace, int value) {
    rowValues[calRowNumber(gridSpace)].insert(value);
    colValues[calColNumber(gridSpace)].insert(value);
    grids[calMacroGridCoor(gridSpace)].insert(value);

    newGameBoard[calRowNumber(gridSpace)][calColNumber(gridSpace)] = value;
}

void SudokuBoard::newBoardGenerator::removeValueFromGridSpace(int gridSpace, int value)
{
    rowValues[calRowNumber(gridSpace)].erase(value);
    colValues[calColNumber(gridSpace)].erase(value);
    grids[calMacroGridCoor(gridSpace)].erase(value);

    newGameBoard[calRowNumber(gridSpace)][calColNumber(gridSpace)] = 0;
}

std::set<int> SudokuBoard::newBoardGenerator::
    getAvailableNumberSet(int gridSpace) {
        std::set<int> unavailableValues;

        mergeTwoSets(unavailableValues, rowValues[calRowNumber(gridSpace)]);
        mergeTwoSets(unavailableValues, colValues[calColNumber(gridSpace)]);
        mergeTwoSets(unavailableValues, grids[calMacroGridCoor(gridSpace)]);

        std::set<int> availableValues = allValues;

        for (auto i = unavailableValues.begin(); i != unavailableValues.end(); ++i)
        {
            availableValues.erase(*i);
        }
        return availableValues;
}

void SudokuBoard::newBoardGenerator::
    mergeTwoSets(std::set<int> &target, std::set<int> const &given) const {
        for(auto i = given.begin(); i != given.end(); ++i) {
            target.insert(*i);
        }
}

int SudokuBoard::newBoardGenerator::calRowNumber(int gridSpace) const{
    return (gridSpace / size);
}

int SudokuBoard::newBoardGenerator::calColNumber(int gridSpace) const{
    return(gridSpace % size);
}

int SudokuBoard::newBoardGenerator::calMacroGridCoor(int gridSpace) const {
    int gridRow = (gridSpace / size) / (size / 3);
    int gridCol = (gridSpace % size) / (size / 3);

    return (gridRow * 3 + gridCol);
}

int SudokuBoard::newBoardGenerator::calGridNumber(int row, int col) const {
    return ((row * size) + col);
}