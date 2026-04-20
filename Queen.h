#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <string>

class Board;

class Queen : public Piece {
private:
    Board* board;

public:
    Queen(Board* board, int rank, int file, std::string name, int team);
    void calculateMoves() override;
};

#endif
