// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Game.hpp"

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

    game->loadTexture(texture[0], game->getRenderer(), "Image/Background/pixel-art.png");
    game->loadTexture(texture[1], game->getRenderer(), "Image/up.bmp");
    game->loadTexture(texture[2], game->getRenderer(), "Image/down.bmp");
    game->loadTexture(texture[3], game->getRenderer(), "Image/left.bmp");
    game->loadTexture(texture[4], game->getRenderer(), "Image/right.bmp");

    while (game->running())
    {
        // game->handleEvent();
        {
            SDL_Event event;

            render(game->getRenderer(), texture[0]);

            SDL_PollEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                game->setRunning(false);
                break;
            case SDLK_ESCAPE:
                game->setRunning(false);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    cout << "up \n";
                    render(game->getRenderer(), texture[1]);
                    break;
                case SDLK_DOWN:
                    cout << "down \n";
                    render(game->getRenderer(), texture[2]);
                    break;
                case SDLK_LEFT:
                    cout << "left \n";
                    render(game->getRenderer(), texture[3]);
                    break;
                case SDLK_RIGHT:
                    cout << "right \n";
                    render(game->getRenderer(), texture[4]);
                    break;
                }
            default:
                break;
            }
        }
        game->update();
        SDL_RenderPresent(game->getRenderer());
    }
    game->update();
    game->clean();

    return 0;
}
