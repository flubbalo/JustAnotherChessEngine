//
// Created by Dylan Williams on 3/31/2026.
//

#include "Piece.h"
#include <iostream>
#include "Board.h"

Piece::Piece() {

}

Piece::Piece(Board *board, int rank, int file, std::string name) : board(board), rank(rank), file(file) {
    board->getTile(rank, file)->setPiece(this);
    this->name = name;
}

int Piece::getValue() const {
    return this->value;
}

std::vector<Tile*> Piece::getValidMoves() {
    return this->validMoves;
}

std::string Piece::getTeam() {
    return this->team;
}

std::string Piece::getName() {
    return this->name;
}

void Piece::movePiece() {
    std::cout << "Pick a Move:" << std::endl;
    int selection;
    int counter = 1;
    for (Tile* tile : this->validMoves) {
        std::cout << counter << ": Rank" << tile->getRank() << ", File" << tile->getFile() << std::endl;
        counter++;
    }

    std::cin >> selection;

    //move piece to new location
    board->getTile(validMoves[selection - 1]->getRank(), validMoves[selection - 1]->getFile())->setPiece(this);
    std::cout << "Piece moved" << std::endl;
    //remove piece from current location
    board->getTile(rank, file)->setPiece(nullptr);
    std::cout << "Pointer removed" << std::endl;
    //update Rank and File of piece
    this->rank = validMoves[selection - 1]->getRank();
    this->file = validMoves[selection - 1]->getFile();
    std::cout << "Rank and file updated" << std::endl;
}

void Piece::movePiece(Tile* tileOrigin, Tile* tileTarget) {
    board->getTile(tileTarget->getRank(), tileTarget->getFile())->setPiece(this);
    board->getTile(tileOrigin->getRank(), tileOrigin->getFile())->setPiece(nullptr);
    this->rank = tileTarget->getRank();
    this->file = tileTarget->getFile();
}