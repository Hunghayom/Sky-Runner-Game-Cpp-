#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#include "Texture_box.hpp"
#include "Tilemap.hpp"
#include "Player.hpp"

using namespace std;

class Game
{
private:
    int score = 0;
    clock_t start_time;

    bool isRunning;

    // Window to render to
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

public:
    Game();
    ~Game();

    void setRunning(bool running);
    int getScore();
    void setScore(int score);
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    bool running();

    void start();
    int calculate_score();

    void init(const char *tilte, int xpos, int ypost, int width, int height, bool fullscreen);

    void render(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect);

    void loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path);
    
    void Moving_background(SDL_Texture *background, Texture_box &background_box, Texture_box &next_background_box, SDL_Renderer *renderer, int speed);

    void drawing_tilemap(Tilemap tilemap, Texture_box tilemap_texture, SDL_Texture *pTexture, int tilemap_pos_x);
    void infinite_tilemap(Tilemap tilemap[], int n, Texture_box tilemap_texture, SDL_Texture *pTexture, int index_1, int index_2, int present_tilemap_pos_x, int next_tilemap_pos_x, int speed);
    int random_tilemap(int n, int score);


    void handleEvent();

    void death_message(Player& player);
    void clean();

};

#endif /* Game_hpp */