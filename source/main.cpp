#include "snake/snake.h"
#include "snake/control/control_ncurses.h"
#include "snake/control/control_sfml.h"
#include <functional>

int main(int argc, char *argv[]) {
    snakey_game game{};

    std::function<bool(std::string)> arg_is =
            [argv](std::string name) {
                return ((std::string) argv[1]) == name;
            };

    switch (argc) {
        case 2: {
            if (arg_is("upupdowndownleftrightleftrightababenter"))
                std::cout << "nope";
            else if (arg_is("sfml"))
                run_game_sdl(game);
            else if (arg_is("ncurses"))
                run_game_ncurses(game);
            else
                std::cout << "Options are 'ncurses' and 'sdl'";
            break;
        }
        case 1: run_game_ncurses(game);
            break;
        default: std::cout << "Pass one argument specifying the backend.";
    }

    return 0;
}