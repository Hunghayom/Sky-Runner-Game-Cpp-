#ifndef Moving_background_hpp
#define Moving_background_hpp

// Hàm Moving_background dùng để di chuyển các background lớn trong game (vd: đất, trời, mây, núi, biển,...)
//  một cách liên tục không bị gián đoạn
//  Khi nhân vật di chuyển sang PHẢI thì background di chuyển sang TRÁI.

#include "Library.hpp"


void Game::Moving_background(SDL_Texture *background, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer *renderer, int speed)
{
    /*
    Texture_box background_plains_texture(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    Texture_box next_background_plains_texture(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    background_plains_texture.set_destinationRect(background_plains_texture.get_destinationRect().x - speed, background_plains_texture.get_destinationRect().y, background_plains_texture.get_destinationRect().w, background_plains_texture.get_destinationRect().h);
    next_background_plains_texture.set_destinationRect(next_background_plains_texture.get_destinationRect().x - speed, next_background_plains_texture.get_destinationRect().y, next_background_plains_texture.get_destinationRect().w, next_background_plains_texture.get_destinationRect().h);
    if (next_background_plains_texture.get_destinationRect().x == 0)
    {
        background_plains_texture.set_destinationRect(1280, background_plains_texture.get_destinationRect().y, background_plains_texture.get_destinationRect().w, background_plains_texture.get_destinationRect().h);
    }
    if (background_plains_texture.get_destinationRect().x == 0)
    {
        next_background_plains_texture.set_destinationRect(1280, next_background_plains_texture.get_destinationRect().y, next_background_plains_texture.get_destinationRect().w, next_background_plains_texture.get_destinationRect().h);
    }
    cout << "\tbackground_plains_texture.destinationRect.x: " << background_plains_texture.get_destinationRect().x << "\n";
    cout << "\tnext_background_plains_texture.destinationRect.x: " << next_background_plains_texture.get_destinationRect().x << "\n";

    //render(game->getRenderer(), texture[BACKGROUND_SKY], background_sky_texture.get_sourceRect(), background_sky_texture.get_destinationRect());
    //render(game->getRenderer(), texture[BACKGROUND_PLAINS], background_plains_texture.get_sourceRect(), background_plains_texture.get_destinationRect());
    //render(game->getRenderer(), texture[BACKGROUND_PLAINS], next_background_plains_texture.get_sourceRect(), next_background_plains_texture.get_destinationRect());
    //render(game->getRenderer(), texture[CHARACTER], player_texture.get_sourceRect(), player_texture.get_destinationRect());

*/

}
#endif /* Moving_background_hpp*/