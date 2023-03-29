#include "Game.hpp"
#include "Texture_box.hpp"

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
