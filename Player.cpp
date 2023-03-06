#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Player
{
    private:
        int health;
        int xp;
    public:
        void move_to_left();
        void move_to_right();
        void jump();
        void fall();
        void breaking_with_bare_hand();
        void breaking_with_pickaxe();
};
