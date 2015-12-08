#include <unistd.h>
#include "game.h"

loc::loc(int col, int row) : x(col), y(row) { }

loc::loc(dir some_dir) {
    switch (some_dir) {
        case dir::Up: {
            y = -1, x = 0;
            break;
        }
        case dir::Down: {
            y = 1, x = 0;
            break;
        }
        case dir::Left: {
            y = 0, x = -1;
            break;
        }
        case dir::Right: {
            y = 0, x = 1;
            break;
        }
    }
}

loc::loc() : x(0), y(0) { }

void loc::operator+=(loc a_loc) {
    this->x += a_loc.x;
    this->y += a_loc.y;
}

loc operator+(loc a, loc b) {
    return loc(a.x + b.x, a.y + b.y);
}

void loc::clamp(int max_x, int max_y) {
    x = std::min(x, max_x);
    y = std::min(y, max_y);

    x = std::max(x, 0);
    y = std::max(y, 0);
}

boost::optional<dir> key_to_dir(int a_key) {
    switch (a_key) {
        case 260: return boost::optional<dir>(dir::Left);
        case 261: return boost::optional<dir>(dir::Right);
        case 259: return boost::optional<dir>(dir::Up);
        case 258: return boost::optional<dir>(dir::Down);
        default: return boost::optional<dir>();
    }
}

std::string show_dir(dir a_dir) {
    switch (a_dir) {
        case dir::Up: return "^";
        case dir::Down: return "v";
        case dir::Left: return "<";
        case dir::Right: return ">";
    }
}

/*********************************************************************************************************************/
/* game_i
/*********************************************************************************************************************/

void game_i::tick(double) { }

void game_i::render() { }

void game_i::handle(int) { }

bool game_i::conclude() { return false; }

void game_i::print(loc a_loc, char *t) {
    move(a_loc.y, a_loc.x);
    printw(t);
}

void game_i::draw_border(loc corner) {
    int i;
    const int x = corner.x;
    const int y = corner.y;
    for (i = 0; i < x; ++i) {
        move(0, i), printw("=");
        move(y, i), printw("=");
    }
    for (i = 0; i < y; ++i) {
        move(i, 0), printw("|");
        move(i, x), printw("|");
    }
}

/*********************************************************************************************************************/
/* run_game
/*********************************************************************************************************************/

static const __useconds_t delay = 5000;

void update_dims(game_i &game) {
    int height, width;
    getmaxyx(stdscr, height, width);
    game.dims.y_max = height - 1;
    game.dims.x_max = width - 1;
}

void run_game_loop(game_i &game) {
    int key;
    double delta;
    clock_t now_stamp, then_stamp;

    now_stamp = clock();
    while (1) {
        then_stamp = now_stamp;
        usleep(delay);
        now_stamp = clock();
        delta = ((double) now_stamp - then_stamp) / 10000;

        update_dims(game);
        game.tick(delta);
        game.render();

        if (game.conclude()) break;

        do {
            key = getch();
            game.handle(key);
        } while (key != -1);
    }
}

void run_game(game_i &game) {
    /** initialisation code **/
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    update_dims(game);

    /** game loop **/
    run_game_loop(game);

    /** destruction code **/
    endwin();
}
