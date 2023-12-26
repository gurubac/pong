#ifndef GameEntity_H
#define GameEntity_H

#include <SDL.h>
#include <iostream>

class GameEntity {
protected:
    SDL_Rect entity;
    SDL_Renderer *renderer;
    int x_direction;
    int y_direction;
    int speed;

public:
    GameEntity(SDL_Renderer *renderer, int x_direction, int y_direction, int speed);
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);
    void setXDirection(int x_direction);
    void setYDirection(int y_direction);
    void setSpeed(int speed);
    int getX();
    int getY();
    int getW();
    int getH();
    int getXDirection();
    int getYDirection();
    int getSpeed();
    void draw();
    SDL_Rect *getRect();
};

#endif