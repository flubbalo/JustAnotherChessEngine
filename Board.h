//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_BOARD_H
#define JUSTANOTHERCHESSENGINE_BOARD_H
#include "Tile.h"


class Board {
public:
    Board();

    //returns Tile object, not reference
    Tile *getTile(int rank, int file);

    //getter
    int getTurnOrder();

    //setter
    void setTurnOrder();


private:
    void initBoard();

    Tile board[8][8];

    int turnOrder;

};


#endif //JUSTANOTHERCHESSENGINE_BOARD_H