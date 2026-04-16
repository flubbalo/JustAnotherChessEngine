#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <string>

class Board;

class Bishop : public Piece {
private:
    Board* board;

public:
    Bishop(Board* board, int rank, int file, std::string name);
    void calculateMoves() override;
};

#endif
