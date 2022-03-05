#include "gameObject.hpp"

#include "textureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y) {
  objectTexture = TextureManager::LoadTexture(textureSheet);
  xPos = x;
  yPos = y;
}

void GameObject::update() {
  xPos++;
  yPos++;

  srcRectangle.h = 32;
  srcRectangle.w = 32;
  srcRectangle.x = 0;
  srcRectangle.y = 0;

  destRectangle.h = srcRectangle.h * 2;
  destRectangle.w = srcRectangle.w * 2;
  destRectangle.x = xPos;
  destRectangle.y = yPos;
}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, objectTexture, &srcRectangle, &destRectangle);
}
