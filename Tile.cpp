//
// Created by Dylan Williams on 3/31/2026.
//

#include "Tile.h"

Tile::Tile() {
    this->rank = 0;
    this->file = 0;
}

Tile::Tile(int rank, int file) {
    this->rank = rank;
    this->file = file;
}

int Tile::getRank() {
    return this->rank;
}

int Tile::getFile() {
    return this->file;
}

void Tile::setRank(int rank) {
    this->rank = rank;
}

void Tile::setFile(int file) {
    this->file = file;
}