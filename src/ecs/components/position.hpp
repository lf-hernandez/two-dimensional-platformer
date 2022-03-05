#pragma once
#include "../entityComponentSystem.hpp"

class PositionComponent : public Component {
 private:
  int xPosition;
  int yPosition;

 public:
  PositionComponent() {
    xPosition = 0;
    yPosition = 0;
  }

  PositionComponent(int x, int y) {
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
