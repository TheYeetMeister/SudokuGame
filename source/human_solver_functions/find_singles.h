#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class SinglesFinder {
public:
    SinglesFinder(int** gameBoard, int size, int gridSize);

    ~SinglesFinder();

    //used for naked singles AND full houses/last digits
    int findSingleDigit();
private:
    void setTakenValues();

    int calGridValue(int row, int col) const;

    const int** gameBoard;
    const int size;
    const int gridSize;
    
    bool** takenRowValues;
    bool** takenColValues;
    bool** takenMacroGridValues;
};

#endif