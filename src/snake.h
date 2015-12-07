#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>

#ifndef PONG_SNAKE_H
#define PONG_SNAKE_H

struct game_loc {
    int x, y;

    game_loc(int col, int row) : x(col), y(row) { }

    game_loc() : x(0), y(0) { }
};

enum class game_dir {
    Up, Down, Left, Right
};

class game {
    const __useconds_t delay = 110000;

    /** graphics **/
    const chtype body_char = 'x';
    const chtype border_char = (char) 219;
    const chtype food_char = '*';

    /** screen dimensions **/
    int maxwidth;
    int maxheight;

    /** game state **/
    int points;
    bool get; //indicates that the snake get food (it makes the snake longer)
    game_dir direction; //indicates the current direction of the snake
    game_loc food;
    std::vector<game_loc> snake; //represent the snake

    void put_food ();
    bool collision();
    void tick();

public:
    game();
    ~game();
    void start();
};

#endif //PONG_SNAKE_H
