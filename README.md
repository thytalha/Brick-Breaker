# 🧱🕹️ Brick Breaker: Console Arcade Chaos

**The classic paddle-and-ball arcade game, rebuilt inside the Windows console using pure C++.** 🎯  

![C++](https://img.shields.io/badge/Language-C/C++-00599C?style=for-the-badge)
![Author](https://img.shields.io/badge/Author-Talha%20Pasha-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-In%20Progress-red?style=for-the-badge)

---

## 🚀 Overview

No game engines. No frameworks. Just Win32 drawing calls and raw C++ logic. ⚙️  
This is **Brick Breaker** running directly in the Windows console. The game renders the paddle, ball, and colorful bricks using custom drawing helpers, handles real-time keyboard input, and tracks score, lives, and win/lose states. Select your difficulty, break all the bricks, and try not to lose your last life. 💥  

---

## ✨ Features

- 🧱 **Classic Brick Layout** – 6 rows × 14 columns of colored bricks, each destroyed with a satisfying hit.  
- 🎯 **Paddle & Ball Physics** – Collision with walls, paddle, and bricks with dynamic bounce direction.  
- 🎚️ **Difficulty Modes** – Choose **Easy** or **Hard** and feel the ball speed change instantly.  
- 🎛️ **HUD Display** – Live **Score** and **Lives** counters drawn on the side of the console window.  
- 🏁 **Win / Game Over States** – Clear all bricks to see `YOU WIN!` or lose all lives for `GAME OVER`. 😵‍💫  

---

## 🎮 How to Play

### 🖥️ Before Playing (Important)

- 🛡️ Run **Visual Studio Community as Administrator** so the console configuration is applied correctly.  
- 📏 Set **Screen Buffer Size** to **Width = 240**, **Height = 9001**.  
- 🪟 Set **Window Size** to **Width = 240**, **Height = 60**.  
- 📍 Set **Window Position** to **Left = 0**, **Top = 0**.

### 🎬 Start Screen

- 🆕 Press **N** to start a **New Game**.  
- 🚪 Press **Esc** to **Exit**.  

### 🎚️ Select Difficulty

- 🟢 Press **E** for **Easy** mode.  
- 🔴 Press **H** for **Hard** mode.  

### 🎛️ In-Game Controls

- ⬅️ **Left Arrow** – Move paddle left.  
- ➡️ **Right Arrow** – Move paddle right.  
- ⎋ **Esc** – Exit the game loop.  

### 🎯 Objective

- 🏓 Keep the ball in play using the paddle.  
- 🏆 Break all bricks to win.  
- 💔 You start with **3 lives**; every time the ball falls below the paddle, you lose one.  

---

## 🧩 Technical Details

- 🧱 Written in **C++** for **Windows**. 🪟  
- 🧠 Uses the Windows API (`GetConsoleWindow`, `GetDC`, `Rectangle`, `Ellipse`, `GetAsyncKeyState`, etc.) to draw shapes and read real-time keyboard input.  

### 📂 `help.h` utilities

- 🖊️ Drawing rectangles, ellipses, and lines (`myRect`, `my_rec`, `myEllipse`, `myLine`).  
- 🔤 Rendering custom text and numbers in the console (`drawText`, `lettersnNumbers`).  
- ⌨️ Polling keyboard input (`isKeyPressed`) for arrows, Esc, E, H, N, etc.  

---

## 👨‍💻 Credits

**Designed and Coded by Talha Pasha.** 🙌  
Built to practice game loops, basic physics, collision detection, and low-level drawing with the Windows API in C++. 🎓  

---

## 📜 License

Usage: You are free to explore this code, learn from it, or modify it to build your own version. Feel free to fork the repo, tweak the physics, redesign the levels, or add new power-ups and visual effects. 🧪⚡  

---

**Built with ❤️, C++, and way too many console pixels by Talha Pasha.** 🧠💻
