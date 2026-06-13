## Requirements

- **SFML 3.0** or higher (graphical library)
- **CMake** 3.10+
- C++17 compiler (g++, clang, MSVC)

## 🎮 Controls

| Key                  | Action              |
| -------------------- | ------------------- |
| 'WASD' or '↑ ↓ ← →'  | Move the player     |
| `Shift` (left/right) | Run (doubled speed) |
| `Space` or `Mouse 1` | Shoot projects      |
| `P`                  | Debug painel        |
| `Close window`       | Exit the game       |

## To compile and run

1. Compile

```bash
mkdir build
cd build
cmake ..
make
```

2. Run

```bash
./MyGameSFML
```

## 📁 Project Structure

```bash
├── CMakeLists.txt
├── include/
│   ├── core/
│   │   └── Game.hpp
│   └── entities/
│       └── Player.hpp
├── src/
│   ├── main.cpp
│   ├── core/
│   │   └── Game.cpp
│   └── entities/
│       └── Player.cpp
├── assets/
│   └── fonts/
│       └── LiberationSans-Regular.ttf
└── README.md
```
