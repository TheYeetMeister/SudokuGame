#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iosfwd>

class singlesFinder {
public:
    singlesFinder(int** gameBoard, int size);

    ~singlesFinder();

    //used for naked singles AND full houses/last digits
    int findSingleDigit();
private:
    void setTakenValues();

    const int** gameBoard;
    const int size;
    
    bool** takenRowValues;
    bool** takenColValues;
    bool** takenMacroGridValues;
};

#endif