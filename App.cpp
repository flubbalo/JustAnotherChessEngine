//
// Created by Dylan Williams on 4/6/2026.
//

#include "App.h"
#include <wx/sysopt.h>
#include "BoardPanel.h"
#include "Board.h"
#include "MainMenu.h"
#include "TestPiece.h"


wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    //ignore warning for now
    // wxSystemOptions::SetOption("msw.no-manifest-check", 1);

    board = new Board();


    //basic Frame or Window
    frame = new wxFrame(nullptr, wxID_ANY, "Just Another Chess Engine", wxDefaultPosition, wxSize(800, 800));

    //create new wxPanel object
    // wxPanel* panel = new wxPanel(frame);

    //create new wxBoxSizer object
    mainSizer = new wxBoxSizer(wxVERTICAL);
    frame->SetSizer(mainSizer);

    // MainMenu* mainMenu = new MainMenu(panel);

    // BoardPanel* boardPanel = new BoardPanel(panel, board);

    TestPiece* test = new TestPiece(board, 4, 4, "test");

    currentScene = nullptr;
    showScene(new MainMenu(frame, this));

    // sizer->Add(label, 0, wxALL, 10);   // 10px margin around label
    // sizer->Add(button, 0, wxALL, 10);  // 10px margin around button
    // sizer->Add(boardPanel, 1, wxEXPAND | wxALL, 10);
    // sizer->Add(output, 1, wxEXPAND | wxALL, 10);
    // currentScene->SetSizer(mainSizer);

    frame->Show();
    return true;
}

void App::showScene(wxPanel* scene) {
    if (currentScene != nullptr) {
        mainSizer->Detach(currentScene);
        currentScene->Destroy();
    }

    currentScene = scene;
    mainSizer->Add(currentScene, 1, wxEXPAND);
    mainSizer->Layout();
}

wxFrame* App::getFrame() {
    return frame;
}

Board* App::getBoard() {
    return board;
}