#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>
#include "Tilemap.hpp"

using namespace std;

class Player
{
private:
    double x, y; // tọa độ của player
    double speed;
    double jump_speed;
    double gravity;
    double width, height; // kích thước của player
    bool jumping;
    bool falling;
    double max_height;
public:
    Player();
    Player(double x, double y, double speed, double jump_speed, double gravity, double width, double height, bool jumping, bool falling);
    ~Player();

    double get_x();
    double get_y();
    double get_speed();
    double get_jump_speed();
    double get_gravity();
    double get_width();
    double get_height();
    bool get_jumping();
    bool get_falling();
    double get_max_height();

    void set_x(double x);
    void set_y(double y);
    void set_speed(double speed);
    void set_jump_speed(double jump_speed);
    void set_gravity(double gravity);
    void set_width(double width);
    void set_height(double height);
    void set_jumping(bool jumping);
    void set_falling(bool falling);
    void set_max_height(double max_height);

    void update_player(Player& player, vector<SDL_Rect>& platforms);

    void player_falling(Player& player);
    void player_jumping(Player& player);

    bool is_falling(Player& player, vector<SDL_Rect>& platforms);
    bool is_player_reach_max_heigh(Player& player, vector<SDL_Rect>& platforms);
};
#endif /* "Player_hpp" */