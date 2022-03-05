#pragma once
#include "../entityComponentSystem.hpp"

class PositionComponent : public Component
{
private:
    int xPosition {0};
    int yPosition {0};

public:
    void init() override
    {
        xPosition = 0;
        yPosition = 0;
    }

    void update() override
    {
        xPosition++;
        yPosition++;
    }

    int getXPosition()
    {
        return xPosition;
    }

    int getYPosition()
    {
        return yPosition;
    }

    void setPosition(int x, int y)
    {
        xPosition = x;
        yPosition = y;
    }
};
