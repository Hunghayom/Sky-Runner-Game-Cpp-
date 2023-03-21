#include "Game.hpp"
#include "TextureLoader.hpp"

void TextureManager::loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
        cout << "Fail to load texture: " << SDL_GetError() << '\n';
}

void TextureManager::Texture_loader(SDL_Texture *texture[], int n)
{

    loadTexture(texture[0], getRenderer(), "Image/Background/pixel-art.png");
    loadTexture(texture[1], getRenderer(), "Image/up.bmp");
    loadTexture(texture[2], getRenderer(), "Image/down.bmp");
    loadTexture(texture[3], getRenderer(), "Image/left.bmp");
    loadTexture(texture[4], getRenderer(), "Image/right.bmp");
;
}

void TextureManager::backgroundrender(SDL_Renderer *renderer, SDL_Texture *texture)
{
    int x = SDL_RenderCopy(renderer, texture, NULL, NULL);
    if (x < 0)
    {
        cout << "Render error! SDL_Error: " << SDL_GetError() << "\n";
    }
}