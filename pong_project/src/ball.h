#ifndef BALL_H
#define BALL_H
#include "GameEntity.h"

class Ball : public GameEntity {
private:
    int size;
    int half_size;

public:
    Ball(SDL_Renderer *renderer, int x_direction, int y_direction, int speed, int size, int half_size);
    int getSize();
    int getHalfSize();
    void resetPos();
};

#endif