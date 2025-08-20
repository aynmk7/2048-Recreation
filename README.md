# 2048-Recreation
A terminal-based remake of the classic puzzle game 2048, built entirely in C.
This project demonstrates skills in data structures, memory management, modular design, and interactive CLI development.

# Project Highlights
- Ability to design and implement game logic from scratch
- Use of structs to manage game state and history
- Clean separation of game engine vs. user interface
- Hands-on C programming, debugging, and build automation with Makefiles

# Features
- Fully functional 4x4 2048 board
- Track score per game and scores across multiple games
- Smooth tile movement and merging in all four directions (WASD)
- New game and score history functionality
- Clean, modular code with structs for GameStats and GameTracker

# Technologies
- Language: C
- Build System: Makefile
- Core Concepts: arrays, structs, random number generation, modular programming, CLI interaction

# How To Run
- clone the repo
- in terminal, type:
  - make
  - ./project
- you can also type:
  - make clean
- this gets rid of the object files and executable

# File Structure
```
.
├── Makefile        # Build Configuration
├── project.c       # Main game loop & user interaction
├── projectfunc.c   # Core game logic (movement, merging, scoring)
├── projectfunc.h   # Function declarations & data structures
└── README.txt      # Project Documentation
```


