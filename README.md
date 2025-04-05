# CozeeFarm 🌾

**CozeeFarm** is a medieval-themed farming and life simulation game inspired by *Harvest Moon: Friends of Mineral Town*, *Stardew Valley*, and the shopkeeping mechanics of *Recettear*. The game is being built from scratch in C++ using OpenGL 2.1 for maximum performance and customizability.

---

## 🧱 Project Overview

- 🌍 Top-down 2D world
- 🏡 Farming, livestock, crafting, and social systems
- 🛒 Player-run shop with dynamic economy
- ⛏️ Exploration, fishing, mining, and dungeon elements
- 📅 In-game time, weather, stamina, and relationship systems

---

## 🔧 Tech Stack

| Tech           | Purpose                             |
|----------------|-------------------------------------|
| **C++17**       | Core game logic                     |
| **OpenGL 2.1**  | Graphics rendering (custom engine) |
| **GLFW**        | Windowing, input                    |
| **GLEW**        | OpenGL extensions loading           |
| **GLM**         | Math library (vectors, matrices)    |
| **CMake**       | Cross-platform build system         |
| **VS Code**     | Development environment             |
| **Git**         | Version control                     |

---

## ✅ Current Milestone: Engine Bootstrap

We’ve set up the initial dev environment and engine core:

- [x] Created Ubuntu 22.04 dev VM with OpenGL 4.1 (backward compatible to 2.1)
- [x] Installed full development stack (C++, CMake, Git, VS Code)
- [x] Created project folder structure
- [x] Set up `.gitignore`, `.vscode` config, and CMake build system
- [x] Implemented OpenGL 2.1 rendering context
- [x] Rendered first triangle using shaders (GLSL 1.20)
- [x] Initialized private GitHub repo with `main` and `dev` branches

---

## 🛣️ Next Steps

Planned upcoming features:

- [ ] Scene and game state manager
- [ ] Sprite rendering system (with batching)
- [ ] Tilemap loader and renderer
- [ ] Basic camera system
- [ ] Input mapping system
- [ ] Asset manager (textures, shaders, audio)
- [ ] FPS and timing controls

---

## 🚀 How to Build

```bash
mkdir build
cd build
cmake ..
make
./CozeeFarm