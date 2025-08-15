# 🎮 Horrified Game

Welcome to **Horrified Game**, a thrilling digital adaptation inspired by the popular _Horrified_ board game by Ravensburger. This game plunges players into a cooperative adventure where you team up to defeat iconic monsters from classic horror films, such as Dracula and Invisible man monsters. Built with engaging gameplay and a spooky atmosphere, this project aims to capture the essence of the board game while adding a unique digital twist.

## 🗂 Table of Contents

- [🎮 Horrified Game](#-horrified-game)
  - [🗂 Table of Contents](#-table-of-contents)
  - [📖 About the Game](#-about-the-game)
  - [✨ Features](#-features)
  - [📂 Project Structure](#-project-structure)
  - [📥 Installation](#-installation)
    - [Prerequisites](#prerequisites)
  - [🎮 How to Play](#-how-to-play)
  - [👭 Contributing](#-contributing)
  - [🔑 License](#-license)
  - [✏️ Acknowledgements](#️-acknowledgements)

## 📖 About the Game

_Horrified Game_ is a cooperative strategy game where players work together as unique heroes to save a haunted town from terrifying monsters. Each monster has distinct abilities and strategies, requiring players to plan carefully, and leverage their hero’s special abilities to triumph. This digital version brings the suspense and teamwork of the board game to your screen, with intuitive controls and immersive visuals.

![gamePreview](https://i.imgur.com/IHrfZqG.jpeg)

## ✨ Features

- **Cooperative Gameplay**: Team up with friends or play solo to defeat monsters.
- **Unique Heroes**: Choose from a roster of heroes, each with special abilities that shape your strategy.
- **Iconic Monsters**: Face off against classic horror monsters like Dracula and Invisible man, each with unique mechanics.
- **Immersive Atmosphere**: Enjoy eerie visuals and sound effects that enhance the horror theme.
- **Cross-Platform**: Playable on various devices

## 📂 Project Structure

```bash
── CMakeLists.txt
|
├── include
│   ├── Archaelogist.hpp
│   ├── Card.hpp
│   ├── Courier.hpp
│   ├── Dice.hpp
│   ├── Dracula.hpp
│   ├── ErrorHandler.hpp
│   ├── file.hpp
│   ├── Game.hpp
│   ├── Hero.hpp
│   ├── invisible.hpp
│   ├── Item.hpp
│   ├── Location.hpp
│   ├── LocationNames.hpp
│   ├── Map.hpp
│   ├── Mayor.hpp
│   ├── MonsterCard.hpp
│   ├── Monster.hpp
│   ├── Names.hpp
│   ├── Perk.hpp
│   ├── scientist.hpp
│   ├── Terminal.hpp
│   └── Villager.hpp
├── main.cpp
├── README.md
└── src
    ├── Archaeologist.cpp
    ├── Card.cpp
    ├── Courier.cpp
    ├── Dice.cpp
    ├── Dracula.cpp
    ├── ErrorHandler.cpp
    ├── file.cpp
    ├── Game.cpp
    ├── Hero.cpp
    ├── invisibleMan.cpp
    ├── Item.cpp
    ├── Location.cpp
    ├── Map.cpp
    ├── Mayor.cpp
    ├── MonsterCard.cpp
    ├── Monster.cpp
    ├── Perk.cpp
    ├── scientist.cpp
    ├── Terminal.cpp
    └── Villager.cpp

```

## 📥 Installation

### Prerequisites

- C++17 or newer
- CMake 3.15+
- [Raylib](https://www.raylib.com) installed
- To run _Horrified Game_ locally, follow these steps:

1. Clone the Repository :

```bash
git clone https://github.com/Maryam-nokohan/Horrified-Game.git
cd Horrified-Game
```

2. Install Raylib

Linux :

```bash
sudo apt install libraylib-dev
```

or

Build from Source:

```bash
git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build && cd build
cmake ..
make
sudo make install
```

3. Build the Game

```bash
   cmake -S . -B build
   cd build/
   ./bin/HorrifiedGame
```

## 🎮 How to Play

1. **Choose Your Hero**: Select a hero with unique abilities to contribute to the team’s efforts.
2. **Take Turns**: Work together to collect items, compelete tasks, and defeat monsters. Each hero has a limited number of actions per turn.
3. **Defeat Monsters**: Complete specific objectives for each monster to win the game.
4. **Win or Lose Together**: Succeed by defeating all monsters or lose if the terror level reaches its maximum or the monster deck become empty.

For detailed rules, refer to the in-game tutorial or the [official Horrified board game rules](https://www.ravensburger.us/products/games/family-games/horrified-60001836/index.html) for inspiration.

## 👭 Contributing

We welcome contributions to make _Horrified Game_ even better! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes and commit (`git commit -m 'Add YourFeature'`).
4. Push to your branch (`git push origin feature/YourFeature`).
5. Open a Pull Request with a clear description of your changes.

## 🔑 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## ✏️ Acknowledgements

- Inspired by the _Horrified_ board game by Ravensburger.
- Thanks to the open-source community for tools and libraries used in this project.
- Special thanks to contributors and testers who help bring this game to life.

---

Ready to face the monsters? Clone the repo and start your adventure today! If you have questions or feedback, open an issue on the [GitHub repository](https://github.com/Maryam-nokohan/Horrified-Game) or contact the creators :

1. [Saba Bahrami](https://github.com/Saba-BH)
2. [Maryam Nokohan](https://github.com/Maryam-nokohan)
