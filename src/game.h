#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

/**
 * An interface for an interactive game.
 */
class game_i {
public:
    virtual void tick(double delta) {}
    virtual void render(double delta) {}
    virtual void handle(int key) {}
    virtual bool conclude() {return false;}

    template<typename T>
    static const char *show(const T);
    template<typename T>
    static void print(int x, int y, T);
};

/**
 * Runs a game_i.
 */
void run_game(game_i &game);

#endif //SNAKE_GAME_H

