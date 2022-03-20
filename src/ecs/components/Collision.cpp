#include "Collision.hpp"

bool Collision::AABB_detected(const SDL_Rect& rectA, const SDL_Rect& rectB) {
  return (rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x &&
          rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y);
}

bool Collision::AABB_detected(const ColliderComponent& collider_a,
                              const ColliderComponent& collider_b) {
  if (AABB_detected(collider_a.collider, collider_b.collider)) {
    std::cout << collider_a.tag << " hit: " << collider_b.tag << std::endl;
    return true;
  } else {
    return false;
  }
}
