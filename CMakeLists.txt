cmake_minimum_required(VERSION 3.15)
project(fourier)

set(CMAKE_CXX_STANDARD 20)

add_executable(fourier main.cpp DFT.cpp DFT.h WaveFactory.cpp WaveFactory.h NyquistLimitException.h)