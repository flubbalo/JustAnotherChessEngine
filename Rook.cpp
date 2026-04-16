#include "Rook.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>

Rook::Rook(Board* board, int rank, int file, std::string name)
    : Piece(board, rank, file, name), board(board)
{
    board->getTile(rank, file)->setPiece(this);
}

void Rook::calculateMoves() {
    validMoves.clear();

    int directions[4][2] = {
        {1, 0},    // up
        {-1, 0},   // down
        {0, 1},    // right
        {0, -1}    // left
    };

    for (auto& dir : directions) {
        int r = rank;
        int f = file;

        while (true) {
            r += dir[0];
            f += dir[1];

            if (r < 1 || r > 8 || f < 1 || f > 8)
                break;

            Tile* tile = board->getTile(r, f);

            if (tile->getPiece() == nullptr) {
                validMoves.push_back(tile);
            }
            else {

                if (tile->getPiece()->getColor() != this->getColor()) {
                    validMoves.push_back(tile);
                }

                break;
            }
        }
    }
}