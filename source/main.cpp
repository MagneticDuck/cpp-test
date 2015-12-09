#include "snake/snake.h"
#include "snake/control/control_ncurses.h"
#include "snake/control/control_sdl.h"

int main(int argc, char *argv[]) {
    snakey_game game{};

    switch (argc) {
        case 2: {
            if (((std::string) argv[1]) == "sdl") {
                run_game_sdl(game);
            } else if (((std::string) argv[1]) == "ncurses") {
                run_game_ncurses(game);
            } else {
                std::cout << "Options are 'ncurses' and 'sdl'";
            }
            break;
        }
        case 1: run_game_ncurses(game);
            break;
        default: std::cout << "Pass one argument specifying the backend.";
    }

    return 0;
}