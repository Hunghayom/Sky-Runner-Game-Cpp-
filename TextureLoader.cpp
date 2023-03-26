#include "Game.hpp"
#include "TextureLoader.hpp"

void Game::loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
        cout << "Fail to load texture: " << SDL_GetError() << '\n';
}

void Game::Texture_loader(SDL_Texture *texture[], int n)
{
    loadTexture(texture[0], getRenderer(), "Image/Background/pixel-art.png");
    loadTexture(texture[1], getRenderer(), "Image/Character/Character.png");
}

void Game::backgroundrender(SDL_Renderer *renderer, SDL_Texture *texture)
{
    int x = SDL_RenderCopy(renderer, texture, NULL, NULL);
    if (x < 0)
    {
        cout << "Render error! SDL_Error: " << SDL_GetError() << "\n";
    }
}



void Game::load_character(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect)
{

    SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect);
}