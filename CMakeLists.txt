cmake_minimum_required(VERSION 4.1)
project(JustAnotherChessEngine)

set(CMAKE_CXX_STANDARD 20)

#set(wxWidgets_USE_STATIC ON)
#set(CMAKE_PREFIX_PATH "C:\\Users\\reach\\wxWidgets\\install-Debug\\lib\\cmake\\wxWidgets-3.3")
#
#find_package(wxWidgets CONFIG REQUIRED)
##include(${wxWidgets_USE_FILE})

add_executable(JustAnotherChessEngine main.cpp
        tile.cpp
        tile.h
        Piece.cpp
        Piece.h
        Board.cpp
        Board.h
        TestPiece.cpp
        TestPiece.h
        Rook.cpp
        Rook.h
        Bishop.cpp
        Bishop.h)
#target_link_libraries(JustAnotherChessEngine ${wxWidgets_LIBRARIES})