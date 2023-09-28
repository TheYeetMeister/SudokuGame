#include "find_singles.h"

SinglesFinder::SinglesFinder(int** gameBoard, int size, int gridSize): gameBoard(gameBoard), size(size), gridSize(gridSize) { 
    takenRowValues = new bool*[size]{};
    takenColValues = new bool*[size]{};
    takenMacroGridValues = new bool*[size]{};

    for(int i = 0; i < size; ++i) {
        takenRowValues[i] = new bool[size]{};
        takenColValues[i] = new bool[size]{};
        takenMacroGridValues[i] = new bool[size]{};
    }
}

void SinglesFinder::setTakenValues() {
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

int SinglesFinder::calMacroGridIndex(int row, int col) const {
    return row * gridSize + col;
}

SinglesFinder::~SinglesFinder() {
    for(int i = 0; i < size; ++i) {
        delete[] takenRowValues[i];
        delete[] takenColValues[i];
        delete[] takenMacroGridValues[i];
    }

    delete[] takenRowValues;
    delete[] takenColValues;
    delete[] takenMacroGridValues;
}