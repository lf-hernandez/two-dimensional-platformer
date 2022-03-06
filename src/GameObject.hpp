#pragma once
#include "Game.hpp"

class GameObject {
 public:
  GameObject(const char *textureSheet, int x, int y);
  ~GameObject();

  void update();
  void render();

 private:
  int xPos;
  int yPos;

  SDL_Texture *objectTexture;
  SDL_Rect srcRectangle, destRectangle;
};
