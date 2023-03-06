// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Game.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;


void render (SDL_Renderer* renderer, SDL_Texture* texture) {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

int main(int argc, char *args[])
{
    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Event event;
    while (game->running())
    {
        game->handleEvent();
        game->update();
        SDL_RenderPresent(game->getRenderer());
    }
    game->update();
    game->clean();

    return 0;
}
