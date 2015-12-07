#include "snake.h"

namespace snake {
    snakey_game::snakey_game() {

    }

    snakey_game::~snakey_game() {

    }

    void snakey_game::tick(double) {

    }

    bool snakey_game::conclude() {
        return concluded;
    }

    void snakey_game::handle(int key) {
        this->key = key;
        if (key == quit_key) concluded = true;
    }

    void snakey_game::render(double) {
        clear();
        print(0, 0, key);
        print(0, 1, key_count);
    }
}

