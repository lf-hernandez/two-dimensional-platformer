#include "game.hpp"

const char *WINDOW_TITLE{"Platformer"};
const int WINDOW_WIDTH{800};
const int WINDOW_HEIGHT{600};

Game *game{nullptr};

int main(int argc, const char *argv[]) {
  const int fps{60};
  const int frameDelay{1000 / fps};

  Uint32 frameStart;
  int frameTime;

  game = new Game();

  game->init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  while (game->getIsRunning()) {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();

  return 0;
}
