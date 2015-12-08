#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include "snake/engine/options.h"
#include "snake/control/control.h"
#include "snake/util/util.h"
#include "snake/engine/engine.h"

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class snakey_game : public game_i {
    // tickatickatickaticka
    tickertape title{rndr_opts::advice_width, rndr_opts::advice_length};
    std::string advice;

    // tickers
    ticker anim_ticker{0.2}; // animation things tick
    ticker game_ticker{0.1}; // the game ticks
    ticker advice_ticker{10}; // the game dispenses valuable advice

    // game
    struct {
        bool playing = false;
        bool inited = false;
        bool ended = false;
    } menu_state;
    snake_engine game;

    void anim_tick();

public:
    void tick(double delta) override;
    void render(frame_i &frame) override;
    void handle(int key) override;
};

#endif //PONG_SNAKE_H
