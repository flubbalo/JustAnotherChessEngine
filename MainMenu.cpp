//
// Created by reach on 4/7/2026.
//

#include "MainMenu.h"


MainMenu::MainMenu(wxWindow *parent, App *app) {

    options.push_back("Singleplayer");
    options.push_back("Two player");
    options.push_back("Settings");

    int counter = 0;
    for (wxString option : options) {
        buttons.push_back(new wxButton(this, wxID_ANY, option));
        buttons[counter]->Bind(wxEVT_BUTTON, &MainMenu::onOption, this);
    }

    wxGridSizer* list = new wxGridSizer(buttons.size(), 1, 0, 0);
    for (int i = 0; i < buttons.size(); i++) {
        list->Add(buttons[i], 0, wxEXPAND);
    }


    SetSizer(list);
}

void MainMenu::onOption(wxCommandEvent& event) {
    wxButton* clicked = dynamic_cast<wxButton*>(event.GetEventObject());
    wxMessageBox("Clicked: " + clicked->GetLabel());
}