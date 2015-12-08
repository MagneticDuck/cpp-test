/**
 * Constant options for the engine and the interface.
 */
#include "snake/util/util.h"

#ifndef SNAKE_OPTIONS_H
#define SNAKE_OPTIONS_H

/**
 * General game options for internal use.
 */
struct {
    const int quit_key = 113;
    const loc board_dims{20, 20};
    const loc init_pos{10, 10};
    const dir init_dir = dir::Up;
} game_opts;

/**
 * Render options for internal use.
 */
struct {
    const char tail_char = 'x';

    const char head_char(dir a_dir) {
        switch (a_dir) {
            case dir::Up: return '^';
            case dir::Down: return 'v';
            case dir::Left: return '<';
            case dir::Right: return '>';
        }
    }

    /**
     * Convert a game location to a screen location.
     */
    const loc game_to_screen(loc a_loc) {
        return loc(2 * a_loc.x + 1, a_loc.y + 1);
    }
} rndr_opts;

#endif //SNAKE_OPTIONS_H
