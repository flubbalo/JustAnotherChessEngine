#include <iostream>
#include "Tile.h"
#include "Board.h"
#include "Piece.h"
#include "TestPiece.h"

using namespace std;

// static Tile board[8][8];
void testTilePiece(Board* board, int rank, int file);

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    // Because of the nature of 2 dimensional arrays
    // y must come first
    // Y coord is the same as a tiles rank
    // X coord is the same as a tiles file
    // for (int y = 0; y < 8; y++) {
    //     for (int x = 0; x < 8; x++) {
    //         board[y][x].setFile(x + 1);
    //         board[y][x].setRank(y + 1);
    //     }
    // }

    //for testing purposes, a Rank and File should be +1 over their array values
    // cout << "Rank = " << board[0][0].getRank() << ", File = " << board[0][0].getFile() << endl; //should out 1 and 1
    // cout << "Rank = " << board[3][5].getRank() << ", File = " << board[3][5].getFile() << endl; //should out 4 and 6
    // cout << "Rank = " << board[7][7].getRank() << ", File = " << board[7][7].getFile() << endl; //should out 8 and 8

    Board* board = new Board();

    new TestPiece(board, 4, 4, "test");

    testTilePiece(board, 4, 4);

    board->getTile(4,4)->getPiece()->calculateMoves();
    board->getTile(4,4)->getPiece()->movePiece();

    testTilePiece(board, 2, 4);
    testTilePiece(board, 4, 4);


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}

void testTilePiece(Board* board, int rank, int file) {
    if (board->getTile(rank,file)->getPiece() != nullptr) {
        cout << "Piece at " << rank << "," << file << ": " << board->getTile(4,4)->getPiece()->getName() << endl;
    } else {
        cout << "Piece at " << rank << "," << file << ": NULL" << endl;
    }
}