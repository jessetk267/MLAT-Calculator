cmake_minimum_required(VERSION 3.13)
project(cmake_mlat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

add_library(mlat STATIC src/mlat.cpp)

target_link_libraries(mlat PUBLIC Eigen3::Eigen)

set_target_properties(mlat PROPERTIES POSITION_INDEPENDENT ON)

pybind11_add_module(cmake_mlat src/bindings.cpp)

target_link_libraries(cmake_mlat PRIVATE mlat)