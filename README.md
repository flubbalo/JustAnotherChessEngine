This is a C++ project created for UCNJ class CST-117-081.2026SP Final Project.

Authored by Dylan Williams and Cleiton Ribeiro De Oliveira.

This project is meant to demonstrate and utilize multiple common Object Oriented Programming concepts, including but not limited to Inheritance, Polymorphism, Encapsulation.
This project accomplishes this by aiming to be a self made chess engine wherein users can play chess.
Minimum Viable Product is having multiple types of pieces capable of moving about a board and interacting with each other.
Additional scope includes having a functional UI and chess AI to be able to play singleplayer.

Technologies utilized:
C++
Cmake
WxWidgets library

Setup:
In order to build this project on your own local machine, you will need to first build and install the [WxWidgets library](https://docs.wxwidgets.org/3.2/overview_install.html) locally. Once that is setup, you can clone this repository to your local machine. You will have to manually configure CMakeLists.txt to look for the WxWidgets library headers where you installed them, and will need to create your own assets within the cmake-build-*BRANCH*/assets directory for each piece. Once those steps have been accomplished, you should be able to modify and build this project locally.
