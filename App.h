//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_APP_H
#define JUSTANOTHERCHESSENGINE_APP_H

// #pragma once
#include <wx/wx.h>

#include "Board.h"

//replaces int main() as the driving method
class App : public wxApp
{
public:
    virtual bool OnInit();
    void showScene(wxPanel* scene);
    wxFrame* getFrame();
    Board* getBoard();

private:
    Board* board;
    wxFrame* frame;
    wxPanel* currentScene;
    wxBoxSizer* mainSizer;
};

#endif //JUSTANOTHERCHESSENGINE_APP_H