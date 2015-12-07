#include "snake.h"

//the entry point of the program.
int main() {
    snake::snakey_game game();
    run_game((game_i *) &game);

    return 0;
}