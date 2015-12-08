#include <iostream>
#include <vector>
#include <ncurses.h>
#include "game.h"
#include <cstdlib>

#ifndef PONG_SNAKE_H
#define PONG_SNAKE_H

class tickertape {
private:
    int iter = 0;

    char at_index(int i) {
        if (i < std::min((int) text.length(), str_width))
            return text[i];
        else return ' ';
    }

public:
    const int disp_width;
    const int str_width;
    const int loop_length;
    // the number of positions the ticker tape can be in
    // equal to max(dist_width, str_width);

    std::string text = "";

    /**
     * disp_width: the length that the displayed string is
     * str_width: the length of the tickertape message
     */
    tickertape(const int disp_width, const int str_width)
            : disp_width(disp_width), str_width(str_width),
              loop_length(std::max(disp_width, str_width)) { }

    void tick() {
        iter = (iter + 1) % loop_length;
    }

    std::string print();
};


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
    void render() override;
    void handle(int key) override;
    bool conclude() override;
};

#endif //PONG_SNAKE_H
