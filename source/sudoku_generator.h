#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include <vector>
#include <set>
#include <string>

class newBoardGenerator {
public:
    newBoardGenerator(int** newGameBoard, int size, int gridSize);

    ~newBoardGenerator();

    void createCompletedBoard();

    std::set<int> eraseNumOfSquares(int n);

    void getAvailableNumberSet(int gridSpace,
                                std::vector<int> &target,
                                int exludedVal = -1) const;

    bool isUniqueSolution(std::vector<int> &emptyGrids, int gridNumber, int value);
private:
    //picks a random number, INCLUDING the number argument given
    int pickRanVal(int n) const;

    void SValueRemove(int colRowMinimum, int minimum);

    void insertValueIntoGridSpace(int gridSpace, int value);

    int removeValueFromGridSpace(int gridSpace, int value);

    int calRowNumber(int gridSpace) const;

    int calColNumber(int gridSpace) const;

    int calMacroGridCoor(int gridSpace) const;

    int calGridNumber(int row, int col) const;

    bool** rowValues;
    bool** colValues;
    bool** grids;
    std::set<int> remainingGridNumbers;

    int** newGameBoard;
    int size;
    int gridSize;
    int numberOfAvailableGrids;
};

class CreationValueOutOfBounds: public std::exception {
public:
    CreationValueOutOfBounds(const std::string &msg = "") {
        message += msg;
    }

    std::string what() {
        return message;
    }
private:
    std::string message = "Generated value out of bounds!: ";
};


#endif