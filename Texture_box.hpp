#pragma once
#ifndef Texture_box_hpp
#define Texture_box_hpp

#include "Game.hpp"

class Texture_box
{
private:
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;

public:
    Texture_box();
    Texture_box(int Sx, int Sy, int Sw, int Sh, int Dx, int Dy, int Dw, int Dh);
    SDL_Rect get_sourceRect();

    SDL_Rect get_destinationRect();
  
    void set_sourceRect(int x, int y, int w, int h);
    void set_destinationRect(int x, int y, int w, int h);
};


#endif /* Texture_box_hpp */
