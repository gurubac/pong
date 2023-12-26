#include "game.h"

int main() {
    std::unique_ptr<Game> game = std::make_unique<Game>();
    if (game->init()) {
        game->run();
    }
    return 0;
}