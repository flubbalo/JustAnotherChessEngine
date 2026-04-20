#include "Knight.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>

Knight::Knight(Board* board, int rank, int file, std::string name, int team)
    : Piece(board, rank, file, name, team ), board(board)
{
    board->getTile(rank, file)->setPiece(this);
    if (team == 0) {
        this->imagePath = "assets/testPieceWhite.png";
    } else if (team == 1) {
        this->imagePath = "assets/testPieceBlack.png";
    }
}

void Knight::calculateMoves() {
    validMoves.clear();

    int moves[8][2] = {
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2}
    };

    for (auto& move : moves) {
        int r = rank + move[0];
        int f = file + move[1];

        if (r >= 1 && r <= 8 && f >= 1 && f <= 8) {
            Tile* tile = board->getTile(r, f);
            \
            if (tile->getPiece() == nullptr) {
                validMoves.push_back(tile);
            }
            else {

                if (tile->getPiece()->getTeam() != this->getTeam()) {
                    validMoves.push_back(tile);
                }
            }
        }
    }
}