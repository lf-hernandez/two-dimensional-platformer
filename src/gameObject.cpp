#include "gameObject.hpp"
#include "textureManager.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* gameRenderer, int x,int y)
{
    renderer = gameRenderer;
    objectTexture = TextureManager::LoadTexture(textureSheet, gameRenderer);
    xPos = x;
    yPos = y;

}

void GameObject::update()
{
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

void GameObject::render()
{
    SDL_RenderCopy(renderer, objectTexture, &srcRectangle, &destRectangle);
}