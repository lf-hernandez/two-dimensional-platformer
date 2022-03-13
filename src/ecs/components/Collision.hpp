#pragma once
#include "SDL2/SDL.h"

class Collision {
 public:
  // Axis-Aligned Bounding Box
  static bool AABB_detected(const SDL_Rect& rectA, const SDL_Rect& rectB);
};
