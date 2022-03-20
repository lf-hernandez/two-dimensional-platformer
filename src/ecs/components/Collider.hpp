#pragma once
#include <string>

#include "../EntityComponentSystem.hpp"
#include "SDL2/SDL.h"
#include "Transform.hpp"

class ColliderComponent : public Component {
 public:
  SDL_Rect collider;
  std::string tag;

  TransformComponent* transform;

  ColliderComponent(std::string cstr_tag) { tag = cstr_tag; }

  void init() override {
    if (!entity->hasComponent<TransformComponent>()) {
      entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();

    Game::colliders.push_back(this);
  }

  void update() override {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);

    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
  }
};
