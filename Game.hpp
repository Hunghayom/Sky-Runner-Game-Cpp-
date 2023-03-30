#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

using namespace std;

class Game
{
    friend class TextureManage;
private:
    int cnt = 0;
    
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

    
    void render (SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect);

    void loadTexture(SDL_Texture *&texture, SDL_Renderer *renderer, const char *path);
    void Texture_loader(SDL_Texture *texture[], int n);
    void Moving_background(SDL_Texture *background, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer *renderer, int speed);

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();    

    void handleEvent();

    void update();
    void clean();

    bool running();
};

#endif /* Game_hpp */