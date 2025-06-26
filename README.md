##instruction to run the game : ##
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
This game uses the **FTXUI** library for its user interface. Install it from the official [FTXUI GitHub](https://github.com/ArthurSonzogni/FTXUI) page.
it's best to zoom out you'r Terminal for Cleaner view.

#### Install via CMake
Add this to your `CMakeLists.txt`:
```cmake
include(FetchContent)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG v4.1.1
)

FetchContent_MakeAvailable(ftxui)

target_link_libraries(<your-target> PRIVATE ftxui::screen ftxui::dom ftxui::component)
