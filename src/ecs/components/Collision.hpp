#pragma once
#include "SDL2/SDL.h"

class ColliderComponent;

class Collision {
 public:
  // Axis-Aligned Bounding Box
  static bool AABB_detected(const SDL_Rect& rectA, const SDL_Rect& rectB);
  static bool AABB_detected(const ColliderComponent& collider_a,
                            const ColliderComponent& collider_b);
};
