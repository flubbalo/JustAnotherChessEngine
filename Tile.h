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


class Tile {
private:
    int rank, file;

public:
    //constructor
    Tile(int rank, int file);

    //getters
    int getRank();
    int getFile();
};


#endif //JUSTANOTHERCHESSENGINE_TILE_H