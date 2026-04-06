//
// Created by Dylan Williams on 4/6/2026.
//

#include "App.h"
#include <wx/sysopt.h>
#include "BoardPanel.h"
#include "Board.h"


wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    //ignore warning for now
    wxSystemOptions::SetOption("msw.no-manifest-check", 1);

    board = new Board();

    //testing output
    // wxString testOut;
    //
    // testOut += wxString::Format("Rank = %d, File = %d\n", board[0][0].getRank(), board[0][0].getFile());
    // testOut += wxString::Format("Rank = %d, File = %d\n", board[5][3].getRank(), board[5][3].getFile());
    // testOut += wxString::Format("Rank = %d, File = %d\n", board[7][7].getRank(), board[7][7].getFile());

    //basic Frame or Window
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "JustAnotherChessEngine", wxDefaultPosition, wxSize(800, 600));

    //create new wxPanel object
    wxPanel* panel = new wxPanel(frame);

    //create new wxBoxSizer object
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Display board info in a read-only text box
    // wxTextCtrl* output = new wxTextCtrl(panel, wxID_ANY, testOut, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

    // // Add a text label
    // wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Hello, World!");
    //
    // // Add a button
    // wxButton* button = new wxButton(panel, wxID_ANY, "Where button");
    //
    // //implement button event
    // button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
    //     wxMessageBox("Button was clicked!");
    // });

    BoardPanel* boardPanel = new BoardPanel(panel, board);


    // sizer->Add(label, 0, wxALL, 10);   // 10px margin around label
    // sizer->Add(button, 0, wxALL, 10);  // 10px margin around button
    sizer->Add(boardPanel, 1, wxEXPAND | wxALL, 10);
    // sizer->Add(output, 1, wxEXPAND | wxALL, 10);
    panel->SetSizer(sizer);

    frame->Show();
    return true;
}