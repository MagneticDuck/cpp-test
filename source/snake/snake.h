#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include "snake/control/control.h"
#include "snake/util/util.h"
#include "snake/engine/engine.h"

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class snakey_game : public game_i {
    // tickatickatickaticka
    tickertape title{30, 30};

    // tickers
    ticker anim_ticker{0.4}; // animation things tick every 0.4 seconds
    ticker game_ticker{0.1}; // the game ticks every 0.1 seconds

    // game
    snake_engine game;

    void anim_tick();

public:
    void tick(double delta) override;
    void render(frame_i &frame) override;
    void handle(int key) override;
};

#endif //PONG_SNAKE_H
