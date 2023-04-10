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

    };
    game->Texture_loader(texture, 3);

    game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

    game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

    Texture_box tilemap_texture(0, 0, 40, 40, 0, 0, 40, 40);
    SDL_Texture *pT;
    game->loadTexture(pT, game->getRenderer(), "Image/Background/test.png");

    int present_tilemap_pos_x = 0;
    int next_tilemap_pos_x = 1280;

    Tilemap array_of_tilemap[18] = {Default_tilemap, Tilemap_1, Tilemap_2, Tilemap_3, Tilemap_4, Tilemap_5, Tilemap_6, Tilemap_7, Tilemap_8, Tilemap_9, Tilemap_10, Tilemap_11, Tilemap_12, Tilemap_13, Tilemap_14, Tilemap_15, Tilemap_16, Tilemap_17};

    game->drawing_tilemap(Default_tilemap, tilemap_texture, pT, present_tilemap_pos_x);
    game->drawing_tilemap(array_of_tilemap[1], tilemap_texture, pT, next_tilemap_pos_x);
    SDL_RenderPresent(game->getRenderer());

    const int speed = 40;
    bool is_first_tilemap = true;
    int present_tilemap_index = 0;
    int next_tilemap_index = game->random_tilemap(18, game->getScore());
    game->start();

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
            case SDLK_RIGHT:
                game->Moving_background(texture[BACKGROUND_MOUNTAIN], mountain, next_mountain, game->getRenderer(), speed / 4);
                game->Moving_background(texture[BACKGROUND_PLAINS], plains, next_plains, game->getRenderer(), speed);

                present_tilemap_pos_x -= speed;
                next_tilemap_pos_x -= speed;

                break;
            }
        default:

            break;
        }

        // Background render

        game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], next_mountain.get_sourceRect(), next_mountain.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_plains.get_sourceRect(), next_plains.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

        game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

        // Tilemap render

        if (is_first_tilemap || present_tilemap_pos_x == -1280)
        {
            if (is_first_tilemap)
            {
                game->infinite_tilemap(array_of_tilemap, 18, tilemap_texture, pT, 0, next_tilemap_index, present_tilemap_pos_x, next_tilemap_pos_x, speed);
                if (present_tilemap_pos_x == -1280)
                {
                    is_first_tilemap = false;
                }
            }
            else
            {
                // present_tilemap_index = game->random_tilemap(6, game->getScore());
                swap(present_tilemap_index, next_tilemap_index);
                next_tilemap_index = game->random_tilemap(18, game->getScore());

                present_tilemap_pos_x = 0;
                next_tilemap_pos_x = 1280;

                cout << "present_tilemap_index: " << present_tilemap_index << endl;
                //cout << "next_tilemap_index: " << next_tilemap_index << endl;
            }
        }
        game->drawing_tilemap(array_of_tilemap[present_tilemap_index], tilemap_texture, pT, present_tilemap_pos_x);
        game->drawing_tilemap(array_of_tilemap[next_tilemap_index], tilemap_texture, pT, next_tilemap_pos_x);
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
