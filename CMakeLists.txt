cmake_minimum_required(VERSION 3.15)
project(horrify)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG  v6.1.9
)

FetchContent_MakeAvailable(ftxui)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(HorrifiedGame ${SOURCES} main.cpp)

target_link_libraries(HorrifiedGame PRIVATE 
    ftxui::screen 
    ftxui::dom 
    ftxui::component
)

set_target_properties(HorrifiedGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
