#pragma once
#include "../../Vector.hpp"
#include "../EntityComponentSystem.hpp"

class TransformComponent : public Component {
 public:
  Vector position;

  TransformComponent() {
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(float x, float y) {
    position.x = x;
    position.y = y;
  }
};
