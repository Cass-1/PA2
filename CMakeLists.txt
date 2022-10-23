cmake_minimum_required(VERSION 3.16)
project(PA2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA2
        main.cpp AVLNode.h AVLTree.h)
