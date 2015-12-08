#include "snake/engine/options.h"
#include "engine.h"

/**********************************************************************************************************************/
/* snake_engine
/**********************************************************************************************************************/

void snake_engine::start(loc player_head, dir player_movement) {
    playing = true;
    score = 0;
    this->score = score;
    this->head = player_head;
    this->movement = player_movement;
    this->tail = {};
}

void snake_engine::stop() {
    playing = false;
}

void snake_engine::render(frame_i &frame) {
    frame.print(rndr_opts.game_to_screen(head),
                rndr_opts.head_char(movement));
    for (loc tail_loc : tail) {
        frame.print(rndr_opts.game_to_screen(tail_loc),
                    rndr_opts.tail_char);
    }
}

void snake_engine::handle(dir movement) {
    this->movement = movement;
}

void snake_engine::tick() {
    if (playing) {
        head += loc{movement};
        head.clamp(game_opts.board_dims.x, game_opts.board_dims.y);
    }
}