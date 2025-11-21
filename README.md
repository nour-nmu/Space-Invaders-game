# 🚀 Space Invaders game

This project is a Raylib-based C++ game interface featuring a fully interactive menu system, multiple scenes, animated background layers, and basic player movement controls for both single-player and two-player modes. It provides a structured foundation for building a complete arcade-style game.

## 🎮 Overview

The project implements a multi-scene game framework using Raylib. It includes:

- A main menu with Start, Info, and Exit buttons

- A mode selection screen (One Player / Two Player)

- Player objects with horizontal movement

- Background rendering with random color overlays

- An info/credits screen with a QR code

- Two controllable spaceship characters, each with different controls

- A modular button system using inheritance and polymorphism

The code demonstrates clean object-oriented design and scene management through enums and abstract classes.

## 🧩 Key Features
### 1. Scene Management

 A strong enum-based state machine allows switching between:
- Main Menu
- Info / Credits
- Play Mode Selection
- Single Player
- Two Player
- Exit

### 2. Object-Oriented Button System

All buttons inherit from a base Button class, each implementing:
- Custom drawing logic
- Scene-transition behavior
- Hover detection
- Mouse-click interaction

### 3. Player Mechanics
- Player 1 uses arrow keys
- Player 2 uses A/D
- Ships are loaded from textures
Built-in boundary checking prevents movement off-screen

📁 Project Structure
```lua
|-- assets/
|   |-- ship_1.png
|   |-- ship_2.png
|   |-- background_stars.png
|   |-- QrCode.png
|
|-- main.cpp
```

▶️ How to Run

Install Raylib

Compile the source file:
```css
g++ main.cpp -lraylib -o infinite
```

Run the game:
```bash
./infinite
```
