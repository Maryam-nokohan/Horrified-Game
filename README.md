Here’s the complete README.md file for your Horrified Game (Raylib version).
You can copy this into your repository root as README.md.

# Horrified Game (Graphic Version)

A graphic, cooperative adventure game inspired by the classic _Horrified_ tabletop game, built in C++ using Raylib for rendering and UI.

---

## 📖 Overview

In Horrified Game – Graphic Version, players take on the roles of unique heroes navigating a mysterious town.  
You must rescue villagers, confront monsters, and work together to save the day—now with engaging visuals powered by Raylib.

---

## ✨ Features

- 🎨 Raylib Graphics — Smooth 2D rendering for maps, heroes, villagers, and monsters.
- 🦸 Multiple Heroes — Each with unique stats and abilities.
- 🗺 Interactive Map — Move freely and interact with the environment.
- 🧠 Dynamic Gameplay — Random events, monster AI, and evolving challenges.
- 🎵 Sound Effects & Music — Immersive audio powered by Raylib.

---

## 🖼 Screenshots

_(Add images or GIFs here when available.)_

---

## ⚙️ Getting Started

### Prerequisites

- C++17 or newer
- CMake 3.15+
- [Raylib](https://www.raylib.com) installed

---

### 📥 Installation

1. Clone the Repository
   `bash
   git clone https://github.com/Maryam-nokohan/Horrified-Game.git
   cd Horrified-Game

2. Install Raylib

Linux (APT):

sudo apt install libraylib-dev

Windows (vcpkg):

vcpkg install raylib

Build from Source:

git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build && cd build
cmake ..
make
sudo make install

3. Build the Game

mkdir build
cd build
cmake ..
make

4. Run

./HorrifiedGame

---

🎮 Controls

Action Key / Input Device

Move Hero Arrow keys / WASD
Interact E / Enter / Left Mouse Click
Pause Menu P / Esc
Toggle Fullscreen F11

---

📂 Project Structure

Horrified-Game/
├── assets/ # Sprites, textures, sounds, fonts
├── include/ # Header files (classes, utilities)
├── src/ # Source files (game logic, rendering, input)
├── shaders/ # Optional: shaders for effects
├── CMakeLists.txt # Build configuration
└── README.md # This file

---

🛠 Architecture

Game Engine — Handles main loop, game states (menu, play, pause).

Entities — Hero, Villager, Monster classes.

Renderer — Raylib-based drawing of game elements.

Input Handler — Processes keyboard, mouse, and gamepad input.

Audio System — Background music & SFX.

---

📜 How to Play

1. Launch the game.

2. Select your hero.

3. Explore the map to rescue villagers and fight monsters.

4. Use abilities and items strategically.

5. Win by completing all objectives before monsters take over the town.

---

🤝 Contributing

1. Fork this repository.

2. Create your feature branch:
   git checkout -b feature/AmazingFeature

3. Commit your changes:
   git commit -m 'Add some AmazingFeature'

4. Push to the branch:
   git push origin feature/AmazingFeature

5. Open a Pull Request.

---

📄 License

This project is licensed under the MIT License — see the LICENSE file for details.

---

🙏 Acknowledgments

Inspired by the Horrified board game.

Built with Raylib.

Thanks to open-source contributors for tools and libraries.

---

📬 Contact

Created by Maryam Nokohan
GitHub: Maryam-nokohan

If you want, I can also make you badges (build, license, Raylib version, platform) and GIF previews so your README looks more professional on GitHub. That would make it stand out.
