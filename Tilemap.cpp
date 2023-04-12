
#include "Tilemap.hpp"

Tilemap::Tilemap()
{
}
 
Tilemap::Tilemap(int index, int tilemap[18][32], int number, SDL_Rect platform[])
{
    tilemap_index = index;
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            this->tilemap[i][j] = tilemap[i][j];
        }
    }
    number_of_platform = number;
    for (int i = 0; i < number; i++)
    {
        platform_rects.push_back(platform[i]);
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

void Tilemap::create_platform_rects(int x, int y, int width, int height)
{
    SDL_Rect platform_rect;
    platform_rect.x = x;
    platform_rect.y = y;
    platform_rect.w = width;
    platform_rect.h = height;
    platform_rects.push_back(platform_rect);
}

void Tilemap::update_platform_rects(int tilemap_pos_x)
{
    // di chuyển các platform sang trái với tốc độ speed
    for (int i = 0; i < platform_rects.size(); i++)
    {
        platform_rects[i].x += tilemap_pos_x;
    }

    // xóa các platform ở phía bên trái màn hình
    while (!platform_rects.empty() && platform_rects[0].x + platform_rects[0].w < 0)
    {
        platform_rects.erase(platform_rects.begin());
    }
}

int Tilemap::get_number_of_platform()
{
    return number_of_platform;
}

void Tilemap::set_number_of_platform(int number_of_platform)
{
    this->number_of_platform = number_of_platform;
}

void Tilemap::set_platform_rects(std::vector<SDL_Rect> platform_rects)
{
    this->platform_rects = platform_rects;
}

SDL_Rect Tilemap::get_platform_rects(int number_of_platform)
{
    return platform_rects[number_of_platform];
}
vector <SDL_Rect> Tilemap::update_platform_rects(Tilemap tilemap, int tilemap_pos_x)
{
    for (int i = 0; i < platform_rects.size(); i++)
    {
        
        platform_rects[i].w += tilemap_pos_x;
    }
    return platform_rects;
}