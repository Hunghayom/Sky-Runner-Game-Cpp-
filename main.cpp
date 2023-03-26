// Using SDL and standard IO
#include <SDL2/SDL.h>
#include "TextureLoader.hpp"
#include "Game.hpp"


// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;


int main(int argc, char *args[])
{
    int const FPS = 60;
    int const frameDelay = 1000 / FPS;

    Texture_box player_texture(0, 0, 35, 42, 100, 100, 35, 42);

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[2];
    enum texture_type {BACKGROUND, CHARACTER};
    game->Texture_loader(texture,2);

    game->backgroundrender(game->getRenderer(), texture[BACKGROUND]);
    game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

    while (game->running())
    {
        frameStart = SDL_GetTicks64();

        SDL_Event event;
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
                cout << "up \n";
                player_texture.set_destinationRect(player_texture.get_destinationRect().x, player_texture.get_destinationRect().y - 30, player_texture.get_destinationRect().w, player_texture.get_destinationRect().h);
                game->backgroundrender(game->getRenderer(), texture[BACKGROUND]);
                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                break;
            case SDLK_DOWN:
                player_texture.set_destinationRect(player_texture.get_destinationRect().x, player_texture.get_destinationRect().y + 30, player_texture.get_destinationRect().w, player_texture.get_destinationRect().h);
                game->backgroundrender(game->getRenderer(), texture[BACKGROUND]);
                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                cout << "down \n";
                break;
            case SDLK_LEFT:
                player_texture.set_destinationRect(player_texture.get_destinationRect().x - 30, player_texture.get_destinationRect().y, player_texture.get_destinationRect().w, player_texture.get_destinationRect().h);
                game->backgroundrender(game->getRenderer(), texture[BACKGROUND]);
                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                cout << "left \n";
                break;
            case SDLK_RIGHT:
                player_texture.set_destinationRect(player_texture.get_destinationRect().x + 30, player_texture.get_destinationRect().y, player_texture.get_destinationRect().w, player_texture.get_destinationRect().h);
                game->backgroundrender(game->getRenderer(), texture[BACKGROUND]);
                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                cout << "right \n";
                break;
            }
        default:
            break;
        }

        game->update();
        SDL_RenderPresent(game->getRenderer()); 
        
        frameTime = SDL_GetTicks64() - frameStart;
        
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
