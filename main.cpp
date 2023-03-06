// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Game.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;

void loadTexture (SDL_Texture* &texture, SDL_Renderer* renderer, const char* path)
{
    texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL) std::cout << "Fail to load texture: " << SDL_GetError() << '\n';
}

void render (SDL_Renderer* renderer, SDL_Texture* texture) {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

int main(int argc, char *args[])
{
    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    // game->loadBackgroundMedia();
    // game->blitSurface();

    SDL_Texture* texture[5];
    loadTexture (texture[0], game->getRenderer(), "Image/Background/pixel-art.png");
    loadTexture (texture[1], game->getRenderer(), "Image/up.bmp");
    loadTexture (texture[2], game->getRenderer(), "Image/down.bmp");
    loadTexture (texture[3], game->getRenderer(), "Image/left.bmp");
    loadTexture (texture[4], game->getRenderer(), "Image/right.bmp");

    SDL_Event event;
    while (game->running())
    {
        render(game->getRenderer(), texture[0]);
        
        SDL_PollEvent(&event); 
        switch (event.type )
            {
            case SDL_QUIT:
                game->clean();
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
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
        
        game->update();
        SDL_RenderPresent(game->getRenderer());
    }
    game->update();
    game->clean();

    return 0;
}
