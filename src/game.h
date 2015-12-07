#include <string>

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

/**
 * An interface for an interactive game. Oh hey, this is an interface for an interface.
 */
class game_i {
public:
    /** virtual interactive handles **/
    virtual void tick(double delta) {}
    virtual void render(double delta) {}
    virtual void handle(int key) {}
    virtual bool conclude() {return false;}

    /** static, non-virtual helper functions **/
    template<typename T> static const char *show(const T);
    static const char *show(std::string);
    template<typename T> static void print(int x, int y, T);
    static void print(int x, int y, char *);
};

/**
 * Runs a game_i.
 */
void run_game(game_i &game);

template<typename T>
const char *game_i::show(const T t) {
    return std::to_string(t).c_str();
}

template<typename T>
void game_i::print(int x, int y, T t) {
    move(x, y);
    printw(show(t));
}

#endif //SNAKE_GAME_H

