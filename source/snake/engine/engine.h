/**
 * Represents the logical core of snakey.
 */
#include <iostream>
#include <vector>
#include "snake/control/control.h"

#ifndef SNAKE_ENGINE_H
#define SNAKE_ENGINE_H

class snake_engine {
public:
    bool playing = false;
    int score = 0;
    loc head{};
    dir movement = dir::Up;
    std::vector<loc> tail{};

    void start(loc player_head, dir player_movement);
    void stop();
    void render(frame_i &frame);
    void handle(dir movement);
    void tick();
};


#endif //SNAKE_ENGINE_H
