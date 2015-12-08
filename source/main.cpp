#include "snake/snake.h"
#include "snake/control/control_ncurses.h"

int main() {
    snakey_game game{};
    run_game_ncurses(game);

    return 0;
}