cmake_minimum_required(VERSION 3.15)
project(horrify)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(HorrifiedGame ${SOURCES} main.cpp)

target_link_libraries(HorrifiedGame PRIVATE
    raylib
    m
    pthread
    dl
    rt
    X11
)

set_target_properties(HorrifiedGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
