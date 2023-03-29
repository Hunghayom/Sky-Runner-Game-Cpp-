#ifndef Platform_hpp
#define Platform_hpp

#include "Game.hpp"
#include "Texture_box.hpp"

class Platform
{
    private:
        Texture_box platform_hitbox;
        SDL_Texture *platform_texture;

};
#endif /* Platform_hpp */