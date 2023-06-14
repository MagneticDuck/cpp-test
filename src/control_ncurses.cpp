#include <thread>
#include "control.h"
#include "control_ncurses.h"

/**********************************************************************************************************************/
/* frame_ncurses
/**********************************************************************************************************************/

class frame_ncurses : public frame_i {
private:
    void update_dims();
public:
    frame_ncurses();

    void print_c(loc a_loc, char *) override;
    void draw_border(loc corner) override;

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

void frame_ncurses::print_c(loc a_loc, char *t) {
    move(a_loc.y, a_loc.x);
    printw("%s", t);
}

void frame_ncurses::draw_border(loc corner) {
    int i;
    const int x = corner.x + 1;
    const int y = corner.y + 1;
    for (i = 1; i < x; ++i) {
        move(0, i), printw("=");
        move(y, i), printw("=");
    }
    for (i = 1; i < y; ++i) {
        move(i, 0), printw("|");
        move(i, x), printw("|");
    }
}

void frame_ncurses::tick() {
    update_dims();
}

/**********************************************************************************************************************/
/* run_game_ncurses
/**********************************************************************************************************************/

static const int delay = 10; // in milliseconds

void run_game_loop(frame_ncurses &frame, game_i &game) {
    // TODO: use timers to make the game loop more precise

    int key;
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        frame.tick();
        game.tick(((double) delay) / 1000);
        game.render(frame);

        if (game.concluded) break;

        do {
            key = getch();
            game.handle(key);
        } while (key != -1);
    }
}

void run_game_ncurses(game_i &game) {
    /** initialisation **/
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    frame_ncurses frame;

    /** game loop **/
    run_game_loop(frame, game);

    /** destruction **/
    endwin();
}

