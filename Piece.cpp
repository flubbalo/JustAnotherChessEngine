//
// Created by Dylan Williams on 3/31/2026.
//

#include "Piece.h"

int Piece::getValue() {
    return this->value;
}

std::vector<std::array<int, 2>> Piece::getValidMoves() {
    return this->validMoves;
}

std::string Piece::getTeam() {
    return this->team;
}
