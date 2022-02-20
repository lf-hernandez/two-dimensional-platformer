#include "game.hpp"

const char *WINDOW_TITLE = "Platformer";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

Game *game = nullptr;

int main(int argc, const char *argv[])
{
    game = new Game();

    game->init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    while (game->getIsRunning())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}