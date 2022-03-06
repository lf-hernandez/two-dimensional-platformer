#pragma once
#include "../../TextureManager.hpp"
#include "../EntityComponentSystem.hpp"
#include "SDL2/SDL.h"
#include "Transform.hpp"

class SpriteComponent : public Component {
 private:
  TransformComponent* transform;
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
    transform = &entity->getComponent<TransformComponent>();

    srcRectangle.x = 0;
    srcRectangle.x = 0;
    srcRectangle.h = 32;
    srcRectangle.w = 32;

    destRectange.w = 64;
    destRectange.h = 64;
  }

  void update() override {
    destRectange.x = static_cast<int>(transform->position.x);
    destRectange.y = static_cast<int>(transform->position.y);
  }

  void draw() override {
    TextureManager::Draw(texture, srcRectangle, destRectange);
  }
};
