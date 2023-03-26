#include "Game.hpp"
#include "TextureLoader.hpp"

void Game::render(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect)
{
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &destinationRect);
    SDL_RenderPresent(renderer);
}

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

//p----------------------
Texture_box::Texture_box()
{
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = 0;
    sourceRect.h = 0;
    destinationRect.x = 0;
    destinationRect.y = 0;
    destinationRect.w = 0;
    destinationRect.h = 0;
}
Texture_box::Texture_box(int Sx, int Sy, int Sw, int Sh, int Dx, int Dy, int Dw, int Dh)
{
    sourceRect.x = Sx;
    sourceRect.y = Sy;
    sourceRect.w = Sw;
    sourceRect.h = Sh;
    destinationRect.x = Dx;
    destinationRect.y = Dy;
    destinationRect.w = Dw;
    destinationRect.h = Dh;
}
SDL_Rect Texture_box::get_sourceRect()
{
    return sourceRect;
}
SDL_Rect Texture_box::get_destinationRect()
{
    return destinationRect;
}
void Texture_box::set_sourceRect(int x, int y, int w, int h)
{
    sourceRect.x = x;
    sourceRect.y = y;
    sourceRect.w = w;
    sourceRect.h = h;
}
void Texture_box::set_destinationRect(int x, int y, int w, int h)
{
    destinationRect.x = x;
    destinationRect.y = y;
    destinationRect.w = w;
    destinationRect.h = h;
}
int Texture_box::get_destinationRect_x()
{
    return destinationRect.x;
}
int Texture_box::get_destinationRect_y()
{
    return destinationRect.y;
}
int Texture_box::get_destinationRect_w()
{
    return destinationRect.w;
}
int Texture_box::get_destinationRect_h()
{
    return destinationRect.h;
}