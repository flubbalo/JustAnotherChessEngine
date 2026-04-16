#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <string>

class Board;

class King : public Piece {
private:
    Board* board;

public:
    King(Board* board, int rank, int file, std::string name, int team);
    void calculateMoves() override;
};

#endif
