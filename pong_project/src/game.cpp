#include "game.h"

Game::Game() {
    running = false;
    window = nullptr;
    renderer = nullptr;
    font = nullptr;
    ball = nullptr;
    p1 = nullptr;
    p2 = nullptr;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) != 0) {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() != 0) {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return false;
    }

    std::cout << "Game initialized" << std::endl;
    font = TTF_OpenFont("resources/fonts/PublicPixel.ttf", FONT_SIZE);

    ball = new Ball(renderer, 1, 1, 7, 20, 10);
    p1 = new Paddle(renderer, 0, 0, 5, 1, 0);
    p2 = new Paddle(renderer, 0, 0, 5, 2, 0);

    Game::addSounds();

    p1->resetPos();
    p2->resetPos();
    ball->resetPos();
    return true;
}

void Game::addSounds() {
    // for loop to add all sounds in sounds folder
    for (const auto &entry : std::filesystem::directory_iterator("resources/sounds")) {
        std::string path = entry.path();
        std::string name = entry.path().filename().string();
        // std::cout << "Path: " << path << std::endl;
        // std::cout << "Name: " << name << std::endl;
        se.addSound(name, path);
    }
}

void Game::run() {
    running = true;
    std::cout << "Game running" << std::endl;
    while (running) {
        start = SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        Game::update();
        Game::input();
        Game::render();
        if (1000 / fps > SDL_GetTicks() - start) {
            SDL_Delay(1000 / fps - (SDL_GetTicks() - start));
        }
    }
}

void Game::update() {

    // make sure paddles don't go off the screen
    p1->enforceBounds();
    p2->enforceBounds();

    // ball collision with left and right sides
    // if the ball goes off the screen on either left or right sides,
    // reset the ball and add a point to the other player
    if (ball->getX() <= 0) {
        ball->resetPos();
        p2->setScore(p2->getScore() + 1);
    } else if (ball->getX() + ball->getW() >= WIDTH) {
        ball->resetPos();
        p1->setScore(p1->getScore() + 1);
        se.playSound("score.wav");
    }

    // ball collision with top and bottom
    if (ball->getY() <= 0) {
        ball->setY(0);                                   // don't let the ball go off the screen (top)
        ball->setYDirection(ball->getYDirection() * -1); // reverse the direction
        se.playSound("thud.wav");
    } else if (ball->getY() + ball->getH() >= HEIGHT) {
        ball->setY(HEIGHT - ball->getH());               // don't let the ball go off the screen (bottom)
        ball->setYDirection(ball->getYDirection() * -1); // reverse the direction
        se.playSound("thud.wav");
    }

    // ball collision with paddles
    // if the ball is within the x range of the paddle and the y range of the paddle, setX pos to the paddle and change direction
    if (ball->getX() <= p1->getX() + p1->getW() && ball->getY() + ball->getH() >= p1->getY() && ball->getY() <= p1->getY() + p1->getH()) {
        ball->setX(p1->getX() + p1->getW());
        ball->setXDirection(ball->getXDirection() * -1); // reverse the direction
        se.playSound("hit.wav");
        // std::cout << "HIT P1 " << std::endl;
    }
    // paddle 2
    if (ball->getX() + ball->getW() >= p2->getX() && ball->getY() + ball->getH() >= p2->getY() && ball->getY() <= p2->getY() + p2->getH()) {
        ball->setX(p2->getX() - ball->getW());
        ball->setXDirection(ball->getXDirection() * -1); // reverse the direction
        // std::cout << "HIT 2 " << std::endl;
        se.playSound("hit.wav");
    }

    // ai movement direction calculation
    // if the ball is above the paddle, move up
    if (ball->getY() < p2->getY() && p2->getYDirection() != -1) {
        p2->setYDirection(-1);
    }
    // if the ball is below the paddle, move down
    if (ball->getY() > p2->getY() && p2->getYDirection() != 1) {
        p2->setYDirection(1);
    }

    // ball movement (gets updated by the collision statements)
    ball->setX(ball->getX() + ball->getXDirection() * ball->getSpeed());
    ball->setY(ball->getY() + ball->getYDirection() * ball->getSpeed());

    // paddle movement - based on speed, and the direction
    // direction gets updated by the input function, or the ai movement
    p1->setY(p1->getY() + p1->getSpeed() * p1->getYDirection());
    p2->setY(p2->getY() + p2->getSpeed() * p2->getYDirection());

    // if the score reaches 2, create a game over screen by writing the winner
    if (p1->getScore() == 2) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        writeText("You win!", WIDTH / 2 + 100, HEIGHT / 2);
        SDL_RenderPresent(renderer);
        se.playSound("win.wav");
        SDL_Delay(3000);
        p1->resetScore();
        p2->resetScore();
        ball->resetPos();
        p1->resetPos();
        p2->resetPos();
    } else if (p2->getScore() == 2) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        writeText("Computer wins!", WIDTH / 2 + 150, HEIGHT / 2);
        SDL_RenderPresent(renderer);
        se.playSound("lose.wav");
        SDL_Delay(3000);
        p1->resetScore();
        p2->resetScore();
        ball->resetPos();
        p1->resetPos();
        p2->resetPos();
    }
}

void Game::input() {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            running = false;
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP) {
            p1->setYDirection(-1);
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN) {
            p1->setYDirection(1);
        }

        if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_UP) {
            p1->setYDirection(0);
        }
        if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_DOWN) {
            p1->setYDirection(0);
        }
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    p1->draw();
    p2->draw();
    ball->draw();
    writeText(std::to_string(p1->getScore()) + "   " + std::to_string(p2->getScore()), WIDTH / 2 + WIDTH / 14, 45);
    SDL_RenderPresent(renderer);
}

void Game::destroy() {
    delete ball;
    delete p1;
    delete p2;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game destroyed" << std::endl;
}

Game::~Game() {
    Game::destroy();
}

void Game::writeText(std::string text, int x, int y) {
    SDL_Rect rect;
    SDL_Color color = {255, 255, 255, 255};
    const char *textChar = text.c_str();
    SDL_Surface *surface = TTF_RenderText_Solid(font, textChar, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect.w = surface->w;
    rect.h = surface->h;
    rect.x = x - rect.w;
    rect.y = y - rect.h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}