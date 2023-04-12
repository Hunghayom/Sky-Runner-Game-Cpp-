#pragma once
#ifndef Tilemap_hpp
#define Tilemap_hpp

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

using namespace std;

class Tilemap
{
private:
    int tilemap_index;
    int tilemap[18][32];
    int number_of_platform = 0;
    vector <SDL_Rect> platform_rects;

public:
    Tilemap();
    Tilemap(int index, int tilemap[18][32], int number, SDL_Rect platform[]);
    ~Tilemap();

    int get_tilemap_index();
    int get_tilemap(int x, int y);

    void set_tilemap_index(int index);
    void set_tilemap(int x, int y, int value);

    int get_number_of_platform();
    void set_number_of_platform(int number_of_platform);

    void set_platform_rects(std::vector <SDL_Rect> platform_rects);
    std::vector <SDL_Rect> get_platform_rects()
    {
        return platform_rects;
    }
    vector <SDL_Rect> update_platform_rects(Tilemap tilemap, int tilemap_pos_x);

    
    SDL_Rect get_platform_rects(int number_of_platform);

    void create_platform_rects(int x, int y, int width, int height);

    void update_platform_rects(int tilemap_pos_x);
};
#endif /* Tilemap_hpp */