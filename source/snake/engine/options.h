/**
 * Constant options for the engine and the interface.
 */
#include "snake/util/util.h"
#include <boost/optional/optional.hpp>
#include <random>

#ifndef SNAKE_OPTIONS_H
#define SNAKE_OPTIONS_H

/**
 * General game options for internal use.
 */
namespace game_opts {
/** key bindings **/
static const int quit_key = 113;

/**
 * Turn an arrow-key keycode into a dir.
 */
static boost::optional<dir> key_to_dir(int a_key) {
    switch (a_key) {
        case 260: return boost::optional<dir>(dir::Left);
        case 261: return boost::optional<dir>(dir::Right);
        case 259: return boost::optional<dir>(dir::Up);
        case 258: return boost::optional<dir>(dir::Down);
        default: return boost::optional<dir>();
    }
}

//static boost::optional<menu_action>(int a_key) {
//    switch (a_key) {
//        case 260: return boost::optional<dir>(menu_action::Up);
//        case 261: return boost::optional<dir>(menu_action::Down);
//        case 259: return boost::optional<dir>(menu_action::Up);
//        case 258: return boost::optional<dir>(menu_action::Down);
//        default: return boost::optional<dir>();
//    }
//};

/** game values **/
static loc board_dims{20, 20};
static loc init_pos{10, 10};
static dir init_dir = dir::Up;
};

/**
 * Render options for internal use.
 */
namespace rndr_opts {
/** positioning **/
static const int advice_width = 30;

static const loc game_to_screen(loc a_loc) {
    return loc(2 * a_loc.x + 1, a_loc.y + 1);
}

/** printing **/
static const char tail_char = 'x';

static const char head_char(dir a_dir) {
    switch (a_dir) {
        case dir::Up: return '^';
        case dir::Down: return 'v';
        case dir::Left: return '<';
        case dir::Right: return '>';
    }
}

static const std::string print_score(double score) {
    std::string level;
    switch ((int) std::floor(score / 20)) {
        case 0: level = "newbie";
            break;
        case 1: level = "initiated";
            break;
        case 2: level = "baby steps";
            break;
        case 3: level = "runner-up";
            break;
        case 4: level = "predator snake";
            break;
        case 5: level = "eagle";
            break;
        default: level = "quite good";
            break;
    }
    return "score: " + std::to_string((int) std::floor(score)) + " (" + level + ")";
}

/** cheeky advice **/
static const std::string print_advice() {
    static const std::vector<std::string> choices{"yipeee", "keep snaking!", "you're goind good"};

    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(0, (int) choices.size() - 1);

    return choices[distribution(generator)];
}

static const int advice_length = 30;
};

#endif //SNAKE_OPTIONS_H
