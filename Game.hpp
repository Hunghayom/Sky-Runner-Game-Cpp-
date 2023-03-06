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
    int cnt = 0;
    bool isRunning;

    // Window to render to
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Current displayed image
    SDL_Surface *image = NULL;


    //--------------------------------------------------------------------------------

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    // Key press surfaces constants
    enum KeyPressSurfaces
    {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };
    // The images that correspond to a keypress
    SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

public:
    Game();
    ~Game();

    void setRunning(bool running);

    void init(const char *tilte, int xpos, int ypost, int width, int height, bool fullscreen);

    SDL_Surface *loadSurface(string path);

    bool loadBackgroundMedia();
    void blitSurface();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();    

    void handleEvent();

    void update();
    void clean();

    bool running();
};

#endif /* Game_hpp */