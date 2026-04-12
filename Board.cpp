//
// Created by Dylan Williams on 4/6/2026.
//

#include "Board.h"

Board::Board()
{
    initBoard();
}

void Board::initBoard()
{
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board[y][x].setFile(x + 1);
            board[y][x].setRank(y + 1);
        }
    }
}

Tile *Board::getTile(int rank, int file)
{
    // Subtract 1 to convert from 1-based rank/file to 0-based array index
    return &board[rank - 1][file - 1];
}