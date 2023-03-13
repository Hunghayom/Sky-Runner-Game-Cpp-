// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "TextureLoader.cpp"

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;

void render(SDL_Renderer *renderer, SDL_Texture *texture)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

int main(int argc, char *args[])
{
    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[5];
    game->Texture_loader(texture,5);

    while (game->running())
    {
        game->handleEvent();
        SDL_Event event;

        render(game->getRenderer(), texture[0]); 
        
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            game->setRunning(false);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game->setRunning(false);
                break;
            case SDLK_UP:
                render(game->getRenderer(), texture[1]);
                cout << "up \n";
                break;
            case SDLK_DOWN:
                render(game->getRenderer(), texture[2]);
                cout << "down \n";
                break;
            case SDLK_LEFT:
                render(game->getRenderer(), texture[3]);
                cout << "left \n";
                break;
            case SDLK_RIGHT:
                render(game->getRenderer(), texture[4]);
                cout << "right \n";
                break;
            }
        default:
            break;
        }
        // game->update();
        SDL_RenderPresent(game->getRenderer());
    }
    //game->update();
    game->clean();

    return 0;
}
