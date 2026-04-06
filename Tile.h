//
// Created by Dylan Williams on 3/31/2026.
//
// A Tile Class to hold Rank and File, or Y and X coordinates
// Will act as parent class for pieces, as all pieces must have a Rank and File
// Using Tile as a parent class will allow for the creation of a board or multi-dimensional array
// that has tiles and pieces.
// Tiles are otherwise immutable and they are only being used in logic to hold and pass on Rank and File
// information to pieces.

#ifndef JUSTANOTHERCHESSENGINE_TILE_H
#define JUSTANOTHERCHESSENGINE_TILE_H

#include "Piece.h"


class Tile {
private:
    int rank, file;
    Piece* piece; //nullptr if empty

public:
    //constructor
    Tile();
    Tile(int rank, int file);

    //check if tile is occupied
    bool isOccupied() const;

    //getters
    int getRank() const;
    int getFile() const;
    Piece* getPiece() const;

    //setters
    //should only be called for modifying Tiles created without arguments
    void setRank(int rank);
    void setFile(int file);
    void setPiece(Piece* piece);
};


#endif //JUSTANOTHERCHESSENGINE_TILE_H