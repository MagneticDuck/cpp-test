/**
 * Represents the logical core of snakey.
 */
#include <iostream>
#include <vector>
#include "snake/control/control.h"

#ifndef SNAKE_ENGINE_H
#define SNAKE_ENGINE_H

class snake_engine {
private:
    bool move();

public:
    bool failure = false;
    double score = 0;

    loc head{};
    dir movement = dir::Up;
    std::vector<loc> tail{};
    std::vector<loc> food{};
    int target_tail = 0;

    void init(loc player_head, dir player_movement);
    void render(frame_i &frame);
    void handle(dir movement);
    void tick();
};


#endif //SNAKE_ENGINE_H
