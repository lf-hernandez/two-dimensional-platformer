#pragma once
#include "../../Vector.hpp"
#include "../EntityComponentSystem.hpp"

class TransformComponent : public Component {
 public:
  Vector position;
  Vector velocity;

  int height{32};
  int width{32};
  int scale{1};
  int speed{3};

  TransformComponent() { position.clear(); }

  TransformComponent(float initial_x, float initial_y) {
    position.x = initial_x;
    position.y = initial_y;
  }

  TransformComponent(float initial_x, float initial_y, int initial_scale) {
    position.x = initial_x;
    position.y = initial_y;
    scale = initial_scale;
  }

  TransformComponent(float initial_x, float initial_y, int initial_height,
                     int initial_width, int initial_scale) {
    position.x = initial_x;
    position.y = initial_y;
    width = initial_width;
    height = initial_height;
    scale = initial_scale;
  }

  void init() override { velocity.clear(); }

  void update() override {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }
};
