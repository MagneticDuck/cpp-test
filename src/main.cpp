#include "snake.h"
#include "control_ncurses.h"
#include <functional>

int main(int argc, char *argv[]) {
    snakey_game game{};
    run_game_ncurses(game);
    return 0;
}