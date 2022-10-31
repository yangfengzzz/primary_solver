cmake_minimum_required(VERSION 3.23)
project(primary_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(solver main.cpp Solver.cpp Solver.h)
