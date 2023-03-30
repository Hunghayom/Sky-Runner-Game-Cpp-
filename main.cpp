// Using SDL and standard IO
#include "Library.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;

int main(int argc, char *args[])
{
    int const FPS = 60;
    int const frameDelay = 1000 / FPS;

    Texture_box player_texture(0, 0, 35, 42, 640, 600, 35, 42);

    Texture_box background_sky_texture(0, 0, 1280, 720, 0, 0, 1280, 720);

    Texture_box background_plains_texture(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_background_plains_texture(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[3];
    enum texture_type
    {
        BACKGROUND_SKY,
        BACKGROUND_PLAINS,
        CHARACTER
    };
    game->Texture_loader(texture, 3);

    game->render(game->getRenderer(), texture[BACKGROUND_SKY], background_sky_texture.get_sourceRect(), background_sky_texture.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], background_plains_texture.get_sourceRect(), background_plains_texture.get_destinationRect());

    game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

    const int speed = 60;

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
                break;

            case SDLK_RIGHT:
                cout << "right \n";
                SDL_RenderClear(game->getRenderer());
                for (int i = 1; i < 60; i++)
                {
                    background_plains_texture.set_destinationRect(background_plains_texture.get_destinationRect().x - speed/60, background_plains_texture.get_destinationRect().y, background_plains_texture.get_destinationRect().w, background_plains_texture.get_destinationRect().h);
                    next_background_plains_texture.set_destinationRect(next_background_plains_texture.get_destinationRect().x - speed/60, next_background_plains_texture.get_destinationRect().y, next_background_plains_texture.get_destinationRect().w, next_background_plains_texture.get_destinationRect().h);
                    if (next_background_plains_texture.get_destinationRect().x == 0)
                    {
                        background_plains_texture.set_destinationRect(1280, background_plains_texture.get_destinationRect().y, background_plains_texture.get_destinationRect().w, background_plains_texture.get_destinationRect().h);
                    }
                    if (background_plains_texture.get_destinationRect().x == 0)
                    {
                        next_background_plains_texture.set_destinationRect(1280, next_background_plains_texture.get_destinationRect().y, next_background_plains_texture.get_destinationRect().w, next_background_plains_texture.get_destinationRect().h);
                    }
                    

                    game->render(game->getRenderer(), texture[BACKGROUND_SKY], background_sky_texture.get_sourceRect(), background_sky_texture.get_destinationRect());
                    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], background_plains_texture.get_sourceRect(), background_plains_texture.get_destinationRect());
                    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_background_plains_texture.get_sourceRect(), next_background_plains_texture.get_destinationRect());
                    game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());
                }

                    cout << "\tbackground_plains_texture.destinationRect.x: " << background_plains_texture.get_destinationRect().x << "\n";
                    cout << "\tnext_background_plains_texture.destinationRect.x: " << next_background_plains_texture.get_destinationRect().x << "\n";
                break;
            }
        default:
            break;
        }

        game->update();
        SDL_RenderPresent(game->getRenderer());

        frameTime = SDL_GetTicks64() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
