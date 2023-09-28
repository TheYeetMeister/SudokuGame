#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class singlesFinder {
public:

private:
    int** gameBoard;
    
    bool** availRowValues;
    bool** availColValues;
    bool** availMacroGridValues;
};

#endif