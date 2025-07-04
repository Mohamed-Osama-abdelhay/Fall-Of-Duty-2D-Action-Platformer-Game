Here's a detailed `README.md` documentation for your game project hosted on GitHub:

---

# 🎮 Fall Of Duty - 2D Action Platformer Game

Welcome to **Fall Of Duty**, a 2D side-scrolling shooter and platformer game built using **C++** and **SFML (Simple and Fast Multimedia Library)**. This game includes player and enemy characters, shooting mechanics, collisions, health tracking, collectible items, and a basic UI with a pause/resume menu system.

---

## 📂 Project Structure

```bash
├── Game.txt            
├── assets/              
│   ├── enemy*.png
│   ├── player*.png
│   ├── BG.png
│   ├── Sand.png
│   ├── fireball.png
│   ├── Water__01.png
│   ├── game music.wav
│   └── ...
```

---

## 🚀 Features

* **Character Movement**: Left, Right, and Jump using `WASD` keys.
* **Mouse Shooting**: Left and right click to fire water or fire projectiles.
* **Auto Shooting**: Enemy shoots periodically based on firing rate.
* **Collision Detection**: Tile-based and object-based collision detection.
* **Physics**: Basic gravity simulation.
* **Health System**: Player and enemy lose health when hit.
* **Menu System**: Start screen, Pause screen, Resume/Exit options.
* **Collectibles and Powerups**: Coin system and power-up effect simulation.
* **Camera Logic**: Basic camera following player.
* **Animations**: Texture-based sprite animation system.

---

## 🛠️ Built With

* **C++**
* **SFML** - Graphics, Audio, and Input handling

---

## 🎮 Controls

| Action                 | Key/Mouse Input   |
| ---------------------- | ----------------- |
| Move Left              | A                 |
| Move Right             | D                 |
| Jump                   | W or Space        |
| Shoot Fire Projectile  | Left Mouse Click  |
| Shoot Water Projectile | Right Mouse Click |
| Pause Game             | Escape            |

---

## 🧱 Core Components

* **Character Structure**: Handles movement, health, jumping, gravity.
* **Projectile System**: Allows both manual and automatic firing using trigonometry.
* **Collision Functions**: Multiple directions (Up, Down, Left, Right) and projectile-target intersections.
* **Enemy AI**: Enemy movement toward player and shooting logic.
* **Game Loop**: Starts with a main menu and transitions to gameplay or exits.

---

## 📦 Installation & Setup

1. Make sure you have **SFML** installed (version ≥ 2.5).
2. Clone this repo:

   ```bash
   git clone https://github.com/yourusername/Fall-Of-Duty.git
   ```
3. Rename `Game.txt` to `main.cpp`:

   ```bash
   mv Game.txt main.cpp
   ```
4. Compile the project:

   ```bash
   g++ main.cpp -o FallOfDuty -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```
5. Run it:

   ```bash
   ./FallOfDuty
   ```

---



## ❗ Known Issues

* Lack of modular structure — all logic is written in a single file.
* Hardcoded values for textures and coordinates.
* Collision detection can be optimized further.

---

## 🔄 Future Improvements

* Modularize game logic into classes (Player, Enemy, Projectile, etc.)
* Add more enemy types and AI.
* Improve animation system.
* Add sound effects for actions.
* Include score system and health UI.

---


