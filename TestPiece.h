//
// Created by reach on 4/8/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_TESTPIECE_H
#define JUSTANOTHERCHESSENGINE_TESTPIECE_H

#include "Piece.h"


class TestPiece : public Piece{
public:
    TestPiece(Board* board, int rank, int file, std::string name, int team);
    void calculateMoves();

private:

    Board* board;
};


#endif //JUSTANOTHERCHESSENGINE_TESTPIECE_H