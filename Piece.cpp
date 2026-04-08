//
// Created by Dylan Williams on 3/31/2026.
//

#include "Piece.h"

#include "Board.h"

Piece::Piece() {

}

Piece::Piece(Board *board, int rank, int file, std::string name) : board(board) {
    board->getTile(rank, file)->setPiece(this);
    this->name = name;
}

int Piece::getValue() const {
    return this->value;
}

std::vector<Tile*> Piece::getValidMoves() {
    return this->validMoves;
}

std::string Piece::getTeam() {
    return this->team;
}

std::string Piece::getName() {
    return this->name;
}