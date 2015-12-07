//
// Created by magneticduck on 12/7/15.
//

#include <bits/types.h>
#include <unistd.h>
#include "game.h"

namespace {
    const __useconds_t delay = 10000;
}

void run_game(game_i &game) {
    while (1) {
        game.tick(100);
        usleep(delay);
        if (game.conclude()) break;
    }
}

