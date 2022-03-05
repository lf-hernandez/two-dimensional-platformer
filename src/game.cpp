#include "game.hpp"

#include "ecs/components/positionComponent.hpp"
#include "ecs/entityComponentSystem.hpp"
#include "gameObject.hpp"
#include "map.hpp"
#include "textureManager.hpp"

GameObject* player;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xPos, int yPos, int width, int height,
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

  player = new GameObject("assets/player_sprite.png", 0, 0);
  map = new Map();

  newPlayer.addComponent<PositionComponent>();
}

void Game::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
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
}

void Game::update() {
  player->update();
  manager.update();
  std::cout << newPlayer.getComponent<PositionComponent>().getXPosition() << ","
            << newPlayer.getComponent<PositionComponent>().getYPosition()
            << std::endl;
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  map->DrawMap();
  player->render();
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
