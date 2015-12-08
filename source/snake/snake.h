#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include "snake/control/control.h"
#include "snake/util/util.h"

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class snakey_game : public game_i {
    const int quit_key = 113;

    // interface
    bool concluded = false;
    tickertape title{30, 30};
    int lifetime = 0;

    // ticking
    const double tick_dur = 0.8;
    const double anim_dur = 1.3;
    double tick_cooldown = 0;
    double anim_cooldown = 0;

    // game
    loc head{};
    std::vector<loc> tail{};
    dir movement = dir::Up;

    void game_tick();
    void anim_tick();

    // rendering
    loc game_to_screen(loc);

public:
    void tick(double delta) override;
    void render(frame_i &frame) override;
    void handle(int key) override;
    bool conclude() override;
};

#endif //PONG_SNAKE_H
