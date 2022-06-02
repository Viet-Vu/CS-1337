cmake_minimum_required(VERSION 3.21)
project(TransactionManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(TransactionManagement main.cpp Account.cpp Account.h)
