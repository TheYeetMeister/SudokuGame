#include "find_singles.h"

singlesFinder::singlesFinder(int** gameBoard, int size): gameBoard(gameBoard), size(size) { 
    takenRowValues = new bool*[size]{};
    takenColValues = new bool*[size]{};
    takenMacroGridValues = new bool*[size]{};

    for(int i = 0; i < size; ++i) {
        takenRowValues[i] = new bool[size]{};
        takenColValues[i] = new bool[size]{};
        takenMacroGridValues[i] = new bool[size]{};
    }
}

void singlesFinder::setTakenValues() {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if (gameBoard[i][j] != 0) {
                int valueIndex = gameBoard[i][j] - 1;

                takenRowValues[i][valueIndex] = true;
                takenColValues[j][valueIndex] = true;
            }
        }
    }
}

singlesFinder::~singlesFinder() {
    for(int i = 0; i < size; ++i) {
        delete[] takenRowValues[i];
        delete[] takenColValues[i];
        delete[] takenMacroGridValues[i];
    }

    delete[] takenRowValues;
    delete[] takenColValues;
    delete[] takenMacroGridValues;
}