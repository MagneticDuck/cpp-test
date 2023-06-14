/**
 * Simple and clean API for making an ASCII-display interactive app.
 */
#include <string>
#include <ncurses.h>
#include <boost/optional.hpp>
#include "util.h"

#ifndef SNAKE_CONTROL_H
#define SNAKE_CONTROL_H

/**********************************************************************************************************************/
/* frame_i
/**********************************************************************************************************************/

/**
 * An interface representing a frame where you can draw ASCII graphics.
 */
class frame_i {
private:
    static char *show(std::string t) {
        return (char *) t.c_str();
    }

    template<typename T>
    static const char *show(const T t) {
        return std::to_string(t).c_str();
    }

public:
    virtual void print_c(loc a_loc, char *) = 0;

    template<typename T>
    void print(loc a_loc, T t) {
        print_c(a_loc, show(t));
    }

    void print(loc a_loc, char c) {
        // TODO: make sense of this char* / const char* / string conversion?
        print_c(a_loc, show((std::string) "" + c));
    }

    virtual void draw_border(loc corner) = 0;

    /**
     * Consistently updated frame dimensions.
     */
    struct {
        int x_max;
        int y_max;
    } dims;
};

/**********************************************************************************************************************/
/* game_i
/**********************************************************************************************************************/

/**
 * An interface representing an interactive application.
 */
class game_i {
public:
    bool concluded; // set this to true to exit

    /**
     * Tick your logic forwards in function of a delta interval, given in seconds, in seconds since the last tick.
     */
    virtual void tick(double delta) = 0;

    /**
     * Render graphics to the frame.
     */
    virtual void render(frame_i &frame) = 0;

    /**
     * Handle a keypress with a given key-code.
     */
    virtual void handle(int key) = 0;
};

#endif //GAME_H
