//
// Created by Dylan Williams on 3/31/2026.
//

#include "Piece.h"

Tile Piece::getTile() {
    return location;
}

int Piece::getValue() {
    return this->value;
}

std::vector<Tile> Piece::getValidMoves() {
    return this->validMoves;
}

std::string Piece::getTeam() {
    return this->team;
}

void Piece::setTile(Tile location) {
    this->location = location;
}
