#include "find_singles.h"

singlesFinder::singlesFinder(int** gameBoard, int size): gameBoard(gameBoard), size(size) { 
    availRowValues = new bool*[size]{};
    availColValues = new bool*[size]{};
    availMacroGridValues = new bool*[size]{};

    for(int i = 0; i < size; ++i) {
        availRowValues[i] = new bool[size]{};
        availColValues[i] = new bool[size]{};
        availMacroGridValues[i] = new bool[size]{};
    }
}


singlesFinder::~singlesFinder() {
    for(int i = 0; i < size; ++i) {
        delete[] availRowValues[i];
        delete[] availColValues[i];
        delete[] availMacroGridValues[i];
    }

    delete[] availRowValues;
    delete[] availColValues;
    delete[] availMacroGridValues;
}