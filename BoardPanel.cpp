//
// Created by Dylan Williams on 4/6/2026.
//

#include "BoardPanel.h"

BoardPanel::BoardPanel(wxWindow* parent, Board* board)
    : wxPanel(parent), board(board)
{
    CreateButtons();
}

void BoardPanel::CreateButtons()
{
    wxGridSizer* grid = new wxGridSizer(8, 8, 0, 0);

    int counter = 1;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Tile* tile = board->getTile(y + 1, x + 1);
            wxString label = wxString::Format("R%d F%d", tile->getRank(), tile->getFile());
            buttons[y][x] = new wxButton(this, wxID_ANY, label);
            buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
            if (counter % 2 == 0) {
                buttons[y][x]->SetBackgroundColour(wxColour(255,0,0));
            } else {
                buttons[y][x]->SetBackgroundColour(wxColour(0,0,255));
            }
            buttons[y][x]->SetClientData(tile);

            grid->Add(buttons[y][x], 1, wxEXPAND);
            counter++;
        }
        counter ++;
    }

    SetSizer(grid);
}

void BoardPanel::OnTileClicked(wxCommandEvent& event)
{
    wxButton* clicked = dynamic_cast<wxButton*>(event.GetEventObject());
    Tile* tile = static_cast<Tile*>(clicked->GetClientData());
    // wxMessageBox("Clicked: " + clicked->GetLabel());
    // //will invert colors
    // clicked->SetBackgroundColour(wxColour(clicked->GetBackgroundColour().GetBlue(),0,clicked->GetBackgroundColour().GetRed()));
    if (tile->getPiece() != nullptr) {
        wxMessageBox("Tile " + clicked->GetLabel() + " has a " + tile->getPiece()->getName());
    } else {
        wxMessageBox("Tile" + clicked->GetLabel() + " has nothing.");
    }
}