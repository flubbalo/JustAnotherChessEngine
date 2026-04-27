#include "Queen.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>

Queen::Queen(Board* board, int rank, int file, std::string name, int team)
    : Piece(board, rank, file, name, team), board(board)
{
    board->getTile(rank, file)->setPiece(this);
    if (team == 0) {
        this->imagePath = "assets/whitequeen.png";
    } else if (team == 1) {
        this->imagePath = "assets/blackqueen.png";
    }
}

void Queen::calculateMoves() {
    validMoves.clear();

    int directions[8][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}
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

                if (tile->getPiece()->getTeam() != this->getTeam()) {
                    validMoves.push_back(tile);
                }

                break;
            }
        }
    }
}