//
// Created by Dylan Williams on 4/6/2026.
//

#include "BoardPanel.h"

BoardPanel::BoardPanel(wxWindow* parent, Board* board)
    : wxPanel(parent), m_board(board)
{
    CreateButtons();
}

void BoardPanel::CreateButtons()
{
    wxGridSizer* grid = new wxGridSizer(8, 8, 0, 0);

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Tile& tile = m_board->getTile(y + 1, x + 1);
            wxString label = wxString::Format("R%d F%d", tile.getRank(), tile.getFile());
            m_buttons[y][x] = new wxButton(this, wxID_ANY, label);
            m_buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
            grid->Add(m_buttons[y][x], 1, wxEXPAND);
        }
    }

    SetSizer(grid);
}

void BoardPanel::OnTileClicked(wxCommandEvent& event)
{
    wxButton* clicked = dynamic_cast<wxButton*>(event.GetEventObject());
    wxMessageBox("Clicked: " + clicked->GetLabel());
}