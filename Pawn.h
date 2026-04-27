#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <string>

class Pawn : public Piece {
private:
    Board* board;

public:
    Pawn(Board* board, int rank, int file, std::string name, int team);

    void calculateMoves() override;
};

#endif