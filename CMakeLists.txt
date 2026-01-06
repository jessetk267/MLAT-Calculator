cmake_minimum_required(VERSION 3.15)
project(mlat_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

pybind11_add_module(mlat_cpp
    src/bindings.cpp
    src/mlat.cpp
)

target_link_libraries(mlat_cpp
    PRIVATE
        Python3::Python
        Eigen3::Eigen
)