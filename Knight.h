#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <string>

class Board;

class Knight : public Piece {
private:
    Board* board;

public:
    Knight(Board* board, int rank, int file, std::string name);
    void calculateMoves() override;
};

#endif
