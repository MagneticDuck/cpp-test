#include "snake/engine/options.h"
#include "engine.h"

/**********************************************************************************************************************/
/* snake_engine
/**********************************************************************************************************************/

void snake_engine::init(loc player_head, dir player_movement) {
    failure = false;
    score = 0;

    this->head = player_head;
    this->movement = player_movement;
    this->momentum = player_movement;
    this->tail = {};
    this->target_tail = 2;

    set_food();
}

void snake_engine::render(frame_i &frame) {
    for (loc tail_loc : tail) {
        frame.print(rndr_opts::game_to_screen(tail_loc),
                    rndr_opts::tail_char);
    }
    for (loc food_loc : food) {
        frame.print(rndr_opts::game_to_screen(food_loc),
                    rndr_opts::food_char);
    }
    frame.print(rndr_opts::game_to_screen(head),
                rndr_opts::head_char(movement));
}

void snake_engine::handle(dir movement) {
    if (!dirs_are_contrary(movement, this->momentum))
        this->movement = movement;
}

/**********************************************************************************************************************/
/* ticking
/**********************************************************************************************************************/

const bool touching(loc head, std::vector<loc> targets) {
    for (loc target :targets) if (head == target) return true;
    return false;
}

bool snake_engine::move() {
    momentum = movement;
    loc new_head = head + loc{movement};
    if (new_head.clamp(game_opts::board_dims.x, game_opts::board_dims.y)) {
        // we've hit the wall
        return true;
    } else {
        if (touching(new_head, tail) != 0) {
            // we're touching our tail; ew
            return true;
        } else {
            head = new_head;
            return false;
        }
    }
}

void snake_engine::set_food() {
    food.clear();
    food.push_back(random_loc(game_opts::board_dims));
}

void snake_engine::tick() {
    if (failure) return;

    score += 0.01;

    loc old_head = head;
    loc shedded;
    bool has_shedded = false;
    if (tail.size() > 0) {
        shedded = tail.at(0);
        has_shedded = true;
    }

    if (tail.size() >= target_tail) tail.erase(tail.begin());

    if (move()) {
        failure = true;
        head = old_head;
        if (has_shedded) tail.push_back(shedded);
        return;
    }

    tail.push_back(old_head);

    if (touching(head, food)) {
        score += 1;
        target_tail++;
        set_food();
    }
}

