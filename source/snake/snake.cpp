#include <cmath>
#include "snake.h"

void snakey_game::game_tick() {
    lifetime++;

    head += loc{movement};
    head.clamp(20, 20);
}

void snakey_game::anim_tick() {
    title.tick();
}

void snakey_game::tick(double delta) {
    tick_cooldown += delta;
    if (tick_cooldown > tick_dur) {
        tick_cooldown = 0;
        game_tick();
    }

    anim_cooldown += delta;
    if (anim_cooldown > anim_dur) {
        anim_tick();
        anim_cooldown = 0;
    }
}

bool snakey_game::conclude() {
    return concluded;
}

void snakey_game::handle(int key) {
    if (key == quit_key) concluded = true;
    if (boost::optional<dir> new_dir = key_to_dir(key)) {
        this->movement = *new_dir;
    }
}

loc snakey_game::game_to_screen(loc a_loc) {
    return loc(2 * a_loc.x + 1, a_loc.y + 1);
}

void snakey_game::render(frame_i &frame) {
    clear();
    frame.draw_border(loc(42, 22));

    frame.print(game_to_screen(head), show_dir(movement));
    for (loc tail_loc : tail) {
        frame.print(game_to_screen(tail_loc), (char *) "x");
    }

    using std::to_string;
    title.text = to_string(lifetime) + " iterations and counting! ";
    frame.print(loc(6, 0), title.print());
}

