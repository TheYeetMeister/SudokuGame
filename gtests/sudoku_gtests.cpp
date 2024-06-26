#include <gtest/gtest.h>
#include "../source/sudoku.h"
#include <set>

TEST(SudokuBoardSetUp, CreatingBoard) {
    SudokuBoard game = SudokuBoard();

    auto board = game.getGameBoard();

    int expectedBoard[9][9] = {{0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0}};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_EQ(game.getBoardSize(), 9);
}

TEST(SudokuBoardSetUp, AnchoredNumberPlacement) {
    SudokuBoard game = SudokuBoard();

    game.insertAnchoredNumber(4, 6, 7);

    game.insertAnchoredNumber(1, 1, 1);

    game.insertAnchoredNumber(7, 3, 7);

    int expectedBoard[9][9] = {{1,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 7,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 4,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0}};

    auto anchoredCoorSet = game.getAnchoredcoor();

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_NE(anchoredCoorSet.find((6 - 1) * 9 + (7 - 1)), anchoredCoorSet.end());
    EXPECT_NE(anchoredCoorSet.find(0), anchoredCoorSet.end());
    EXPECT_NE(anchoredCoorSet.find((3 - 1) * 9 + (7 - 1)), anchoredCoorSet.end());

    EXPECT_EQ(anchoredCoorSet.find((4 - 1) * 9 + (8 - 1)), anchoredCoorSet.end());
}

TEST(SudokuBoardOutOfBounds, AnchoredNumberOutOfBounds) {
    SudokuBoard game = SudokuBoard();

    game.insertAnchoredNumber(9, 5, 4);

    game.insertAnchoredNumber(7, 8, 9);

    game.insertAnchoredNumber(3, 5, 7);

    int expectedBoard[9][9] = {{0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 9,0,0, 3,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,7},
                               {0,0,0, 0,0,0, 0,0,0}};

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_THROW({
        game.insertAnchoredNumber(3, 9, 10);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.insertAnchoredNumber(0, 3, 6);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.insertAnchoredNumber(3, 4, -100);
    }, ValueOutOfBounds);
}

TEST(SudokuBoardSetUp, PlayerNumberPlacement) {
    SudokuBoard game = SudokuBoard();

    game.playerInsertNumber(6, 8, 4);

    game.playerInsertNumber(9, 4, 7);

    game.playerInsertNumber(3, 8, 5);

    int expectedBoard[9][9] = {{0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 9,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 6,3,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0}};

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }
}

TEST(SudokuBoardSetUp, removeValues) {
    SudokuBoard game = SudokuBoard();

    game.playerInsertNumber(5, 7, 8);

    game.playerInsertNumber(3, 4, 9);

    game.playerInsertNumber(9, 4, 2);

    int expectedBoard[9][9] = {{0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,9,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0}};

    game.playerRemoveNumber(4, 9);

    game.playerRemoveNumber(7, 8);

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_THROW({
        game.playerInsertNumber(5, 0, 9);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.playerInsertNumber(5, 10, 9);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.playerInsertNumber(-100, 4, 5);
    }, ValueOutOfBounds);
}

TEST(SudokuBoardOutOfBounds, PlayerInsertedNumberOutOfBounds) {
    SudokuBoard game = SudokuBoard();

    game.playerInsertNumber(5, 7, 8);

    game.playerInsertNumber(3, 4, 9);

    game.playerInsertNumber(9, 4, 2);

    int expectedBoard[9][9] = {{0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,9,0, 0,0,0, 0,0,3},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,5,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,0}};

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_THROW({
        game.playerInsertNumber(5, 0, 9);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.playerInsertNumber(5, 10, 9);
    }, ValueOutOfBounds);

    EXPECT_THROW({
        game.playerInsertNumber(-100, 4, 5);
    }, ValueOutOfBounds);
}


TEST(SudokuBoardSetUp, PlayerAnchoredInteractionPlacement) {
    SudokuBoard game = SudokuBoard();

    game.insertAnchoredNumber(1, 6, 1);
    game.insertAnchoredNumber(2, 3, 5);
    game.insertAnchoredNumber(3, 3, 8);
    game.insertAnchoredNumber(4, 3, 6);
    game.insertAnchoredNumber(5, 8, 9);
    game.insertAnchoredNumber(6, 2, 1);
    game.insertAnchoredNumber(7, 1, 4);
    game.insertAnchoredNumber(8, 7, 1);
    game.insertAnchoredNumber(9, 5, 4);

    int expectedBoard[9][9] = {{0,0,0, 7,0,0, 0,0,0},
                               {6,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,2,4, 0,3,0},
                               {0,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 9,0,0, 0,0,0},
                               {1,0,0, 0,0,0, 0,0,0},
                               {8,0,0, 0,0,0, 0,0,0},
                               {0,0,0, 0,0,0, 0,0,5},
                               {0,0,0, 0,0,0, 0,0,0}};

    auto board = game.getGameBoard();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    game.playerInsertNumber(3, 5, 2);
    game.playerInsertNumber(8, 8, 5);
    game.playerInsertNumber(1, 6, 3);
    game.playerInsertNumber(8, 4, 5);
    game.playerInsertNumber(6, 5, 6);
    game.playerInsertNumber(7, 7, 9);
    game.playerInsertNumber(9, 3, 9);

    expectedBoard[4][1] = 3;
    expectedBoard[7][4] = 8;
    expectedBoard[5][2] = 1;
    expectedBoard[3][4] = 8;
    expectedBoard[4][5] = 6;
    expectedBoard[6][8] = 7;
    expectedBoard[2][8] = 9;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }

    EXPECT_THROW({
        game.playerInsertNumber(9, 3, 6);
    }, GridPositionAlreadyTaken);

    EXPECT_THROW({
        game.playerInsertNumber(3, 8, 9);
    }, GridPositionAlreadyTaken);

    EXPECT_THROW({
        game.playerInsertNumber(6, 3, 8);
    }, GridPositionAlreadyTaken);

    game.playerInsertNumber(7, 8, 5);
    game.playerInsertNumber(7, 6, 3);

    expectedBoard[7][4] = 7;
    expectedBoard[5][2] = 7;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            EXPECT_EQ(board[i][j], expectedBoard[i][j]);
        }
    }
}

TEST(SudokuBoardLogic, SolvingOneRowOrColumn) {
    int row1[] = {0,0,0, 7,0,1, 0,0,0};
    int row2[] = {0,0,1, 6,0,2, 0,0,0};
    int row3[] = {1,4,5, 8,7,6, 9,2,3};
    int row4[] = {0,0,3, 5,0,4, 0,0,0};
    int row5[] = {1,2,4, 4,5,6, 7,8,9};
    int row6[] = {1,2,4, 3,5,6, 7,8,9};
    int row7[] = {0,0,8, 2,0,5, 0,0,0};
    int row8[] = {2,3,4, 1,0,7, 9,8,5};
    int row9[] = {0,0,9, 9,0,8, 0,0,0};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isSetOfNumbersSolved(2, 0, 0, 1));
    EXPECT_TRUE(game.isSetOfNumbersSolved(5, 0, 0, 1));
    EXPECT_TRUE(game.isSetOfNumbersSolved(5, 3, 1, 0));

    EXPECT_FALSE(game.isSetOfNumbersSolved(4, 3, 0, 1));
    EXPECT_FALSE(game.isSetOfNumbersSolved(7, 3, 0, 1));
    EXPECT_FALSE(game.isSetOfNumbersSolved(0, 4, 1, 0));
    EXPECT_FALSE(game.isSetOfNumbersSolved(7, 2, 1, 0));
}

TEST(SudokuBoardWrongBoardSets, WrongRowSets) {
    int row1[] = {0,0,0, 7,0,1, 0,0,0};
    int row2[] = {0,0,1, 6,0,2, 0,0,0};
    int row3[] = {1,4,5, 8,7,6, 9,2,3};
    int row4[] = {0,0,3, 5,0,4, 0,0,0};
    int row5[] = {1,2,4, 4,5,6, 7,8,9};
    int row6[] = {1,2,4, 3,5,6, 7,8,9};
    int row7[] = {0,0,8, 2,0,5, 0,0,0};
    int row8[] = {2,3,4, 1,0,7, 9,8,5};
    int row9[] = {0,0,9, 9,0,8, 0,0,0};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGridNumbers = game.getWrongGridsInSet(2, 4, 0, 1);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());

    wrongGridNumbers = game.getWrongGridsInSet(5, 8, 0, 1);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());

    std::set<int> predictedWrongGridNumbers{38, 39};
    wrongGridNumbers = game.getWrongGridsInSet(4, 3, 0, 1);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    predictedWrongGridNumbers = {67};
    wrongGridNumbers = game.getWrongGridsInSet(7, 8, 0, 1);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    predictedWrongGridNumbers = {72, 73, 74, 75, 76, 78, 79, 80};
    wrongGridNumbers = game.getWrongGridsInSet(8, 8, 0, 1);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());
}

TEST(SudokuBoardWrongBoardSets, WrongColumnSets) {
    int row1[] = {0,0,0, 7,0,1, 0,0,0};
    int row2[] = {0,0,1, 6,0,2, 0,0,0};
    int row3[] = {1,4,5, 8,7,6, 9,2,3};
    int row4[] = {0,0,3, 5,0,4, 0,0,0};
    int row5[] = {1,2,4, 4,5,6, 7,8,9};
    int row6[] = {1,2,4, 3,5,6, 7,8,9};
    int row7[] = {0,0,8, 2,0,5, 0,0,0};
    int row8[] = {2,3,4, 1,0,7, 9,8,5};
    int row9[] = {0,0,9, 9,0,8, 0,0,0};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGridNumbers = game.getWrongGridsInSet(2, 3, 1, 0);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());

    std::set<int> predictedWrongGridNumbers = {1, 10, 28, 37, 46, 55, 73};
    wrongGridNumbers = game.getWrongGridsInSet(0, 1, 1, 0);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    predictedWrongGridNumbers = {23, 41, 50};
    wrongGridNumbers = game.getWrongGridsInSet(0, 5, 1, 0);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    predictedWrongGridNumbers = {6, 15, 24, 33, 42, 51, 60, 69, 78};
    wrongGridNumbers = game.getWrongGridsInSet(0, 6, 1, 0);

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());
}

TEST(SudokuBoardLogic, SolvingAllRowsOrColumns) {
    int row1[] = {1,2,3, 7,6,5, 9,8,4};
    int row2[] = {2,3,1, 6,5,4, 7,8,9};
    int row3[] = {1,4,5, 8,7,6, 9,2,3};
    int row4[] = {6,9,3, 5,7,4, 8,1,2};
    int row5[] = {1,2,4, 3,5,6, 7,8,9};
    int row6[] = {1,2,4, 3,5,6, 7,8,9};
    int row7[] = {1,2,8, 3,4,5, 7,6,9};
    int row8[] = {2,3,4, 1,6,7, 9,8,5};
    int row9[] = {1,2,9, 3,4,8, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isConsecutiveSetsSolved(1, 0));

    EXPECT_FALSE(game.isConsecutiveSetsSolved(0, 1));
}

TEST(SudokuBoardWrongBoardSets, AllWrongSets) {
    int row1[] = {1,2,3, 7,6,5, 9,8,4};
    int row2[] = {2,3,1, 6,5,4, 7,8,9};
    int row3[] = {1,4,5, 8,7,6, 9,2,3};
    int row4[] = {6,9,3, 5,7,4, 8,1,2};
    int row5[] = {1,2,4, 3,5,6, 7,8,9};
    int row6[] = {1,2,4, 3,5,6, 7,8,9};
    int row7[] = {1,2,8, 3,4,5, 7,6,9};
    int row8[] = {2,3,4, 1,6,7, 9,8,5};
    int row9[] = {1,2,9, 3,4,8, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getWrongGridsInConsecutiveSets(1, 0);

    EXPECT_EQ(wrongGrids.begin(), wrongGrids.end());

    wrongGrids = game.getWrongGridsInConsecutiveSets(0, 1);
    std::set<int> predictedWrongGrids {0, 1, 2, 4, 5, 6, 7, 9, 10, 13, 14, 15, 16,
                                        17, 18, 22, 23, 24, 29, 31, 32, 36, 37, 38,
                                        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
                                        50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61,
                                        62, 63, 64, 65, 67, 69, 70, 72, 73, 75, 76,
                                        79};
    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardLogic, SolvingAllRowsOrColumns2) {
    int row1[] = {2,9,6, 7,1,1, 8,9,1};
    int row2[] = {3,8,1, 6,2,2, 5,8,2};
    int row3[] = {1,4,5, 8,7,6, 6,7,3};
    int row4[] = {4,7,3, 5,6,4, 1,6,4};
    int row5[] = {5,6,2, 4,3,3, 7,5,5};
    int row6[] = {6,2,4, 3,5,9, 2,1,6};
    int row7[] = {7,5,8, 2,4,5, 3,2,7};
    int row8[] = {8,3,7, 1,9,7, 9,3,8};
    int row9[] = {9,1,9, 9,8,8, 4,4,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isConsecutiveSetsSolved(0, 1));

    EXPECT_FALSE(game.isConsecutiveSetsSolved(1, 0));
}

TEST(SudokuBoardWrongBoardSets, AllWrongSets2) {
    int row1[] = {2,9,6, 7,1,1, 8,9,1};
    int row2[] = {3,8,1, 6,2,2, 5,8,2};
    int row3[] = {1,4,5, 8,7,6, 6,7,3};
    int row4[] = {4,7,3, 5,6,4, 1,6,4};
    int row5[] = {5,6,2, 4,3,3, 7,5,5};
    int row6[] = {6,2,4, 3,5,9, 2,1,6};
    int row7[] = {7,5,8, 2,4,5, 3,2,7};
    int row8[] = {8,3,7, 1,9,7, 9,3,8};
    int row9[] = {9,1,9, 9,8,8, 4,4,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getWrongGridsInConsecutiveSets(0, 1);

    EXPECT_EQ(wrongGrids.begin(), wrongGrids.end());

    wrongGrids = game.getWrongGridsInConsecutiveSets(1, 0);
    std::set<int> predictedWrongGrids {1, 4, 5, 7, 8, 10, 13, 14, 16, 17, 22,
                                        23, 24, 25, 27, 31, 32, 34, 35, 36, 40,
                                        41, 43, 44, 45, 46, 51, 53, 54, 55, 57,
                                        59, 61, 62, 63, 64, 65, 67, 68, 69, 70,
                                        71, 72, 74, 75, 76, 77, 78, 79, 80};
    
    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardLogic, SolvingSingleGrid) {
    int row1[] = {1,2,3, 7,5,1, 8,0,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,6, 9,2,3};
    int row4[] = {0,0,3, 5,0,4, 1,6,5};
    int row5[] = {1,2,4, 4,5,6, 7,2,9};
    int row6[] = {1,2,4, 3,5,6, 4,8,3};
    int row7[] = {1,6,8, 2,0,5, 2,8,1};
    int row8[] = {2,5,7, 1,0,7, 9,8,5};
    int row9[] = {3,4,9, 9,0,8, 3,4,5};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isSingleGridSolved(0, 0));
    EXPECT_TRUE(game.isSingleGridSolved(1, 2));
    EXPECT_TRUE(game.isSingleGridSolved(2, 0));

    EXPECT_FALSE(game.isSingleGridSolved(0, 1));
    EXPECT_FALSE(game.isSingleGridSolved(0, 2));
    EXPECT_FALSE(game.isSingleGridSolved(1, 0));
    EXPECT_FALSE(game.isSingleGridSolved(1, 1));
    EXPECT_FALSE(game.isSingleGridSolved(2, 1));
    EXPECT_FALSE(game.isSingleGridSolved(2, 2));
}

TEST(SudokuBoardWrongBoardGrids, WrongSingularGrid) { 
    int row1[] = {1,2,3, 7,5,1, 8,0,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,6, 9,2,3};
    int row4[] = {0,0,3, 5,0,4, 1,6,5};
    int row5[] = {1,2,4, 4,5,6, 7,2,9};
    int row6[] = {1,2,4, 3,5,6, 4,8,3};
    int row7[] = {1,6,8, 2,0,5, 2,8,1};
    int row8[] = {2,5,7, 1,0,7, 9,8,5};
    int row9[] = {3,4,9, 9,0,8, 3,4,5};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGridNumbers = game.getWrongGridsInMacroGrid(0, 0);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());

    wrongGridNumbers = game.getWrongGridsInMacroGrid(1, 2);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());

    wrongGridNumbers = game.getWrongGridsInMacroGrid(2, 0);

    EXPECT_EQ(wrongGridNumbers.begin(), wrongGridNumbers.end());


    wrongGridNumbers = game.getWrongGridsInMacroGrid(0, 1);
    std::set<int> predictedWrongGridNumbers {12, 23};

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    wrongGridNumbers = game.getWrongGridsInMacroGrid(0, 2);
    predictedWrongGridNumbers = {7};

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());

    wrongGridNumbers = game.getWrongGridsInMacroGrid(1, 0);
    predictedWrongGridNumbers = {27, 28, 36, 37, 38, 45, 46, 47};

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());
}

TEST(SudokuBoardLogic, SolvingAllGrids) {
    int row1[] = {1,2,3, 7,5,1, 8,7,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,9, 9,2,3};
    int row4[] = {6,5,3, 5,7,9, 1,6,5};
    int row5[] = {1,2,4, 4,2,3, 7,2,9};
    int row6[] = {7,8,9, 8,1,6, 4,8,3};
    int row7[] = {1,6,8, 6,4,5, 2,8,1};
    int row8[] = {2,5,7, 1,2,7, 9,5,7};
    int row9[] = {3,4,9, 9,3,8, 3,4,6};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.areAllGridsSolved());
}

TEST(SudokuBoardWrongBoardGrids, AllWrongGrid) {
    int row1[] = {1,2,3, 7,5,1, 8,7,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,9, 9,2,3};
    int row4[] = {6,5,3, 5,7,9, 1,6,5};
    int row5[] = {1,2,4, 4,2,3, 7,2,9};
    int row6[] = {7,8,9, 8,1,6, 4,8,3};
    int row7[] = {1,6,8, 6,4,5, 2,8,1};
    int row8[] = {2,5,7, 1,2,7, 9,5,7};
    int row9[] = {3,4,9, 9,3,8, 3,4,6};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGridsInMacroGrids();

    EXPECT_EQ(wrongGrids.begin(), wrongGrids.end());
}

TEST(SudokuBoardLogic, SolvingAllGrids2) {
    int row1[] = {1,2,3, 7,5,1, 8,7,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,9, 9,2,3};
    int row4[] = {6,5,3, 5,7,9, 1,6,5};
    int row5[] = {1,2,4, 4,2,3, 7,8,9};
    int row6[] = {7,8,9, 8,1,6, 4,8,3};
    int row7[] = {1,6,8, 6,4,5, 2,8,1};
    int row8[] = {2,5,7, 1,2,7, 9,5,7};
    int row9[] = {3,4,9, 9,3,8, 3,4,6};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.areAllGridsSolved());
}

TEST(SudokuBoardWrongBoardGrids, AllWrongGrid2) {
    int row1[] = {1,2,3, 7,5,1, 8,7,6};
    int row2[] = {4,5,6, 6,3,2, 1,4,5};
    int row3[] = {7,8,9, 8,4,9, 9,2,3};
    int row4[] = {6,5,3, 5,7,9, 1,6,5};
    int row5[] = {1,2,4, 4,2,3, 7,8,9};
    int row6[] = {7,8,9, 8,1,6, 4,8,3};
    int row7[] = {1,6,8, 6,4,5, 2,8,1};
    int row8[] = {2,5,7, 1,2,7, 9,5,7};
    int row9[] = {3,4,9, 9,3,8, 3,4,6};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGridNumbers = game.getAllWrongGridsInMacroGrids();
    std::set<int> predictedWrongGridNumbers {43, 52};

    for (auto i = wrongGridNumbers.begin(); i != wrongGridNumbers.end(); ++i) {
        EXPECT_NE(predictedWrongGridNumbers.find(*i), predictedWrongGridNumbers.end());
    }
    EXPECT_EQ(wrongGridNumbers.size(), predictedWrongGridNumbers.size());
}

TEST(SudokuBoardLogic, SolveEntirePuzzle) {
    int row1[] = {8,2,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,3, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzle2) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_TRUE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzleFail) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,9,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzleFail2) {
    int row1[] = {8,9,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,3, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzleFail3) {
    int row1[] = {8,2,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,2, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzleFail4) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,0};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardLogic, SolveEntirePuzzleFail5) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,0,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    EXPECT_FALSE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardWrongBoardGrids, NoWrongGrids) {
    int row1[] = {8,2,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,3, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();

    EXPECT_EQ(wrongGrids.begin(), wrongGrids.end());
}

TEST(SudokuBoardWrongBoardGrids, NoWrongGrids2) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();

    EXPECT_EQ(wrongGrids.begin(), wrongGrids.end());
}

TEST(SudokuBoardWrongBoardGrids, WrongGrids) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,9,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();
    std::set<int> predictedWrongGrids {5, 19, 22, 31};

    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardWrongBoardGrids, WrongGrids2) {
    int row1[] = {8,9,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,3, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();
    std::set<int> predictedWrongGrids {1, 7, 9, 28};

    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardWrongBoardGrids, WrongGrids3) {
    int row1[] = {8,2,7, 1,5,4, 3,9,6};
    int row2[] = {9,6,5, 3,2,7, 1,4,8};
    int row3[] = {3,4,1, 6,8,9, 7,5,2};
    int row4[] = {5,9,3, 4,6,8, 2,7,1};
    int row5[] = {4,7,2, 5,1,2, 6,8,9};
    int row6[] = {6,1,8, 9,7,2, 4,3,5};
    int row7[] = {7,8,6, 2,3,5, 9,1,4};
    int row8[] = {1,5,4, 7,9,6, 8,2,3};
    int row9[] = {2,3,9, 8,4,1, 5,6,7};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();
    std::set<int> predictedWrongGrids {38, 41, 50};

    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardWrongBoardGrids, WrongGrids4) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,8,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,0};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();
    std::set<int> predictedWrongGrids {80};

    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardWrongBoardGrids, WrongGrids5) {
    int row1[] = {4,3,5, 2,6,9, 7,8,1};
    int row2[] = {6,8,2, 5,7,1, 4,9,3};
    int row3[] = {1,9,7, 8,3,4, 5,6,2};
    int row4[] = {8,2,6, 1,9,5, 3,4,7};
    int row5[] = {3,7,4, 6,0,2, 9,1,5};
    int row6[] = {9,5,1, 7,4,3, 6,2,8};
    int row7[] = {5,1,9, 3,2,6, 8,7,4};
    int row8[] = {2,4,8, 9,5,7, 1,3,6};
    int row9[] = {7,6,3, 4,1,8, 2,5,9};

    int* testBoard[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};

    SudokuBoard game = SudokuBoard(testBoard);

    std::set<int> wrongGrids = game.getAllWrongGrids();
    std::set<int> predictedWrongGrids {40};

    for (auto i = wrongGrids.begin(); i != wrongGrids.end(); ++i) {
        EXPECT_NE(predictedWrongGrids.find(*i), predictedWrongGrids.end());
    }
    EXPECT_EQ(wrongGrids.size(), predictedWrongGrids.size());
}

TEST(SudokuBoardGeneration, CreateSolvedPuzzle) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0);

    EXPECT_TRUE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardGeneration, CreateSolvedPuzzle2) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0);

    EXPECT_TRUE(game.isTheWholeBoardSolved());
}

TEST(SudokuBoardGeneration, CreateSolvedPuzzle3) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0);

    EXPECT_TRUE(game.isTheWholeBoardSolved());
} 

TEST(SudokuBoardGeneration, CreatePlayablePuzzle) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0.197);

    EXPECT_EQ(game.getAnchoredcoor().size(), 9 * 9 - 16);
}

TEST(SudokuBoardGeneration, CreatePlayablePuzzle2) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0.39);

    EXPECT_EQ(game.getAnchoredcoor().size(), 9 * 9 - 32);
}

TEST(SudokuBoardGeneration, CreatePlayablePuzzle3) {
    SudokuBoard game = SudokuBoard();

    game.generateNewPlayableBoard(0.50);

    EXPECT_EQ(game.getAnchoredcoor().size(), 9 * 9 - 41);
}