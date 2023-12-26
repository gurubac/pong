![image](https://github.com/gurubac/pong/assets/59124862/305cdfbc-ad14-43df-be33-8b7b15908c71)

## Overview

This project is a simple game developed using the SDL2 (Simple DirectMedia Layer) library. SDL2 was chosen for its cross-platform capabilities, built-in renderer, and comprehensive tools for game development, such as SDL_Rect for rectangles, SDL_TTF for font loading, and SDL_Mixer for sound loading. The project follows a structured approach, utilizing a GameEntity class as the base for game objects, and then deriving specific classes for the ball and paddles.

## Structure

### GameEntity Class

The `GameEntity` class contains methods related to SDL_Rect, serving as a foundational class for other game objects.

### Ball and Paddle Classes

Derived from the `GameEntity` class, these classes include additional methods specific to the ball and paddles, such as setting and getting speed.

## Gameplay Logic

The main logic of the game revolves around determining ball and paddle movements, as well as handling collisions. Movement is determined by x and y direction variables for the objects (-1, 0, 1). Collisions are detected with paddles, the top/bottom of the game window, and the left/right sides of the screen. Scoring occurs when the ball collides with the left/right sides, and the ball resets to the middle of the screen.

## AI Implementation

The computer-controlled paddle follows a simple AI function. If the ball is above the computer’s paddle, it moves up, and if it's below, it moves down. This logic is implemented in the same way as player input, with a setY function and direction calculation.

## Sound Effects

Various sound effects enhance the gaming experience, triggered by different events such as scoring points, collisions with paddles, top/bottom of the screen, winning, and losing.

## Build System

CMake is used as the build system, providing a cross-platform solution. Troubleshooting was required, including the installation of custom CMake modules to address issues with finding SDL libraries. This approach eliminated the need for hardcoded paths in Makefiles, offering a more standardized build process.

## Getting Started

1. Clone the repository.
2. Ensure SDL2 is installed on your system.
3. Use CMake to generate build files.
4. Build the project.
5. Run the executable.
