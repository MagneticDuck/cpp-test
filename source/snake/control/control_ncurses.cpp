//
// Created by magneticduck on 12/8/15.
//

#include "control.h"
#include "control_ncurses.h"

class frame_ncurses : public frame_i {
private:
    void update_dims();
public:
    frame_ncurses();

    void print(loc a_loc, char *);
    void draw_border(loc corner);

    void tick();
};

void frame_ncurses::update_dims() {
    int height, width;
    getmaxyx(stdscr, height, width);
    dims.y_max = height - 1;
    dims.x_max = width - 1;
}

frame_ncurses::frame_ncurses() {
    update_dims();
}

void frame_ncurses::print(loc a_loc, char *t) {
    move(a_loc.y, a_loc.x);
    printw(t);
}

void frame_ncurses::draw_border(loc corner) {
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

void frame_ncurses::tick() {
    update_dims();
}

/** run_game_ncurses **/

static const __useconds_t delay = 5000;

void run_game_loop(frame_ncurses &frame, game_i &game) {
    int key;
    double delta;
    clock_t now_stamp, then_stamp;

    now_stamp = clock();
    while (1) {
        then_stamp = now_stamp;
        usleep(delay);
        now_stamp = clock();
        delta = ((double) now_stamp - then_stamp) / 10000;

        frame.tick();
        game.tick(delta);
        game.render(frame);

        if (game.conclude()) break;

        do {
            key = getch();
            game.handle(key);
        } while (key != -1);
    }
}

void run_game_ncurses(game_i &game) {
    /** initialisation code **/
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    frame_ncurses frame;

    /** game loop **/
    run_game_loop(frame, game);

    /** destruction code **/
    endwin();
}

