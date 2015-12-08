/**
 * Various utilities for our game.
 */
#ifndef SNAKE_UTIL_H
#define SNAKE_UTIL_H

/**********************************************************************************************************************/
/* dir, loc
/**********************************************************************************************************************/

#include <bits/stringfwd.h>
#include <boost/optional/optional.hpp>

/**
 * A direction something can travel along.
 */
enum class dir {
    Up, Down, Left, Right
};

/**
 * Turn an arrow-key keycode into a dir.
 */
boost::optional<dir> key_to_dir(int a_key);

/**
 * A position on the screen.
 */
struct loc {
    int x, y;

    loc(int col, int row);
    loc(dir some_dir);
    loc();

    void operator+=(loc a_loc);
    void clamp(int max_x, int max_y);
};

/**********************************************************************************************************************/
/* tickertape
/**********************************************************************************************************************/

/**
 * A rolling 'digital tickertape' with fixed message and display width.
 */
class tickertape {
private:
    int iter = 0;

    char at_index(int i) {
        if (i < std::min((int) text.length(), str_width))
            return text[i];
        else return ' ';
    }

    const int loop_length;

public:
    const int disp_width;
    const int str_width;

    std::string text = "";
    tickertape(const int disp_width, const int str_width);
    void tick();
    std::string print();
};

/**********************************************************************************************************************/
/* ticker
/**********************************************************************************************************************/

/**
 * Manages an action that becomes momentarily active on regular intervals. (The 'tick' of an analog clock is the analogy
 * that inspires its name.)
 */
class ticker {
private:
    bool active = false;
    double cooldown = 0;
    const double period;

public:
    ticker(double period) : period(period) { }

    bool tick(double delta);
    operator bool();
};

#endif //SNAKE_UTIL_H
