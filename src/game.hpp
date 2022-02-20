#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>
#include <iostream>

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

private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif
