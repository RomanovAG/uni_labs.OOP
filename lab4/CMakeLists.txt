cmake_minimum_required(VERSION 3.5)

project(lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab4
    main.cpp
    Pieces/piece.h  Pieces/piece.cpp
    Pieces/king.h   Pieces/king.cpp
    Pieces/queen.h  Pieces/queen.cpp
    Pieces/rook.h   Pieces/rook.cpp
    Pieces/knight.h Pieces/knight.cpp
    Pieces/bishop.h Pieces/bishop.cpp
    Pieces/pawn.h   Pieces/pawn.cpp
    game.h game.cpp
    clock.h clock.cpp
    player.h player.cpp
    gamehistory.h gamehistory.cpp
    Pieces/position.h Pieces/position.cpp
    dialog.h dialog.cpp
    Pieces/myarray.h
    )
