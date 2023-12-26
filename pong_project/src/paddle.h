#ifndef PADDLE_H
#define PADDLE_H
#include "GameEntity.h"

class Paddle : public GameEntity {
private:
    int playerNumber;
    int score;

public:
    Paddle(SDL_Renderer *renderer, int x_direction, int y_direction, int speed, int playerNumber, int score);
    void setScore(int score);
    int getScore();
    void resetPos();
    void resetScore();
    void enforceBounds();
};

#endif