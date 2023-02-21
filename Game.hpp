#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

class Game
{
    private:
        int cnt = 0;
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
    public:
        Game();
        ~Game();

        void init(const char* tilte, int xpos, int ypost, int width, int height, bool fullscreen);

        void handleEvent();
        void update();
        void render();
        void clean();

        bool running();

};

#endif /* Game_hpp */