## 1. Index

- [1. Index](#1-index)
- [2. 📋 Requirements](#2--requirements)
- [3. 🎮 Controls](#3--controls)
- [4. 🚀 To compile and run](#4--to-compile-and-run)
- [5. 📁 Project Structure](#5--project-structure)
- [6. 📖 About](#6--about)

## 2. 📋 Requirements

- **SFML 3.0** or higher (graphical library)
- **CMake** 3.10+
- C++17 compiler (g++, clang, MSVC)

## 3. 🎮 Controls

| Key                  | Action              |
| -------------------- | ------------------- |
| `WASD` or `↑ ↓ ← →`  | Move the player     |
| `Shift` (left/right) | Run (doubled speed) |
| `Space` or `Mouse 1` | Shoot projects      |
| `P`                  | Debug painel        |
| `Close window`       | Exit the game       |

## 4. 🚀 To compile and run

1. Clone the repository

```bash
git clone https://github.com/JorgeLineZin/Game-in-Cpp.git
```

2. Compile

```bash
mkdir build
cd build
cmake ..
make
```

3. Run

```bash
./MyGameSFML
```

## 5. 📁 Project Structure

- **assets:** resources and complementary files
- **include:** header files `.hpp`
- **src:** main directory `.cpp`

```bash
├── assets/
│   └── fonts/
│       └── LiberationSans-Regular.ttf
├── include/
│   ├── core/
│   │   └── Game.hpp
│   └── entities/
│       └── Player.hpp
│       └── Projectile.hpp
├── src/
│   ├── core/
│   │   └── Game.cpp
│   ├── entities/
│   │   └── Player.cpp
│   │   └── Projectile.cpp
│   └── main.cpp
├── .gitignore
├── CMakeLists.txt
├── LICENSE.txt
└── README.md
```

## 6. 📖 About

I'm creating this project to learn C++, it's a bit of a silly project,
but I do it out of curiosity and gain more programming knowledge.
Now I'm going to go to sleep, good night.
