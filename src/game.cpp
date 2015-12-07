//
// Created by magneticduck on 12/7/15.
//

#include "game.h"

namespace {
    const __useconds_t delay = 10000;
}

void run_game(game_i &game) {
    while (1) {
        tick();
        if (direction == 'q')
            break;
        usleep(delay);
    }
}
