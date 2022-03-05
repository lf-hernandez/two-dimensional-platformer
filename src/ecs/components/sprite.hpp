#pragma once
#include "../components.hpp"
#include "SDL2/SDL.h"

class SpriteComponent : public Component {
 private:
  PositionComponent* position;
  SDL_Texture* texture;
  SDL_Rect srcRectangle;
  SDL_Rect destRectange;

 public:
  SpriteComponent() = default;
  SpriteComponent(const char* path) { setTexture(path); }

  void setTexture(const char* path) {
    texture = TextureManager::LoadTexture(path);
  }

  void init() override {
    position = &entity->getComponent<PositionComponent>();

    srcRectangle.x = 0;
    srcRectangle.x = 0;
    srcRectangle.h = 32;
    srcRectangle.w = 32;

    destRectange.w = 64;
    destRectange.h = 64;
  }

  void update() override {
    destRectange.x = position->getXPosition();
    destRectange.y = position->getYPosition();
  }

  void draw() override {
    TextureManager::Draw(texture, srcRectangle, destRectange);
  }
};
