#include "paddle.h"
#include "globals.h"

// constructor with initializer list syntax and derived class syntax
Paddle::Paddle(SDL_Renderer *renderer, int x_direction, int y_direction, int speed, int playerNumber, int score)
    : GameEntity(renderer, x_direction, y_direction, speed),
      playerNumber(playerNumber),
      score(score) {
    entity.x = 0;
    entity.y = 0;
    entity.w = 20;
    entity.h = 140;
}

void Paddle::setScore(int score) { this->score = score; }
int Paddle::getScore() { return score; }
void Paddle::resetPos() {
    if (playerNumber == 1) {
        entity.w = 20;
        entity.h = 140;
        entity.x = WIDTH - WIDTH / 1.07;
        entity.y = HEIGHT / 2 - entity.h / 2;
    } else if (playerNumber == 2) {
        entity.w = 20;
        entity.h = 140;
        entity.x = WIDTH / 1.1;
        entity.y = HEIGHT / 2 - entity.h / 2;
    }
}

void Paddle::resetScore() { this->score = 0; }

void Paddle::enforceBounds() {
    if (entity.y < 0) {
        entity.y = 0;
    } else if (entity.y + entity.h > HEIGHT) {
        entity.y = HEIGHT - entity.h;
    }
}