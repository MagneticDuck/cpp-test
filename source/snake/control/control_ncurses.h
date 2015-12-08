//
// Created by magneticduck on 12/8/15.
//

#ifndef SNAKE_CONTROL_NCURSES_H
#define SNAKE_CONTROL_NCURSES_H

#include "control.h"

class frame_ncurses : public frame_i {
private:
    void update_dims();
public:
    frame_ncurses();

    void print(loc a_loc, char *);
    void draw_border(loc corner);

    void tick();
};


void run_game_ncurses(game_i &game);

#endif //SNAKE_CONTROL_NCURSES_H
