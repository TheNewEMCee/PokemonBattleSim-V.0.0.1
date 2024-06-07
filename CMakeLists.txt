cmake_minimum_required(VERSION 3.28)
project(PokemonBattleSim_V0_0_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(PokemonBattleSim_V0_0_4 main.cpp
        CVar.cpp
        CString.cpp
        CInt.cpp
        main.cpp
        Move.cpp
        Move.h)
