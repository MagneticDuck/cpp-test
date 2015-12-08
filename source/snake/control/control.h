/**
 * Simple and clean API for making an ASCII-display interactive app.
 */
#include <string>
#include <ncurses.h>
#include <boost/optional.hpp>
#include "snake/util/util.h"

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
    static const char *show(std::string t) {
        return t.c_str();
    }

    template<typename T>
    static const char *show(const T t) {
        return std::to_string(t).c_str();
    }

public:
    /**
     * We can print a stringifyable value to a screen location.
     * print(loc, char *) is pure virtual but the templated function
     * is defined here, dependant on the former.
     */
    virtual void print(loc a_loc, char *) = 0;
    template<typename T>
    void print(loc a_loc, T t);
    virtual void draw_border(loc corner) = 0;

    /**
     * Consistently updated frame dimensions.
     */
    struct {
        int x_max;
        int y_max;
    } dims;
};

template<typename T>
void frame_i::print(loc a_loc, T t) {
    move(a_loc.y, a_loc.x);
    printw(show(t));
}

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
