//
// Created by Dylan Williams on 4/6/2026.
//

#include "Board.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"

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

    //set turn order to start on white
    turnOrder = 0;

    //Initialize new pieces, white pieces
    new Bishop(this, 8, 3, "WhiteBishopDark", 0);
    new Bishop(this, 8, 6, "WhiteBishopLight", 0);
    new Rook(this, 8, 1, "WhiteRookLeft", 0);
    new Rook(this, 8, 8, "WhiteRookRight", 0);
    new Knight(this, 8, 2, "WhiteKnightLeft", 0);
    new Knight(this, 8, 7, "WhiteKnightRight", 0);
    new Queen(this, 8, 4, "WhiteQueen", 0);
    new King(this, 8, 5, "WhiteKing", 0);

    //Black Pieces
    new Bishop(this, 1, 3, "BlackBishopLight", 1);
    new Bishop(this, 1, 6, "BlackBishopDark", 1);
    new Rook(this, 1, 1, "BlackRookLeft", 1);
    new Rook(this, 1, 8, "BlackRookRight", 1);
    new Knight(this, 1, 2, "BlackKnightLeft", 1);
    new Knight(this, 1, 7, "BlackKnightRight", 1);
    new Queen(this, 1, 4, "BlackQueen", 1);
    new King(this, 1, 5, "BlackKing", 1);
}

Tile *Board::getTile(int rank, int file)
{
    // Subtract 1 to convert from 1-based rank/file to 0-based array index
    return &board[rank - 1][file - 1];
}

int Board::getTurnOrder() {
    return turnOrder;
}

void Board::setTurnOrder() {
    if (turnOrder == 0) {
        turnOrder = 1;
    } else if (turnOrder == 1) {
        turnOrder = 0;
    }
}