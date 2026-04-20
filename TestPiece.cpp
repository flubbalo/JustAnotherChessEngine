//
// Created by reach on 4/8/2026.
//

#include "TestPiece.h"
#include "Board.h"
#include <iostream>

//Piece(board, rank, file, name)

TestPiece::TestPiece(Board *board, int rank, int file, std::string name, int team) : Piece(board, rank, file, name, team), board(board) {
    board->getTile(rank, file)->setPiece(this);
    // this->name = name;
    // this->rank = rank;
    // this->file = file;
    if (team == 0) {
        this->imagePath = "assets/testPieceWhite.png";
    } else if (team == 1) {
        this->imagePath = "assets/testPieceBlack.png";
    }

}
// I made a change
void TestPiece::calculateMoves() {
    validMoves.clear();

    if (rank <= 6) {
        if (!isOccupied(board->getTile(rank + 2, file))) {
            validMoves.push_back(board->getTile(rank + 2, file));
        }
    }
    if (rank >= 3) {
        if (!isOccupied(board->getTile(rank - 2, file))) {
            validMoves.push_back(board->getTile(rank - 2, file));
        }
    }
    if (file <= 6) {
        if (!isOccupied(board->getTile(rank, file + 2))) {
            validMoves.push_back(board->getTile(rank, file + 2));
        }
    }
    if (file >= 3) {
        if (!isOccupied(board->getTile(rank, file - 2))) {
            validMoves.push_back(board->getTile(rank, file - 2));
        }
    }

    // std::cout << std::endl << "NEW CALL OF CALCULATE MOVES" << std::endl;
    // for (Tile* tile : validMoves) {
    //     std::cout << "Memory address of tile: " << tile << std::endl;
    //     std::cout << "Can move to:" << tile->getRank() << " " << tile->getFile() << std::endl;
    // }
}
