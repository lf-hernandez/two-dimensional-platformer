#include "Game.hpp"

#include "GameObject.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include "Vector.hpp"
#include "ecs/components.hpp"

Map *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

auto &player(manager.addEntity());

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xPos, int yPos, int width, int height,
                Uint32 flags) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    isRunning = false;
  }

  std::cout << "SDL subsystems initialized..." << std::endl;

  window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

  if (window) {
    std::cout << "Window created" << std::endl;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (renderer) {
    std::cout << "Renderer created" << std::endl;
  }

  isRunning = true;

  map = new Map();

  player.addComponent<TransformComponent>(0.0, 485.0);
  player.addComponent<SpriteComponent>("assets/player.png");
  player.addComponent<KeyboardController>();
}

void Game::handleEvents() {
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      }
      break;

    default:
      break;
  }
}

void Game::update() {
  manager.refresh();
  manager.update();
}

void Game::render() {
  SDL_RenderClear(renderer);

  map->DrawMap();
  manager.draw();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "Destroyed window, renderering context, and cleaned up all "
               "intialized SDL subsystems"
            << std::endl;
}

bool Game::getIsRunning() { return isRunning; }
