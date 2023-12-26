#include <SDL.h>
#include <SDL_ttf.h>
#include <filesystem>
#include <iostream>

#include "ball.h"
#include "globals.h"
#include "paddle.h"
#include "sound.h"

class Game {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event e;
    TTF_Font *font;
    bool running;
    Ball *ball;
    Paddle *p1;
    Paddle *p2;
    Sound se;
    uint32_t start;
    const int fps = 60;
    void addSounds();
    void update();
    void input();
    void render();
    void writeText(std::string text, int x, int y);
    void destroy();

public:
    Game();
    bool init();
    void run();
    ~Game();
};