cmake_minimum_required(VERSION 3.15)
project(MCTS_TSP)

set(CMAKE_CXX_STANDARD 14)

add_executable(MCTS_TSP
        main.cpp
        src/Node.cpp
        include/Node.h
        include/Tree.h
        src/Tree.cpp
        src/MCTS.cpp
        include/MCTS.h)