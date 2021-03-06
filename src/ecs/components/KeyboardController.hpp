#pragma once

#include "../../Game.hpp"
#include "../EntityComponentSystem.hpp"
#include "Transform.hpp"

class KeyboardController : public Component {
 public:
  TransformComponent *transform;

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override {
    if (Game::event.type == SDL_KEYDOWN) {
      switch (Game::event.key.keysym.sym) {
        case SDLK_a:
          transform->velocity.x = -1;
          break;
        case SDLK_d:
          transform->velocity.x = 1;
          break;
        case SDLK_SPACE:
          transform->velocity.y = -1;
          break;
        default:
          break;
      }
    }
    if (Game::event.type == SDL_KEYUP) {
      switch (Game::event.key.keysym.sym) {
        case SDLK_a:
          transform->velocity.x = 0;
          break;
        case SDLK_d:
          transform->velocity.x = 0;
          break;
        case SDLK_SPACE:
          transform->position.y = 485.0;
          transform->velocity.y = 0;
          break;
        default:
          break;
      }
    }
  }
};
