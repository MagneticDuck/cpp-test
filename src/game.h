//
// Created by magneticduck on 12/7/15.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

/**
 * An interface for a interactive snakey_game.
 */
class game_i {
public:
    virtual void tick(double delta) = 0;
    virtual bool conclude() = 0;
};

/**
 * Runs a snakey_game.
 */
void run_game(game_i *game);

#endif //SNAKE_GAME_H

