#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class singlesFinder {
public:
    singlesFinder(int** gameBoard);

private:
    const int** gameBoard;
    
    bool** availRowValues;
    bool** availColValues;
    bool** availMacroGridValues;
};

#endif