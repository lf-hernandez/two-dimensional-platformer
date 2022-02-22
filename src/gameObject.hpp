#pragma once
#include "game.hpp"

class GameObject
{
public:
    GameObject(const char *textureSheet, SDL_Renderer *gameRenderer, int x, int y);
    ~GameObject();

    void update();
    void render();

private:
    int xPos;
    int yPos;

    SDL_Texture *objectTexture;
    SDL_Rect srcRectangle, destRectangle;
    SDL_Renderer *renderer;
};