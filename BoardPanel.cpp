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
    std::vector<Tile*> validMoves;
    // wxMessageBox("Clicked: " + clicked->GetLabel());
    // //will invert colors
    // clicked->SetBackgroundColour(wxColour(clicked->GetBackgroundColour().GetBlue(),0,clicked->GetBackgroundColour().GetRed()));
    if (tile->getPiece() != nullptr) {
        wxMessageBox("Tile " + clicked->GetLabel() + " has a " + tile->getPiece()->getName());
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
                    if (tileTest == buttons[j][i]->GetClientData() ) {
                        // validButtons.push_back(buttons[i][j]);
                        buttons[j][i]->SetBackgroundColour(wxColour(0,255,0));
                        // movementTiles& test;

                        //THIS IS THE SOURCE OF THE BUG
                        //SINCE IT IS IN A FOR LOOP IT ONLY EVER REMEMBERS THE LAST PIECE USED IN THE ARRAY
                        //NEED DIFFERENT WAY TO PASS THESE TILES TO BUTTON FUNCTION TWO
                        // std::cout << "Created tiles object" << std::endl;
                        tileOriginTest = tile;
                        // std::cout << "Set Tile Origin in tiles object" << std::endl;
                        tileDestinationTest = tileTest;
                        // std::cout << "Set Tile Destination in tiles object" << std::endl;
                        // buttons[i][j]->SetClientData(test);
                        // std::cout << "Set button client data" << std::endl;
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
    // Tile* tileTarget = static_cast<Tile*>(clicked->GetClientData());
    // // //need to get tileOrigin passed in here somehow
    // tileOrigin->getPiece()->movePiece(tileOrigin, tileTarget);
    // movementTiles* test = static_cast<movementTiles*>(clicked->GetClientData());
    // std::cout << "Passed group of tiles" << std::endl;
    // Tile* tileOrigin = test->tileOrigin;
    // std::cout << "Set Tile Origin" << std::endl;
    // Tile* tileDestination = test->tileDestination;
    // std::cout << "Set Tile Destination" << std::endl;
    tileOriginTest->getPiece()->movePiece(tileOriginTest, tileDestinationTest);

    //reset board state
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
            // Tile* tile = board->getTile(y + 1, x + 1);
            // buttons[y][x]->SetClientData(tile);
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedTwo, this);
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedOrigin, this);
        }
    }

    tileOriginTest = nullptr;
    tileDestinationTest = nullptr;
}

void BoardPanel::OnTileClickedOrigin(wxCommandEvent &event) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            buttons[y][x]->Bind(wxEVT_BUTTON, &BoardPanel::OnTileClicked, this);
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedTwo, this);
            buttons[y][x]->Unbind(wxEVT_BUTTON, &BoardPanel::OnTileClickedOrigin, this);
            Tile* tile = board->getTile(y + 1, x + 1);
            buttons[y][x]->SetClientData(tile);
        }
    }
    wxMessageBox("Undo piece selection");
}
