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
    int value, rank, file, team;
    std::vector<Tile*> validMoves;
    std::string name;
    std::string imagePath;
    Board* board;

    //function for checking if a tile is occupied to be used inside calculate moves
    //takes as input a Tile
    //checks if tile is empty or not
    //checks if tile is not empty, if piece is on other team
    //returns bool
    //returns TRUE if tile IS NOT VALID because of occupied piece
    bool isOccupied(Tile* tile);


public:
    Piece();
    Piece(Board* board, int rank, int file, std::string name, int team);

    //getter
    int getValue() const;
    std::vector<Tile*> getValidMoves();
    int getTeam();
    std::string getTeam(std::string x);
    std::string getName();
    std::string getImagePath();


    void movePiece();
    void movePiece(Tile* tileOrigin, Tile* tileTarget);

    //setters

    //declared so can be universally called but not defined because not necessary
    virtual void calculateMoves() = 0;



};


#endif //JUSTANOTHERCHESSENGINE_PIECE_H