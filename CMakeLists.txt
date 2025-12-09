cmake_minimum_required(VERSION 4.1)
project(jueguito)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL3 REQUIRED)
add_executable(jueguito main.cpp)
target_link_libraries(jueguito PRIVATE SDL3::SDL3)