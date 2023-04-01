cmake_minimum_required(VERSION 3.24)
project(fretMatrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(fretMatrix main.cpp Note.h util.cpp util.h)
