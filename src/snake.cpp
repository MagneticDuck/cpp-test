#include "snake.h"

namespace snake {
    snakey_game::snakey_game() {
        // stub
    }

    snakey_game::~snakey_game() {
        // stub
    }

    void snakey_game::tick(double) {
        // stub
    }

    bool snakey_game::conclude() {
        return concluded;
    }

    void snakey_game::handle(int key) {
        if (key == quit_key) concluded = true;
        else if (key != this->key) {
            this->key = key;
            key_count++;
        }
    }

    void snakey_game::render(double) {
        clear();
        print(0, 0, key);
        print(0, 1, key_count);
        print(0, 1, "delay_len: " + std::to_string(delay_len));
    }
}

