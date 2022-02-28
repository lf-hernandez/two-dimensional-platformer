#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game
{
public:
    Game();
    ~Game();
    void init(const char *title, int xPos, int yPos, int width, int height, Uint32 flags);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool getIsRunning();

    static SDL_Renderer* renderer;

private:
    bool isRunning;
    // int counter;
    SDL_Window *window;
};
