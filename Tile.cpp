//
// Created by Dylan Williams on 3/31/2026.
//

#include "Tile.h"

Tile::Tile() {
    this->rank = 0;
    this->file = 0;
    this->piece = nullptr;
}

Tile::Tile(int rank, int file) {
    this->rank = rank;
    this->file = file;
    this->piece = nullptr;
}

bool Tile::isOccupied() const {
    return piece != nullptr;
}

int Tile::getRank() const {
    return this->rank;
}

int Tile::getFile() const {
    return this->file;
}

Piece* Tile::getPiece() const {
    return this->piece;
}

void Tile::setRank(int rank) {
    this->rank = rank;
}

void Tile::setFile(int file) {
    this->file = file;
}

void Tile::setPiece(Piece* piece) {
    this->piece = piece;
}
