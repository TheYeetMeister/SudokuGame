#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class SinglesFinder {
public:
    SinglesFinder(int** gameBoard, int size, int gridSize);

    //used for naked singles AND full houses/last digits
    int findSingleDigit();
private:
    void setTakenValues(std::vector<std::vector<bool>> &takenRowValues,
                        std::vector<std::vector<bool>> &takenColValues, 
                        std::vector<std::vector<bool>> &takenMacroGridValues);

    int calMacroGridIndex(int row, int col) const;

    const int** gameBoard;
    const int size;
    const int gridSize;
};

#endif