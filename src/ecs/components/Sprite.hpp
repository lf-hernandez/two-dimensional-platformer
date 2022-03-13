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
  ~SpriteComponent() { SDL_DestroyTexture(texture); }

  void setTexture(const char* path) {
    texture = TextureManager::LoadTexture(path);
  }

  void init() override {
    transform = &entity->getComponent<TransformComponent>();

    srcRectangle.x = 0;
    srcRectangle.x = 0;

    srcRectangle.h = transform->width;
    srcRectangle.w = transform->height;
  }

  void update() override {
    destRectange.x = static_cast<int>(transform->position.x);
    destRectange.y = static_cast<int>(transform->position.y);

    destRectange.w = transform->width * transform->scale;
    destRectange.h = transform->height * transform->scale;
  }

  void draw() override {
    TextureManager::Draw(texture, srcRectangle, destRectange);
  }
};
