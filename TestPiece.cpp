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
}
// I made a change
void TestPiece::calculateMoves() {
    validMoves.clear();

    validMoves.push_back(board->getTile(rank + 2, file));
    validMoves.push_back(board->getTile(rank - 2, file));
    validMoves.push_back(board->getTile(rank, file + 2));
    validMoves.push_back(board->getTile(rank, file - 2));

    for (Tile* tile : validMoves) {
        std::cout << "Can move to:" << tile->getRank() << " " << tile->getFile() << std::endl;
    }
}
