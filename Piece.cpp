//
// Created by Dylan Williams on 3/31/2026.
//

#include "Piece.h"
#include <iostream>
#include "Board.h"

Piece::Piece() {

}

Piece::Piece(Board *board, int rank, int file, std::string name, int team) : board(board), rank(rank), file(file), team(team) {
    board->getTile(rank, file)->setPiece(this);
    this->name = name;
}

int Piece::getValue() const {
    return this->value;
}

std::vector<Tile*> Piece::getValidMoves() {
    return this->validMoves;
}

int Piece::getTeam() {
    return this->team;
}

std::string Piece::getTeam(std::string x) {
    if (this->team == 0) {
        return "White";
    } else if (this->team == 1) {
        return "Black";
    } else {
        return "No Team";
    }
}

std::string Piece::getName() {
    return this->name;
}

std::string Piece::getImagePath() {
    return this->imagePath;
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
    // std::cout << "Current piece pointer is: " << this << std::endl;
    board->getTile(tileTarget->getRank(), tileTarget->getFile())->setPiece(this);
    // std::cout << "Successfully moved piece" << std::endl;
    // std::cout << "Target tile piece is: " << tileTarget->getPiece() << std::endl;
    board->getTile(tileOrigin->getRank(), tileOrigin->getFile())->setPiece(nullptr);
    // std::cout << "Piece removed from origin" << std::endl;
    this->rank = tileTarget->getRank();
    // std::cout << "Set new rank" << std::endl;
    this->file = tileTarget->getFile();
    // std::cout << "Set new file" << std::endl;
    board->setTurnOrder();
}

bool Piece::isOccupied(Tile* tile) {
    //check if tile has piece
    if (tile->getPiece() != nullptr) {
        //there is a piece
        //check piece team
        if (tile->getPiece()->getTeam() == this->team) {
            //if piece matches team, return true
            //SAME TEAM, CANNOT MOVE
            return true;
        } else {
            //piece does not match, move is still valid
            //ENEMY TEAM, CAN MOVE
            return false;
        }
    } else {
        //EMPTY SPACE, CAN MOVE
        return false;
    }
}
