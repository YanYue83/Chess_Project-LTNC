# **Chess Game**

A simple chess game built with **C++** and **SDL2**. This is an project in Advanced Programming course-UET, aiming to have a deep comprehension about using SDL2 library with C++ to create a fully functional game with intuitive gameplay, beautiful graphics, and smooth animations.

## **Info**
- Student: Dao Thi Binh An
- Student ID:22028326
---
## **Project Description**
### **Features**
- Full chess rules implementation (check, checkmate, stalemate, castling, etc.).
- Two-player mode for local games, 1-player mode with machine.
- Intuitive user interface with drag-and-drop functionality.
- Real-time updates and animations for piece movements.
- Highlights for valid moves and selected pieces.
- Score for each session.

---

### **Language and Libraries**
1. **C++ Compiler** (GCC, Clang, or MSVC).
2. **SDL2 Library** (download from [SDL2 official website](https://www.libsdl.org/)).
3. **SDL2_image** (for loading PNG textures, download [here](https://www.libsdl.org/projects/SDL_image/)).
4. **SDL2_mixer**: A audio processing assistance library, allows playing audio files with many different formats.
5. **SDL2_TTF**: A library to support the drawing of text using Trietype font.
6. **CMake** (optional, for cross-platform builds).

---

### **Project Structure**
```
Chess/
├── src/
│   ├── Engine/        # Core game logic
│   ├── GameManager/   # Manage the game state (board, menu, time, etc.)
│   ├── Pieces/        # Code for chess pieces 
│   ├── Player/        # Handle player turns
|   ├── Sound/         # Handle game music and sound effects
|   └── Texture/       # Render graphic
├── assets/
├── bin
├── obj
├── main
├── ...                # SDL2 config files
└── README.md          # Project description
```
### **Contributing**
Contributions are welcome! If you have suggestions or improvements, feel free to:
1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push the changes:
   ```bash
   git push origin feature-name
   ```
5. Create a pull request.
