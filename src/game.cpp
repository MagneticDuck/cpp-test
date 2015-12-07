#include "snake.h"
#include <bits/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <string>
#include "game.h"

namespace {
    const __useconds_t delay = 10000;
}

void run_game(game_i &game) {
    /** initialisation code **/
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    /** game loop **/
    int key;
    while (1) {
        key = getch();
        if (key != -1) game.handle(key);
        game.tick(100);
        game.render(100);
        usleep(delay);
        if (game.conclude()) break;
    }

    /** destruction code **/
    endwin();
}

template<typename T>
const char *game_i::show(const T t) {
    return std::to_string(t).c_str();
}

template<typename T>
void game_i::print(int x, int y, T t) {
    move(x, y);
    printw(show(t));
}