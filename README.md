This is a C++ project created for UCNJ class CST-117-081.2026SP Final Project.

Authored by [Dylan Williams](https://github.com/flubbalo) and [Cleiton Ribeiro De Oliveira](https://github.com/CleitonRBD).

This project is meant to demonstrate and utilize multiple common Object Oriented Programming concepts, including but not limited to Inheritance, Polymorphism, Encapsulation.
This project accomplishes this by aiming to be a self made chess engine wherein users can play chess.
Minimum Viable Product is having multiple types of pieces capable of moving about a board and interacting with each other.
Additional scope includes having a functional UI and chess AI to be able to play singleplayer.

Technologies utilized:
1. C++
2. Cmake
3. WxWidgets library

Setup:
In order to build this project on your own local machine, make sure you have CMake installed on your computer. You will need to first build and install the [WxWidgets library](https://docs.wxwidgets.org/3.2/overview_install.html) locally. Once that is setup, you can clone this repository to your local machine. You will have to manually configure CMakeLists.txt to look for the WxWidgets library headers where you installed them, and will need to move the assets directory to within the cmake-build-*BRANCH* directory. Once those steps have been accomplished, you should be able to modify and build this project locally.
