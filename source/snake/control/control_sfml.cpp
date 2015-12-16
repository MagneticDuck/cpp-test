#include <SFML/Graphics.hpp>
#include "control_sfml.h"

void run_game_sdl(game_i &game) {
    sf::RenderWindow window (sf::VideoMode(800, 600), "my window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // draw

        window.display();
    }
}
