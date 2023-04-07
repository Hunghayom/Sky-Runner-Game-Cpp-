#ifndef Moving_background_hpp
#define Moving_background_hpp

// Hàm Moving_background dùng để di chuyển các background lớn trong game (vd: đất, trời, mây, núi, biển,...)
// một cách liên tục không bị gián đoạn
// Khi nhân vật di chuyển sang PHẢI thì background di chuyển sang TRÁI.


#include "Library.hpp"

void Game::Moving_background(SDL_Texture *background, Texture_box &background_box, Texture_box &next_background_box, SDL_Renderer *renderer, int speed)
{

    background_box.set_destinationRect(background_box.get_destinationRect().x - speed, background_box.get_destinationRect().y, background_box.get_destinationRect().w, background_box.get_destinationRect().h);
    next_background_box.set_destinationRect(next_background_box.get_destinationRect().x - speed, next_background_box.get_destinationRect().y, next_background_box.get_destinationRect().w, next_background_box.get_destinationRect().h);
    if (next_background_box.get_destinationRect().x <= 0)
    {
        background_box.set_destinationRect(1280 + next_background_box.get_destinationRect().x, background_box.get_destinationRect().y, background_box.get_destinationRect().w, background_box.get_destinationRect().h);
    }
    if (background_box.get_destinationRect().x <= 0)
    {
        next_background_box.set_destinationRect(1280 + background_box.get_destinationRect().x, next_background_box.get_destinationRect().y, next_background_box.get_destinationRect().w, next_background_box.get_destinationRect().h);
    }
}
#endif /* Moving_background_hpp*/