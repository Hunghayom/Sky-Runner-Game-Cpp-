#pragma once
#ifndef TextureLoader_hpp
#define TextureLoader_hpp

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

    int get_sourceRect_x();
    int get_sourceRect_y();
    int get_sourceRect_w();
    int get_sourceRect_h();

    SDL_Rect get_destinationRect();
    int get_destinationRect_x();
    int get_destinationRect_y();
    int get_destinationRect_w();
    int get_destinationRect_h();

    
    void set_sourceRect(int x, int y, int w, int h);
    void set_destinationRect(int x, int y, int w, int h);
};


#endif /* TextureLoader_hpp */
