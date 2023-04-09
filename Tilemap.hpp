#pragma once
#ifndef Tilemap_hpp
#define Tilemap_hpp

class Tilemap
{
private:
    int tilemap_index;
    int tilemap[18][32];

public:
    Tilemap();
    Tilemap(int index, int tilemap[18][32]);
    ~Tilemap();

    int get_tilemap_index();
    int get_tilemap(int x, int y);

    void set_tilemap_index(int index);
    void set_tilemap(int x, int y, int value);
};
#endif /* Tilemap_hpp */