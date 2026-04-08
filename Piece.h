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
class Board;

class Piece {
protected:
    int value, rank, file;
    std::vector<Tile*> validMoves;
    std::string team;
    std::string name;
    Board* board;

public:
    Piece();
    Piece(Board* board, int rank, int file, std::string name);

    //getters
    int getValue() const;
    std::vector<Tile*> getValidMoves();
    std::string getTeam();
    std::string getName();

    //setters
};


#endif //JUSTANOTHERCHESSENGINE_PIECE_H