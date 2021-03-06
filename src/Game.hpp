#pragma once
#include <iostream>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class ColliderComponent;

class Game {
 public:
  Game();
  ~Game();
  void init(const char *title, int xPos, int yPos, int width, int height,
            Uint32 flags);
  void handleEvents();
  void update();
  void render();
  void clean();
  bool getIsRunning();

  static void addTile(int id, int xPos, int yPos);

  static SDL_Renderer *renderer;
  static SDL_Event event;

  static std::vector<ColliderComponent *> colliders;

 private:
  bool isRunning;
  SDL_Window *window;
};
