// Using SDL and standard IO
#include "Library.hpp"
#include <fstream>

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Game *game = nullptr;
Player *player = nullptr;

int main(int argc, char *args[])
{
    ofstream outfile;
    outfile.open("log.txt");

    int const FPS = 60;
    int const frameDelay = 1000 / FPS;
    player = new Player(320, 300, 1, -10, 0.5, 70, 90, false, false);

    Texture_box player_texture(0, 0, player->get_width(), player->get_height(), player->get_x(), player->get_y(), player->get_width(), player->get_height());

    Texture_box sky(0, 0, 1280, 720, 0, 0, 1280, 720);

    Texture_box plains(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_plains(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Texture_box mountain(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_mountain(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Texture_box cloud(0, 0, 1280, 720, 0, 0, 1280, 720);
    Texture_box next_cloud(0, 0, 1280, 720, 1280, 0, 1280, 720);

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("Sky Runner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    SDL_Texture *texture[4];
    enum texture_type
    {
        BACKGROUND_SKY,
        BACKGROUND_MOUNTAIN,
        BACKGROUND_PLAINS,
        BACKGROUND_CLOUD,
        CHARACTER,
        MENU,
        INSTRUCTION,

    };
    game->loadTexture(texture[BACKGROUND_SKY], game->getRenderer(), "Image/Background/Sky.png");
    game->loadTexture(texture[BACKGROUND_MOUNTAIN], game->getRenderer(), "Image/Background/mountain.png");
    game->loadTexture(texture[BACKGROUND_PLAINS], game->getRenderer(), "Image/Background/plains_ground.png");
    game->loadTexture(texture[BACKGROUND_CLOUD], game->getRenderer(), "Image/Background/cloud.png");
    game->loadTexture(texture[CHARACTER], game->getRenderer(), "Image/Character/Character.png");
    game->loadTexture(texture[MENU], game->getRenderer(), "Image/Menu/menu.png");
    game->loadTexture(texture[INSTRUCTION], game->getRenderer(), "Image/Menu/instruction.png");

    Texture_box tilemap_texture(0, 0, 40, 40, 0, 0, 40, 40);
    SDL_Texture *pT;
    game->loadTexture(pT, game->getRenderer(), "Image/Background/test.png");

    int present_tilemap_pos_x = 0;
    int next_tilemap_pos_x = 1280;

    Tilemap array_of_tilemap[18] = {Default_tilemap, Tilemap_1, Tilemap_2, Tilemap_3, Tilemap_4, Tilemap_5, Tilemap_6, Tilemap_7, Tilemap_8, Tilemap_9, Tilemap_10, Tilemap_11, Tilemap_12, Tilemap_13, Tilemap_14, Tilemap_15, Tilemap_16, Tilemap_17};
    vector<SDL_Rect> platform_rects[18] = {Default_tilemap.get_platform_rects(), Tilemap_1.get_platform_rects(), Tilemap_2.get_platform_rects(), Tilemap_3.get_platform_rects(), Tilemap_4.get_platform_rects(), Tilemap_5.get_platform_rects(), Tilemap_6.get_platform_rects(), Tilemap_7.get_platform_rects(), Tilemap_8.get_platform_rects(), Tilemap_9.get_platform_rects(), Tilemap_10.get_platform_rects(), Tilemap_11.get_platform_rects(), Tilemap_12.get_platform_rects(), Tilemap_13.get_platform_rects(), Tilemap_14.get_platform_rects(), Tilemap_15.get_platform_rects(), Tilemap_16.get_platform_rects(), Tilemap_17.get_platform_rects()};

    const int speed = 4;
    bool is_first_tilemap = true;
    int present_tilemap_index = 0;
    int next_tilemap_index = game->random_tilemap(18, game->getScore());

    vector<SDL_Rect> present_platform_rects = platform_rects[0];
    vector<SDL_Rect> next_platform_rects = platform_rects[next_tilemap_index];

    Tilemap present_tilemap = array_of_tilemap[present_tilemap_index];
    Tilemap next_tilemap = array_of_tilemap[next_tilemap_index];

    game->start();

    present_platform_rects = array_of_tilemap[present_tilemap_index].update_platform_rects(present_tilemap, present_tilemap_pos_x);

    next_platform_rects = next_tilemap.update_platform_rects(next_tilemap, next_tilemap_pos_x);

    int count = 0;
    //Game-start log
    {
    outfile << "Game start!\n";
    outfile << "---------------------------------------------" << endl;
    outfile << "Number of key event: " << count << endl;
    outfile << "Player: " << player->get_x() << " " << player->get_y() << " " << player->get_width() << " " << player->get_height() << endl;
    outfile << "Falling: " << player->get_falling() << endl;
    outfile << "Jumping: " << player->get_jumping() << endl;
    outfile << "Present_tilemap_index: [" << present_tilemap_index << "]" << endl;
    for (int i = 0; i < present_platform_rects.size(); i++)
    {
        outfile << "\tplatform[" << i << "]_rect: " << present_platform_rects[i].x << " " << present_platform_rects[i].y << " " << platform_rects[0][i].w << " " << present_platform_rects[i].h << endl;
    }
    outfile << "Next_tilemap_index: [" << next_tilemap_index << "]" << endl;
    for (int i = 0; i < next_platform_rects.size(); i++)
    {
        outfile << "\tnext_platform[" << i << "]_rect: " << next_platform_rects[i].x << " " << next_platform_rects[i].y << " " << next_platform_rects[i].w << " " << next_platform_rects[i].h << endl;
    }
    outfile << "---------------------------------------------" << endl;
    }

    game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());

    game->render(game->getRenderer(), texture[BACKGROUND_CLOUD], cloud.get_sourceRect(), cloud.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_CLOUD], next_cloud.get_sourceRect(), next_cloud.get_destinationRect());

    game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], next_mountain.get_sourceRect(), next_mountain.get_destinationRect());

    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_plains.get_sourceRect(), next_plains.get_destinationRect());
    game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

    game->render(game->getRenderer(), texture[MENU], main_menu_screen_box.get_sourceRect(), main_menu_screen_box.get_destinationRect());
    SDL_RenderPresent(game->getRenderer());
    
    while (game->menu())
    {
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
            case SDLK_KP_ENTER:
                game->setPlaying(true);
                game->setMenu(false);
                break;
            default:
                break;
            }
        }
    }

    while (game->playing())
    {
        frameStart = SDL_GetTicks64();

        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            game->setPlaying(false);
            game->setRunning(false);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game->setPlaying(false);
                game->setRunning(false);
                break;
            case SDLK_UP:
                player->set_jumping(true);
                player->player_jumping(*player);
                player->is_player_reach_max_heigh(*player, present_platform_rects);
                break;

            case SDLK_RIGHT:
                count++;
                outfile << "Number of key event: " << count << endl;

                present_platform_rects = present_tilemap.update_platform_rects(present_tilemap, -speed);

                next_platform_rects = next_tilemap.update_platform_rects(next_tilemap, -speed);

                player->set_falling(player->is_falling(*player, present_platform_rects, next_platform_rects));

                player->player_falling(*player);

                player->player_jumping(*player);
                player->is_player_reach_max_heigh(*player, present_platform_rects);
                player_texture.set_destinationRect(player->get_x(), player->get_y(), player->get_width(), player->get_height());

                outfile << "Player: " << player->get_x() << " " << player->get_y() << " " << player->get_width() << " " << player->get_height() << endl;

                outfile << "Falling: " << player->get_falling() << endl;
                outfile << "Jumping: " << player->get_jumping() << endl;

                outfile << "Present_tilemap_index: [" << present_tilemap_index << "]" << endl;
                for (int i = 0; i < present_platform_rects.size(); i++)
                {
                    outfile << "\tplatform[" << i << "]_rect: " << present_platform_rects[i].x << " " << present_platform_rects[i].y << " " << platform_rects[0][i].w << " " << present_platform_rects[i].h << endl;
                }
                outfile << "Next_tilemap_index: [" << next_tilemap_index << "]" << endl;
                for (int i = 0; i < next_platform_rects.size(); i++)
                {
                    outfile << "\tnext_platform[" << i << "]_rect: " << next_platform_rects[i].x << " " << next_platform_rects[i].y << " " << next_platform_rects[i].w << " " << next_platform_rects[i].h << endl;
                }
                outfile << "---------------------------------------------" << endl;

                // game->Moving_background(texture[BACKGROUND_CLOUD], cloud, next_cloud, game->getRenderer(), speed / 3);
                game->Moving_background(texture[BACKGROUND_MOUNTAIN], mountain, next_mountain, game->getRenderer(), speed / 2.1);
                game->Moving_background(texture[BACKGROUND_PLAINS], plains, next_plains, game->getRenderer(), speed / 1.25);

                present_tilemap_pos_x -= speed;
                next_tilemap_pos_x -= speed;
                break;
            }
        default:

            break;
        }

        // Background render

        game->render(game->getRenderer(), texture[BACKGROUND_SKY], sky.get_sourceRect(), sky.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_CLOUD], cloud.get_sourceRect(), cloud.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_CLOUD], next_cloud.get_sourceRect(), next_cloud.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], mountain.get_sourceRect(), mountain.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_MOUNTAIN], next_mountain.get_sourceRect(), next_mountain.get_destinationRect());

        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_plains.get_sourceRect(), next_plains.get_destinationRect());
        game->render(game->getRenderer(), texture[BACKGROUND_PLAINS], plains.get_sourceRect(), plains.get_destinationRect());

        game->render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

        // Tilemap render

        if (is_first_tilemap || present_tilemap_pos_x <= -1280)
        {
            if (is_first_tilemap)
            {
                game->infinite_tilemap(array_of_tilemap, 18, tilemap_texture, pT, 0, next_tilemap_index, present_tilemap_pos_x, next_tilemap_pos_x, speed);
                // present_platform_rects = platform_rects[present_tilemap_index];
                if (present_tilemap_pos_x == -1280)
                {
                    is_first_tilemap = false;
                }
            }
            else
            {
                present_tilemap_index = next_tilemap_index;
                next_tilemap_index = game->random_tilemap(18, game->getScore());

                present_tilemap = array_of_tilemap[present_tilemap_index];
                next_tilemap = array_of_tilemap[next_tilemap_index];

                present_platform_rects.clear();
                next_platform_rects.clear();

                present_platform_rects = platform_rects[present_tilemap_index]; // dòng này đang bị lỗi: gán xong trả về giá trị w ảo

                outfile << "Present_tilemap_index_after_update: [" << present_tilemap_index << "]" << endl;
                for (int i = 0; i < present_platform_rects.size(); i++)
                {
                    outfile << "\tplatform[" << i << "]_rect: " << present_platform_rects[i].x << " " << present_platform_rects[i].y << " " << platform_rects[0][i].w << " " << present_platform_rects[i].h << endl;
                }
                outfile << "---------------------------------------------" << endl;

                next_platform_rects = platform_rects[next_tilemap_index];

                present_tilemap_pos_x = 0;
                next_tilemap_pos_x = 1280;

                present_platform_rects = present_tilemap.update_platform_rects(present_tilemap, present_tilemap_pos_x);
                next_platform_rects = next_tilemap.update_platform_rects(next_tilemap, next_tilemap_pos_x);
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

        game->death_message(*player);
    }

    game->clean();
    outfile << "Game cleaned!\n";
    outfile << "---------------------------------------------" << endl;
    return 0;
}