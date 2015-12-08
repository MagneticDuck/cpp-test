#include <cmath>
#include "snake.h"

std::string tickertape::print() {
    std::string result = "";
    const int loop_len_v = loop_length;
    for (int i = 0; i < disp_width; i++) {
        result += at_index((iter + i) % loop_len_v);
    }
    return result;
}

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
    if (tick_cooldown > tick_dur) game_tick();
    tick_cooldown = std::fmod(tick_cooldown, tick_dur);

    anim_cooldown += delta;
    if (anim_cooldown > anim_dur) anim_tick();
    anim_cooldown = std::fmod(anim_cooldown, anim_dur);
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

void snakey_game::render() {
    clear();
    draw_border(loc(42, 22));

    print(game_to_screen(head), show_dir(movement));
    for (loc tail_loc : tail) {
        print(game_to_screen(tail_loc), (char *) "x");
    }

    using std::to_string;
    title.text = to_string(lifetime) + " iterations and counting! ";
    print(loc(6, 0), title.print());
}

