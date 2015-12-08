#include <string>
#include <ncurses.h>
#include <boost/optional.hpp>

#ifndef GAME_H
#define GAME_H

/*********************************************************************************************************************/
/* dir and loc
/*********************************************************************************************************************/

/**
 * A direction something can travel along.
 */
enum class dir {
    Up, Down, Left, Right
};

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

boost::optional<dir> key_to_dir(int a_key);
std::string show_dir(dir a_dir);

/*********************************************************************************************************************/
/* game_i
/*********************************************************************************************************************/

/**
 * An interface for an interactive game.
 */
class game_i {
public:
    virtual void tick(double delta);
    virtual void render();
    virtual void handle(int key);
    virtual bool conclude();

    /** static, non-virtual helper functions **/
    template<typename T>
    const char *show(const T t) {
        return std::to_string(t).c_str();
    }
    template<typename T>
    void print(loc a_loc, T t) {
        move(a_loc.y, a_loc.x);
        printw(show(t));
    }
    static void print(loc a_loc, char *);
    static void draw_border(loc corner);

    /** state variables **/
    struct {
        int x_max;
        int y_max;
    } dims;
};

/*********************************************************************************************************************/
/* run_game
/*********************************************************************************************************************/

/**
 * Runs a game_i.
 */
void run_game(game_i &game);

#endif //GAME_H
