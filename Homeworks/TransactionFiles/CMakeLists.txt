cmake_minimum_required(VERSION 3.21)
project(TransactionFiles)

set(CMAKE_CXX_STANDARD 14)

add_executable(TransactionFiles main.cpp Date.cpp Date.h Account.cpp Account.h)
