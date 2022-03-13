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

  TransformComponent() {
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(float cstre_x, float cstre_y) {
    position.x = cstre_x;
    position.y = cstre_y;
  }

  TransformComponent(float cstre_x, float cstre_y, int cstr_scale) {
    position.x = cstre_x;
    position.y = cstre_y;
    scale = cstr_scale;
  }

  TransformComponent(float cstr_x, float cstr_y, int cstr_height,
                     int cstr_width, int cstr_scale) {
    position.x = cstr_x;
    position.y = cstr_y;
    width = cstr_width;
    height = cstr_height;
    scale = cstr_scale;
  }

  void init() override {
    velocity.x = 0;
    velocity.y = 0;
  }

  void update() override {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }
};
