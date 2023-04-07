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

    Texture_box sky(0, 0, 1280, 720, 0, 0, 1280, 720);

    Texture_box plains(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_plains(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Texture_box mountain(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_mountain(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Texture_box thu_nghiem(0, 0, 100, 100, 0, 0, 100, 100);

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[5];
    enum texture_type
    {
        BACKGROUND_SKY,
        BACKGROUND_MOUNTAIN,
        BACKGROUND_PLAINS,
        CHARACTER,
        //thu_nghiem
    };
    game->Texture_loader(texture, 3);

    game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

    game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

//game->render(game->getRenderer(), texture[thu_nghiem],thu_nghiem.get_sourceRect(), thu_nghiem.get_destinationRect());

    const int speed = 5;

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
                game->Moving_background(texture[BACKGROUND_MOUNTAIN], mountain, next_mountain, game->getRenderer(), 30);
                game->Moving_background(texture[BACKGROUND_PLAINS], plains, next_plains, game->getRenderer(), 40);
                break;
            }
        default:
            break;
        }

        game->update();

        game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], next_mountain.get_sourceRect(), next_mountain.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_plains.get_sourceRect(), next_plains.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

        game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

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
