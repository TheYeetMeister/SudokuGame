#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class singlesFinder {
public:
    singlesFinder(int** gameBoard, int size);

    ~singlesFinder();
private:
    const int** gameBoard;
    const int size;
    
    bool** availRowValues;
    bool** availColValues;
    bool** availMacroGridValues;
};

#endif