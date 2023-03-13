#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

using namespace std;

class Game
{
private:
    bool isRunning;

    // Window to render to
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Current displayed image
    SDL_Surface *image = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;


public:
    Game();
    ~Game();

    void setRunning(bool running);

    void init(const char *tilte, int xpos, int ypost, int width, int height, bool fullscreen);

    void loadTexture (SDL_Texture* &texture, SDL_Renderer* renderer, const char* path);

    void Texture_loader(SDL_Texture *texture[], int n);

    void render (SDL_Renderer* renderer, SDL_Texture* texture);

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();    

    void handleEvent();

    void update();
    void clean();

    bool running();
};

#endif /* Game_hpp */