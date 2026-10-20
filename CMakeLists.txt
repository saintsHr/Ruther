cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Ruther
    LANGUAGES CXX
    VERSION 0.0.0
)

find_package(raylib REQUIRED)

set(SOURCES
    src/ruther/main.cpp
    src/ruther/renderer/renderer.cpp
    src/ruther/particle/particle.cpp
    src/ruther/input/input.cpp
    src/ruther/simulation/simulation.cpp
)

add_executable(ruther ${SOURCES})

target_include_directories(ruther PRIVATE include)
target_link_libraries(ruther PRIVATE raylib)
