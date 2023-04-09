#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Texture_box.hpp"
#include "Tilemap.hpp"

using namespace std;

class Game
{
private:
    int cnt = 0;

    bool isRunning;

    // Window to render to
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

public:
    Game();
    ~Game();

    void setRunning(bool running);
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    bool running();

    void init(const char *tilte, int xpos, int ypost, int width, int height, bool fullscreen);

    void render(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect);

    void loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path);
    void Texture_loader(SDL_Texture *texture[], int n);
    void Moving_background(SDL_Texture *background, Texture_box &background_box, Texture_box &next_background_box, SDL_Renderer *renderer, int speed);

    void drawing_tilemap(Tilemap tilemap, Texture_box tilemap_texture, SDL_Texture *pTexture, int tilemap_pos_x);

    void handleEvent();

    void update();
    void clean();
};

#endif /* Game_hpp */