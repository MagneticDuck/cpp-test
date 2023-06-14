/**
 * Various utilities for our game.
 */
#ifndef SNAKE_UTIL_H
#define SNAKE_UTIL_H

#include <string>
#include <algorithm>

/**********************************************************************************************************************/
/* dir, loc
/**********************************************************************************************************************/

/**
 * A direction something can travel along.
 */
enum class dir {
    Up, Down, Left, Right
};

bool dirs_are_contrary(dir a_dir, dir b_dir);

/**
 * A position on the screen or a position delta.
 */
struct loc {
    int x, y;

    loc(int col, int row);
    loc(dir some_dir);
    loc();

    void operator+=(loc a_loc);
    bool clamp(int max_x, int max_y); // returns true if clamping occured
};

bool operator==(loc a_loc, loc b_loc);
loc operator+(loc a_loc, loc b_loc);

loc random_loc(loc dims);

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

public:
    double period;
    ticker(double period) : period(period) { }

    bool tick(double delta);
    void reset();
    operator bool();
};

#endif //SNAKE_UTIL_H
