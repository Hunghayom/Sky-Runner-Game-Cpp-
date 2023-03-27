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

    Texture_box player_texture(0, 0, 35, 42, 640, 600, 35, 42);
    Texture_box background_texture(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box previous_background_texture(0, 0, 1280, 720, -1280, 0, 1280, 720);
    Texture_box next_background_texture(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[4];
    enum texture_type {PREVIOUS_BACKGROUND, BACKGROUND, NEXT_BACKGROUND, CHARACTER};
    game->Texture_loader(texture,4);
    
    game->render(game->getRenderer(), texture[BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
    
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
                break;
            case SDLK_DOWN:
                break;
            case SDLK_LEFT:
                cout << "left \n";
                SDL_RenderClear(game->getRenderer());

                previous_background_texture.set_destinationRect(background_texture.get_destinationRect().x - 1280 + 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[PREVIOUS_BACKGROUND], previous_background_texture.get_sourceRect(), previous_background_texture.get_destinationRect());
                cout << "\t previous_background_texture.get_destinationRect().x: " << previous_background_texture.get_destinationRect().x << endl;
                
                background_texture.set_destinationRect(background_texture.get_destinationRect().x + 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
                cout << "\t background_texture.get_destinationRect().x: " << background_texture.get_destinationRect().x << endl;

                next_background_texture.set_destinationRect(background_texture.get_destinationRect().x + 1280 + 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[NEXT_BACKGROUND], next_background_texture.get_sourceRect(), next_background_texture.get_destinationRect());
                cout << "\t next_background_texture.get_destinationRect().x: " << next_background_texture.get_destinationRect().x << endl;

                if (previous_background_texture.get_destinationRect().x == 0)
                {
                    SDL_RenderClear(game->getRenderer());

                    //previous_background_texture.set_destinationRect(-1280, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                    //game->render(game->getRenderer(), texture[PREVIOUS_BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
                    
                    background_texture.set_destinationRect(0, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                    game->render(game->getRenderer(), texture[BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
                
                }

                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                
                break;

            case SDLK_RIGHT:
                cout << "right \n";
                SDL_RenderClear(game->getRenderer());

                previous_background_texture.set_destinationRect(background_texture.get_destinationRect().x - 1280 - 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[PREVIOUS_BACKGROUND], previous_background_texture.get_sourceRect(), previous_background_texture.get_destinationRect());
                cout << "\t previous_background_texture.get_destinationRect().x: " << previous_background_texture.get_destinationRect().x << endl;
                
                background_texture.set_destinationRect(background_texture.get_destinationRect().x - 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
                cout << "\t background_texture.get_destinationRect().x: " << background_texture.get_destinationRect().x << endl;

                next_background_texture.set_destinationRect(background_texture.get_destinationRect().x + 1280 - 40, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                game->render(game->getRenderer(), texture[NEXT_BACKGROUND], next_background_texture.get_sourceRect(), next_background_texture.get_destinationRect());
                cout << "\t next_background_texture.get_destinationRect().x: " << next_background_texture.get_destinationRect().x << endl;

                if (next_background_texture.get_destinationRect().x == 0)
                {
                    SDL_RenderClear(game->getRenderer());
                    
                    background_texture.set_destinationRect(0, background_texture.get_destinationRect().y, background_texture.get_destinationRect().w, background_texture.get_destinationRect().h);
                    game->render(game->getRenderer(), texture[BACKGROUND], background_texture.get_sourceRect(), background_texture.get_destinationRect());
                }
                    
                game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                
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
