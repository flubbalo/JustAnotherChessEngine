#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>

class Board;

class Rook : public Piece {
private:
    Board* board;

public:
    Rook(Board* board, int rank, int file, std::string name);
    void calculateMoves() override;
};

#endif
  