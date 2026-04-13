//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_BOARDPANEL_H
#define JUSTANOTHERCHESSENGINE_BOARDPANEL_H

#include <wx/wx.h>
#include "Board.h"
#include <vector>

class BoardPanel : public wxPanel
{
public:
    BoardPanel(wxWindow* parent, Board* board);

private:
    //called on construction
    void CreateButtons();

    //calls whatever logic is put into this function on click
    void OnTileClicked(wxCommandEvent& event);

    Board* board;
    wxButton* buttons[8][8];
    std::vector<wxButton*> validButtons;
};


#endif //JUSTANOTHERCHESSENGINE_BOARDPANEL_H