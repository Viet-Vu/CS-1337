cmake_minimum_required(VERSION 3.21)
project(Shapes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shapes main.cpp BasicShape.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h)
