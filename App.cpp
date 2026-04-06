//
// Created by Dylan Williams on 4/6/2026.
//

#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "My App", wxDefaultPosition, wxSize(800, 600));
    frame->Show();
    return true;
}