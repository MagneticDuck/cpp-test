/**
 * Simple and clean API for making an ASCII-display interactive app.
 */
#include <string>
#include <ncurses.h>
#include <boost/optional.hpp>
#include "snake/util/util.h"

#ifndef SNAKE_CONTROL_H
#define SNAKE_CONTROL_H

/**
 * An interface representing a frame where you can draw ASCII graphics.
 */
class frame_i {
public:
    /** string conversion utilities **/
    template<typename T>
    static const char *show(const T t) {
        return std::to_string(t).c_str();
    }

    static const char *show(std::string t) {
        return t.c_str();
    }

    /** drawing **/
    virtual void print(loc a_loc, char *) = 0;
    template<typename T>
    void print(loc a_loc, T t);
    virtual void draw_border(loc corner) = 0;

    /** state variables **/
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

/**
 * An interface representing an interactive application.
 */
class game_i {
public:
    /**
     * Tick your logic, with a delta interval in seconds since the last tick.
     */
    virtual void tick(double delta) = 0;

    /**
     * Render graphics to a frame_i.
     */
    virtual void render(frame_i &frame) = 0;

    /**
     * Handle a keypress with a certain code.
     */
    virtual void handle(int key) = 0;

    /**
     * Return true here to exit.
     */
    virtual bool conclude() = 0;
};

#endif //GAME_H
