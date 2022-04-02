#pragma once
#include "../EntityComponentSystem.hpp"
#include "SDL2/SDL.h"
#include "Sprite.hpp"
#include "Transform.hpp"

class TileComponent : public Component {
 public:
  TransformComponent *transform;
  SpriteComponent *sprite;

  SDL_Rect tileRectangle;
  int tileId;
  const char *path;

  TileComponent() = default;

  TileComponent(int x, int y, int w, int h, int id) {
    tileRectangle.x = x;
    tileRectangle.y = y;
    tileRectangle.w = w;
    tileRectangle.h = h;
    tileId = id;

    switch (tileId) {
      case 0:
        path = "assets/sky.png";
        break;
      case 1:
        path = "assets/grass.png";
        break;
      case 2:
        path = "assets/dirt.png";
        break;
      default:
        break;
    }
  }
  void init() override {
    entity->addComponent<TransformComponent>(
        static_cast<float>(tileRectangle.x),
        static_cast<float>(tileRectangle.y),
        static_cast<float>(tileRectangle.w),
        static_cast<float>(tileRectangle.h), 1);
    transform = &entity->getComponent<TransformComponent>();

    entity->addComponent<SpriteComponent>(path);
    sprite = &entity->getComponent<SpriteComponent>();
  }
};
