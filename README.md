# Horrified Game

A terminal-based cooperative adventure inspired by the classic **Horrified** tabletop game, built in C++ using the [FTXUI](https://github.com/ArthurSonzogni/FTXUI) library.

## 📖 Game Overview
Play as one of the available heroes (Mayor or Archaeologist), move across locations, rescue villagers, defeat monsters like **Dracula** and the **Invisible Man**, and save the town!

## ⚡ Features
- Interactive Terminal User Interface using **FTXUI**.
- Multiple playable heroes.
- Detailed map and status display.
- Dynamic hero, monster, and villager interactions.

---

## 🚀 Instructions to Run the Game

### 1️⃣ Install FTXUI
This game uses the **FTXUI** library for its user interface. Install it from the official [FTXUI GitHub](https://github.com/ArthurSonzogni/FTXUI) page or use the CMakeList.txt below.
it's best to zoom out your Terminal and set it to the full screen for a Cleaner gamePlay.

#### Install via CMake
Add this to your `CMakeLists.txt`:
```cmake
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
```
### 2️⃣ Build the project  
Run the following commands in your build directory:
```bash
cmake -S . -B build
```
### 3️⃣ Run the game
```bash
cd build/
./bin/HorrifiedGame
```
