#include "snake.h"

void snakey_game::anim_tick() {
    title.tick();
}

void snakey_game::tick(double delta) {
    if (menu_state.playing && !menu_state.inited) {
        menu_state.inited = true;
        advice_ticker.reset();
        advice = "welcome to SNAKE SIMULATOR";
        game.init(game_opts::init_pos, game_opts::init_dir);
    }

    if (anim_ticker.tick(delta)) anim_tick();
    if (game_ticker.tick(delta)) game.tick();
    if (advice_ticker.tick(delta)) advice = rndr_opts::print_advice();

    if (menu_state.playing && game.failure) {
        menu_state.playing = false;
        menu_state.ended = true;
        menu_state.inited = false;
    }
}

void snakey_game::handle(int key) {
    if (key == game_opts::quit_key) concluded = true;

    boost::optional<dir> input = game_opts::key_to_dir(key);

    if (menu_state.playing) {
        if (input) game.handle(*input);
    } else if (key == game_opts::continue_key) {
        if (menu_state.ended) {
            menu_state.ended = false;
        } else {
            menu_state.playing = true;
        }
    }
}

void snakey_game::render(frame_i &frame) {
    const static loc border_size =
            rndr_opts::game_to_screen(game_opts::board_dims);

    clear();
    frame.draw_border(border_size);

    if (menu_state.playing) {
        using std::to_string;
        title.text = advice;
        frame.print(loc(rndr_opts::advice_offset, 0), title.print());
        frame.print(loc(rndr_opts::score_offset, border_size.y + 1),
                    rndr_opts::print_score(game.score));

        game.render(frame);
    } else {
        using std::string;
        if (menu_state.ended) {
            frame.print(loc(10, 14), (string) "you screwed up with " + rndr_opts::print_score(game.score));
            frame.print(loc(10, 16), game_opts::continue_message);
        } else {
            frame.print(loc(10, 14), (string) "SNAKE SIMULATOR 2015");
            frame.print(loc(10, 16), game_opts::continue_message);
        }
    }
}

