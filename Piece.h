//
// Created by Dylan Williams on 3/31/2026.
//
// A Piece parent class. Main distinction is that each piece has a team or color and a point value
// as well as a list of valid moves, stored as a vector.
// Piece class itself should not be called, but will be used as parent for each individual piece

#ifndef JUSTANOTHERCHESSENGINE_PIECE_H
#define JUSTANOTHERCHESSENGINE_PIECE_H


#include <string>
#include <vector>

class Tile; //forward declaration

class Piece {
private:
    int value;
    std::vector<Tile*> validMoves;
    std::string team;

public:
    //should not require a constructor so not included

    //getters
    int getValue() const;
    std::vector<Tile*> getValidMoves();
    std::string getTeam();

    //setters
};


#endif //JUSTANOTHERCHESSENGINE_PIECE_H