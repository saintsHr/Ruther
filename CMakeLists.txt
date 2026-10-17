cmake_minimum_required(VERSION 3.16)

project(Ruther
    LANGUAGES CXX
    VERSION 0.0.0
)

find_package(raylib REQUIRED)

set(SOURCES
    src/main.cpp
)

add_executable(ruther ${SOURCES})

target_include_directories(ruther PRIVATE include)
target_link_libraries(ruther PRIVATE raylib)
