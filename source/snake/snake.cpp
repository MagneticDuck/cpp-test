#include "snake.h"

void snakey_game::anim_tick() {
    title.tick();
}

void snakey_game::tick(double delta) {
    if (!menu_state.playing) {
        menu_state.playing = true;
        advice_ticker.reset();
        advice = "welcome to SNAKE SIMULATOR";
        game.init(game_opts::init_pos, game_opts::init_dir);
    }

    if (anim_ticker.tick(delta)) anim_tick();
    if (game_ticker.tick(delta)) game.tick();
    if (advice_ticker.tick(delta)) advice = rndr_opts::print_advice();

    if (game.failure) menu_state.playing = false;
}

void snakey_game::handle(int key) {
    if (key == game_opts::quit_key) concluded = true;
    if (boost::optional<dir> new_dir = game_opts::key_to_dir(key))
        game.handle(*new_dir);
}

void snakey_game::render(frame_i &frame) {
    const static loc border_size =
            rndr_opts::game_to_screen(game_opts::board_dims);

    clear();
    frame.draw_border(border_size);

    using std::to_string;
    title.text = advice;
    frame.print(loc(6, 0), title.print());
    frame.print(loc(6, border_size.y + 1), rndr_opts::print_score(game.score));

    game.render(frame);
}

