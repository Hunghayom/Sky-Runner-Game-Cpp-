#ifndef Main_menu_hpp
#define Main_menu_hpp

#include "Game.hpp"
#include "Texture_box.hpp"

using namespace std;

enum menu_state
{
    MAIN_MENU,
};

Texture_box main_menu_screen_box(0, 0, 1280, 720, 0, 0, 1280, 720);
Texture_box instruction_screen_box(0, 0, 1280, 720, 0, 0, 1280, 720);
Texture_box infor_screen_box(0, 0, 1280, 720, 0, 0, 1280, 720);

SDL_Rect new_game_button = {360, 320, 560, 80};
SDL_Rect instruction_button = {360, 440, 560, 80};
SDL_Rect setting_button = {360, 560, 260, 80};
SDL_Rect quit_button= {660, 560, 260, 80};

SDL_Rect main_menu_button[4] = {new_game_button, instruction_button, setting_button, quit_button};

bool isMouseInside(int mouseX, int mouseY, SDL_Rect button) {
    return (mouseX >= button.x && mouseX <= button.x + button.w && mouseY >= button.y && mouseY <= button.y + button.h);
}

#endif /* Main_menu_hpp */