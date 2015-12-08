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

    const int loop_len() {
        return std::max((int) text.length(), width);
    };

    char at_index(int i) {
        if (i < text.length()) return text[i];
        else return ' ';
    }

public:
    int width;
    std::string text;

    tickertape(int width, std::string text)
            : width(width), text(text) { }

    void tick() {
        iter = (iter + 1) % loop_len();
    }

    std::string print();
};


class snakey_game : public game_i {
    const int quit_key = 113;

    // interface
    bool concluded = false;
    tickertape title{30, "title"};
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
