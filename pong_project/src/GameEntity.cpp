#include "GameEntity.h"
#include "globals.h"

GameEntity::GameEntity(SDL_Renderer *renderer, int x_direction, int y_direction, int speed)
    : renderer(renderer), x_direction(x_direction), y_direction(y_direction), speed(speed) {}

void GameEntity::setX(int x) { entity.x = x; }
void GameEntity::setY(int y) { entity.y = y; }
void GameEntity::setW(int w) { entity.w = w; }
void GameEntity::setH(int h) { entity.h = h; }

// use this-> for member variables (have to use this-> because of the same name)
// another option is to use a different name for the member variable, such as m_x_direction (m_ is a common prefix for member variables)

void GameEntity::setXDirection(int x_direction) { this->x_direction = x_direction; }
void GameEntity::setYDirection(int y_direction) { this->y_direction = y_direction; }
void GameEntity::setSpeed(int speed) { this->speed = speed; }

int GameEntity::getX() { return entity.x; }
int GameEntity::getY() { return entity.y; }
int GameEntity::getW() { return entity.w; }
int GameEntity::getH() { return entity.h; }
int GameEntity::getXDirection() { return x_direction; }
int GameEntity::getYDirection() { return y_direction; }
int GameEntity::getSpeed() { return speed; }
SDL_Rect *GameEntity::getRect() { return &entity; }

void GameEntity::draw() {
    if (renderer != NULL) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &entity);
    } else {
        std::cout << "Renderer is NULL" << std::endl;
    }
}
