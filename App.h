//
// Created by Dylan Williams on 4/6/2026.
//

#ifndef JUSTANOTHERCHESSENGINE_APP_H
#define JUSTANOTHERCHESSENGINE_APP_H

// #pragma once
#include <wx/wx.h>

//replaces int main() as the driving method
class App : public wxApp
{
public:
    virtual bool OnInit();
};

#endif //JUSTANOTHERCHESSENGINE_APP_H