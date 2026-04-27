#include "Pawn.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>

Pawn::Pawn(Board* board, int rank, int file, std::string name, int team)
    : Piece(board, rank, file, name, team), board(board)
{
    board->getTile(rank, file)->setPiece(this);
}

void Pawn::calculateMoves() {
    validMoves.clear();

    int direction;

    if (this->getColor() == 0) {
        direction = 1;
    }
    else {
        direction = -1;
    }

    int newRank = rank + direction;

    if (newRank >= 1 && newRank <= 8) {
        Tile* forwardTile = board->getTile(newRank, file);

        if (forwardTile->getPiece() == nullptr) {
            validMoves.push_back(forwardTile);

            if ((this->getColor() == 0 && rank == 2) ||
                (this->getColor() == 1 && rank == 7)) {

                int doubleStepRank = rank + (2 * direction);
                Tile* doubleForwardTile = board->getTile(doubleStepRank, file);

                if (doubleForwardTile->getPiece() == nullptr) {
                    validMoves.push_back(doubleForwardTile);
                }
                }
        }
    }

    int leftFile = file - 1;

    if (newRank >= 1 && newRank <= 8 &&
        leftFile >= 1 && leftFile <= 8) {

        Tile* leftCapture = board->getTile(newRank, leftFile);

        if (leftCapture->getPiece() != nullptr &&
            leftCapture->getPiece()->getColor() != this->getColor()) {

            validMoves.push_back(leftCapture);
            }
        }

    int rightFile = file + 1;

    if (newRank >= 1 && newRank <= 8 &&
        rightFile >= 1 && rightFile <= 8) {

        Tile* rightCapture = board->getTile(newRank, rightFile);

        if (rightCapture->getPiece() != nullptr &&
            rightCapture->getPiece()->getColor() != this->getColor()) {

            validMoves.push_back(rightCapture);
            }
        }
}