#pragma once
#include "../EntityComponentSystem.hpp"

class TransformComponent : public Component {
 private:
  int xPosition;
  int yPosition;

 public:
  TransformComponent() {
    xPosition = 0;
    yPosition = 0;
  }

  TransformComponent(int x, int y) {
    xPosition = x;
    yPosition = y;
  }

  void update() override { xPosition++; }

  int getXPosition() { return xPosition; }

  int getYPosition() { return yPosition; }

  void setPosition(int x, int y) {
    xPosition = x;
    yPosition = y;
  }
};
