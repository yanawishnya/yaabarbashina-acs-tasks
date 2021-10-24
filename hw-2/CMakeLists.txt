cmake_minimum_required(VERSION 3.20)
project(avs_dz2)

set(CMAKE_CXX_STANDARD 17)

add_executable(avs_dz2 main.cpp container.h container.cpp text.cpp text.h digits.cpp digits.h swap.cpp swap.h shift.cpp shift.h rnd.h)
