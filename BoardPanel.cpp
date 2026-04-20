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

            if (tile->getPiece() != nullptr)
                SetImagePiece(buttons[y][x], tile->getPiece()->getImagePath());


            if (counter % 2 == 0) {
                buttons[y][x]->SetBackgroundColour(wxColour(255,0,0));
            } else {
                buttons[y][x]->SetBackgroundColour(wxColour(0,0,255));
            }
            buttonTileMap[buttons[y][x]] = tile;

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
    Tile* tile = buttonTileMap[clicked];
    std::vector<Tile*> validMoves;
    // wxMessageBox("Clicked: " + clicked->GetLabel());
    // //will invert colors
    // clicked->SetBackgroundColour(wxColour(clicked->GetBackgroundColour().GetBlue(),0,clicked->GetBackgroundColour().GetRed()));
    if (tile->getPiece() != nullptr) {
        wxMessageBox("Tile " + clicked->GetLabel() + " has a " + tile->getPiece()->getTeam("team") + " " + tile->getPiece()->getName());
        //further to do
        //call calculate moves
        tile->getPiece()->calculateMoves();
        validMoves = tile->getPiece()->getValidMoves();
        //display calculated moves
        for (Tile* tileTest : validMoves) {
            //find Button with corresponding Tile
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    //unbind buttons
                    buttons[j][i]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);

                    //bind valid moves to new function of onTileClickedTwo, pass it the origin tile
                    if (tileTest == buttonTileMap[buttons[j][i]]) {
                        // buttons[j][i]->SetBackgroundColour(wxColour(0,255,0));
                        buttons[j][i]->SetForegroundColour(wxColour(0,255,0));
                        buttons[j][i]->SetClientData(tile);


                        //set these buttons to have a different function on the click event
                        buttons[j][i]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClickedTwo, this);
                    }
                }
            }
            //change Button color
        }
        clicked->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClickedOrigin, this);

        //set current button to reset to original boardpanel state

    } else {
        wxMessageBox("Tile" + clicked->GetLabel() + " has nothing.");
    }
}

void BoardPanel::OnTileClickedTwo(wxCommandEvent &event) {
    wxButton* clicked = dynamic_cast<wxButton*>(event.GetEventObject());
    wxMessageBox("Can move here");
    Tile* tileDestination = buttonTileMap[clicked];
    Tile* tileOrigin = static_cast<Tile*>(clicked->GetClientData());
    tileOrigin->getPiece()->movePiece(tileOrigin, tileDestination);

    //reset board state
    RefreshBoard();
    // for (int y = 0; y < 8; y++) {
    //     for (int x = 0; x < 8; x++) {
    //         buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
    //         buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedTwo, this);
    //         buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedOrigin, this);
    //         buttons[y][x]->SetForegroundColour(wxColour(0,0,0));
    //     }
    // }
}

void BoardPanel::OnTileClickedOrigin(wxCommandEvent &event) {
    RefreshBoard();
    wxMessageBox("Undo piece selection");
}

void BoardPanel::SetImagePiece(wxButton *button, std::string imagePath) {
    wxImage image(imagePath, wxBITMAP_TYPE_PNG);

    image = image.Scale(80, 80, wxIMAGE_QUALITY_HIGH);
    wxBitmap bitmap(image);
    button->SetBitmap(bitmap);
    // button->SetBitmapPosition();
}

void BoardPanel::RefreshBoard() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Tile* tile = board->getTile(y + 1, x + 1);
            buttons[y][x]->SetBitmap(wxNullBitmap);
            buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
            buttons[y][x]->SetForegroundColour(wxColour(0,0,0));
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedTwo, this);
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedOrigin, this);

            if (tile->getPiece() != nullptr) {
                SetImagePiece(buttons[y][x], tile->getPiece()->getImagePath());
            }
        }
    }
    Refresh();
}