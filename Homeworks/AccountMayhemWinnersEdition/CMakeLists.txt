cmake_minimum_required(VERSION 3.21)
project(AccountMayhem)

set(CMAKE_CXX_STANDARD 14)

add_executable(AccountMayhemWinnersEdition main.cpp Account.cpp Account.h PremiumAccount.cpp PremiumAccount.h RegularAccount.cpp RegularAccount.h Date.cpp Date.h Common.h)
