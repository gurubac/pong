#include "ball.h"
#include "globals.h"
// Ball::Ball(SDL_Renderer *renderer, int x_direction, int y_direction, int speed, int size, int half_size) {
//     this->renderer = renderer;
//     this->x_direction = x_direction;
//     this->y_direction = y_direction;
//     this->speed = speed;
//     this->size = size;
//     this->half_size = half_size;
//     ball.x = 0;
//     ball.y = 0;
//     ball.w = size;
//     ball.h = size;
// }

// rewrite constructor with initializer list syntax and derived class syntax
Ball::Ball(SDL_Renderer *renderer, int x_direction, int y_direction, int speed, int size, int half_size)
    : GameEntity(renderer, x_direction, y_direction, speed),
      size(size),
      half_size(half_size) {
    entity.x = 0;
    entity.y = 0;
    entity.w = size;
    entity.h = size;
}   

int Ball::getSize() { return size; }
int Ball::getHalfSize() { return half_size; }
void Ball::resetPos() {
    entity.x = WIDTH / 2 - half_size;
    entity.y = HEIGHT / 2 - half_size;
    entity.w = size;
    entity.h = size;
}
