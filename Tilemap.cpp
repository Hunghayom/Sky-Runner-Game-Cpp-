
#include "Tilemap.hpp"

Tilemap::Tilemap()
{
}
Tilemap::Tilemap(int index, int tilemap[18][32])
{
    tilemap_index = index;
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            this->tilemap[i][j] = tilemap[i][j];
        }
    }
}
Tilemap::~Tilemap()
{
}
int Tilemap::get_tilemap_index()
{
    return tilemap_index;
}
int Tilemap::get_tilemap(int x, int y)
{
    return tilemap[x][y];
}
void Tilemap::set_tilemap_index(int index)
{
    tilemap_index = index;
}
void Tilemap::set_tilemap(int x, int y, int value)
{
    tilemap[x][y] = value;
}