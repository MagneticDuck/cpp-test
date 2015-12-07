#include <iostream>
#include <vector>
#include <ncurses.h>
#include "game.h"
#include <cstdlib>

#ifndef PONG_SNAKE_H
#define PONG_SNAKE_H

/*********************************************************************************************************************/
/* basic snakey_game state types
/*********************************************************************************************************************/

namespace snake {
/**
 * Location on the screen. Could use a vector; this implementation is purely pedagogical.
 */
    struct loc {
        int x, y;

        loc(int col, int row) : x(col), y(row) { }

        loc() : x(0), y(0) { }
    };

/**
 * A direction something can travel along.
 */
    enum class dir {
        Up, Down, Left, Right
    };

/*********************************************************************************************************************/
/* snakey_game class
/*********************************************************************************************************************/

    class snakey_game : public game_i {
        const int quit_key = 113;
        bool concluded = false;

        int key = 0;
        int key_count = 0;
    public:
        snakey_game();
        ~snakey_game();

        void tick(double delta) override;
        void render(double delta) override;
        void handle(int key) override;
        bool conclude() override;

    };
}

#endif //PONG_SNAKE_H

