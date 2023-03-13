#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include "Game.hpp"

#include <vector>

void Game::loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
        std::cout << "Fail to load texture: " << SDL_GetError() << '\n';
}

void Game::Texture_loader(SDL_Texture *texture[], int n)
{

    loadTexture(texture[0], getRenderer(), "Image/Background/pixel-art.png");
    loadTexture(texture[1], getRenderer(), "Image/up.bmp");
    loadTexture(texture[2], getRenderer(), "Image/down.bmp");
    loadTexture(texture[3], getRenderer(), "Image/left.bmp");
    loadTexture(texture[4], getRenderer(), "Image/right.bmp");
;
}

#endif /* TextureLoader_hpp */