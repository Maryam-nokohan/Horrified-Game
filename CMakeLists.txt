cmake_minimum_required(VERSION 3.15)
project(horrify)

set(CMAKE_CXX_STANDARD 17)

find_package(ftxui COMPONENTS dom screen component REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(HorrifiedGame ${SOURCES} main.cpp)

target_link_libraries(HorrifiedGame PRIVATE ftxui::dom ftxui::screen ftxui::component)
