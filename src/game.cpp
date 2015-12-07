#include "snake.h"
#include <unistd.h>


template<typename T>
const char *game_i::show(const T t) {
    return std::to_string(t).c_str();
}

template<typename T>
void game_i::print(int x, int y, T t) {
    move(x, y);
    printw(show(t));
}

void game_i::print(int x, int y, char *t) {
    move(x, y);
    printw(t);
}

static const __useconds_t delay = 10000;

void run_game(game_i &game) {
    /** initialisation code **/
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    /** game loop **/
    time_t now;
    int key;
    time_t last_stamp, now_stamp, delta;

    last_stamp = time(&now);
    while (1) {
        usleep(delay);
        now_stamp = time(nullptr);
        delta = last_stamp - now_stamp;

        key = getch();
        if (key != -1) game.handle(key);

        game.tick(delta / 10000);
        game.render(delta / 10000);

        if (game.conclude()) break;

        last_stamp = now_stamp;
    }

    /** destruction code **/
    endwin();
}

