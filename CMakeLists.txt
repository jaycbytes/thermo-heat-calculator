cmake_minimum_required(VERSION 3.10)
project(HeatCalculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(heat_calc
    main.cpp
    heatCalculator.cpp
)
