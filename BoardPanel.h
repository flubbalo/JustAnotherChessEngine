//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_BOARDPANEL_H
#define JUSTANOTHERCHESSENGINE_BOARDPANEL_H

#include <wx/wx.h>
#include "Tile.h"

class BoardPanel : public wxPanel
{
public:
    BoardPanel(wxWindow* parent, Tile board[8][8]);

private:
    void CreateButtons(Tile board[8][8]);
    void OnTileClicked(wxCommandEvent& event);

    wxButton* m_buttons[8][8];
};


#endif //JUSTANOTHERCHESSENGINE_BOARDPANEL_H