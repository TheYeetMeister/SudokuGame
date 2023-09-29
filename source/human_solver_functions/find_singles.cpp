#include "find_singles.h"

#include <iostream>
#include <memory>

SinglesFinder::SinglesFinder(int** gameBoard, int size, int gridSize): gameBoard(gameBoard), size(size), gridSize(gridSize) { }

void SinglesFinder::setTakenValues(std::vector<std::vector<bool>> &takenRowValues,
                                    std::vector<std::vector<bool>> &takenColValues, 
                                    std::vector<std::vector<bool>> &takenMacroGridValues) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if (gameBoard[i][j] != 0) {
                int valueIndex = gameBoard[i][j] - 1;

                takenRowValues[i][valueIndex] = true;
                takenColValues[j][valueIndex] = true;
                takenMacroGridValues[calMacroGridIndex(i, j)][valueIndex] = true;
            }
        }
    }
}

std::unordered_map<int, int> SinglesFinder::findSingleDigits() {
    std::vector<std::vector<bool>> takenRowValues(
        size, 
        std::vector<bool>(size, 0));

    std::vector<std::vector<bool>> takenColValues(
        size, 
        std::vector<bool>(size, 0));

    std::vector<std::vector<bool>> takenMacroGridValues(
        size, 
        std::vector<bool>(size, 0));

    setTakenValues(takenRowValues, takenColValues, takenMacroGridValues);

    std::unordered_map<int, int> openGridAndValue;
}

int SinglesFinder::calGridNumber(int row, int col) const {
    
}


int SinglesFinder::calMacroGridIndex(int row, int col) const {
    return row * gridSize + col % gridSize;
}