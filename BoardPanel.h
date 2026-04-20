//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_BOARDPANEL_H
#define JUSTANOTHERCHESSENGINE_BOARDPANEL_H

#include <wx/wx.h>
#include "Board.h"
#include <vector>
#include <map>

class BoardPanel : public wxPanel
{
public:
    BoardPanel(wxWindow* parent, Board* board);
    struct movementTiles {
        Tile* tileOrigin;
        Tile* tileDestination;
    };
    Tile* tileOriginTest;
    Tile* tileDestinationTest;

private:
    //called on construction
    void CreateButtons();

    //calls whatever logic is put into this function on click
    //current logic is to see if a piece is on the tile
    //if a piece is on the tile, it will update buttons in the list
    //to highlight where that piece can move and make those buttons selectable to move that piece
    //disables other buttons
    void OnTileClicked(wxCommandEvent& event);

    //funcion to execute piece movement
    void OnTileClickedTwo(wxCommandEvent& event);

    //function to undo piece selection
    void OnTileClickedOrigin(wxCommandEvent& event);

    //function to set image of button
    void SetImagePiece(wxButton* button, std::string imagePath);

    //function to refresh board state
    void RefreshBoard();
    Board* board;
    wxButton* buttons[8][8];
    std::vector<wxButton*> validButtons;
    std::map<wxButton*, Tile*> buttonTileMap;
};


#endif //JUSTANOTHERCHESSENGINE_BOARDPANEL_H