cmake_minimum_required(VERSION 4.1)
project(jueguito)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib CONFIG REQUIRED)

# src glob,  meson doesnt have T.T
file(GLOB SRC src/*.cpp)
add_executable(jueguito ${SRC})
target_link_libraries(jueguito PRIVATE raylib)
