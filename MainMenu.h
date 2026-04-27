//
// Created by reach on 4/7/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_MAINMENU_H
#define JUSTANOTHERCHESSENGINE_MAINMENU_H

#include <wx/wx.h>
#include <vector>

class App; //forward definition, does not need to be included

class MainMenu : public wxPanel {
    public:
    //constructor
    MainMenu(wxWindow* parent, App* app);

    private:
    App* app;
    std::vector<wxString> options;
    std::vector<wxButton*> buttons;

    void onOption(wxCommandEvent& event);
};


#endif //JUSTANOTHERCHESSENGINE_MAINMENU_H