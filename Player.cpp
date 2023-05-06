#include "Player.hpp"

Player::Player()
{
    x = 0;
    y = 0;
    speed = 0;
    jump_speed = 0;
    gravity = 0;
    width = 0;
    height = 0;
    jumping = false;
    falling = true;
}

Player::Player(double x, double y, double speed, double jump_speed, double gravity, double width, double height, bool jumping, bool falling)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->jump_speed = jump_speed;
    this->gravity = gravity;
    this->width = width;
    this->height = height;
    this->jumping = jumping;
    this->falling = falling;
}

Player::~Player()
{
}

double Player::get_x()
{
    return x;
}

double Player::get_y()
{
    return y;
}

double Player::get_speed()
{
    return speed;
}

double Player::get_jump_speed()
{
    return jump_speed;
}

double Player::get_gravity()
{
    return gravity;
}

double Player::get_width()
{
    return width;
}

double Player::get_height()
{
    return height;
}

bool Player::get_jumping()
{
    return jumping;
}
bool Player::get_falling()
{
    return falling;
}

double Player::get_max_height()
{
    return max_height;
}

void Player::set_x(double x)
{
    this->x = x;
}

void Player::set_y(double y)
{
    this->y = y;
}

void Player::set_speed(double speed)
{
    this->speed = speed;
}

void Player::set_jump_speed(double jump_speed)
{
    this->jump_speed = jump_speed;
}

void Player::set_gravity(double gravity)
{
    this->gravity = gravity;
}

void Player::set_width(double width)
{
    this->width = width;
}

void Player::set_height(double height)
{
    this->height = height;
}

void Player::set_jumping(bool jumping)
{
    this->jumping = jumping;
}
void Player::set_falling(bool falling)
{
    this->falling = falling;
}
void Player::set_max_height(double max_height)
{
    this->max_height = max_height;
}


void Player::player_falling(Player& player)
{
    if (player.get_falling() == 1)
    {
        player.set_y(player.get_y() + 10);
    }
}

bool Player::fall(Player& player, vector<SDL_Rect>& platforms)
{
    for (int i = 0; i < platforms.size(); i++)
    {
        if (player.get_x() + player.get_width() > platforms[i].x && player.get_x() < platforms[i].x + platforms[i].w)
        {
            if (player.get_y() + player.get_height() == platforms[i].y)
            {
                return false;
            }
        }
    }
    return true;
}

bool Player::is_falling(Player& player, vector<SDL_Rect>& present_platforms, vector<SDL_Rect>& next_platforms)
{
    if((fall(player, present_platforms) == 1 || fall(player, next_platforms) ==1) && (fall(player, present_platforms) == 0 || fall(player, next_platforms) == 0))
    {
        return false;
    }
    else return true;
}

void Player::player_jumping(Player& player)
{
    if (player.get_jumping() == 1 )
    {
        player.set_falling(0);
        player.set_y(player.get_y() - 10);
        player.set_max_height(player.get_max_height() + 10);
    }
}

bool Player::is_player_reach_max_heigh(Player& player, vector<SDL_Rect>& platforms)
{
    if (player.get_max_height() >= 100 )
    {
        player.set_jumping(false);
        player.set_falling(true);
        player.set_max_height(0);
        return true;
    }
    return false;
}

