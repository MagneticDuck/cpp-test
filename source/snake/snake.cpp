#include "snake.h"
#include "snake/engine/options.h"

void snakey_game::anim_tick() {
    title.tick();
}

void snakey_game::tick(double delta) {
    if (!game.playing)
        game.start(game_opts.init_pos, game_opts.init_dir);

    if (anim_ticker.tick(delta)) anim_tick();
    if (game_ticker.tick(delta)) game.tick();
}

void snakey_game::handle(int key) {
    if (key == game_opts.quit_key) concluded = true;
    if (boost::optional<dir> new_dir = key_to_dir(key))
        game.handle(*new_dir);
}

void snakey_game::render(frame_i &frame) {
    const static loc border_size =
            rndr_opts.game_to_screen(game_opts.board_dims);

    clear();
    frame.draw_border(border_size);

    using std::to_string;
    title.text = to_string(game.score);
    frame.print(loc(6, 0), title.print());

    game.render(frame);
}

