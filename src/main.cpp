//
// Created by bryce-klein on 3/13/25.
//

#include <SFML/Graphics.hpp>
#include "BlockMap.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1900, 1080), "Isometric Tile Sim", sf::Style::Close);
    window.setFramerateLimit(60);

    BlockMap blockMap(100, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        blockMap.animateWater();

        window.clear(sf::Color::Black);
        blockMap.draw(window);
        window.display();
    }

    return 0;
}
