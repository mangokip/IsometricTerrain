#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TileMap.h"
#include "Block.h"
#include "BlockMap.h"
#include<cmath>


int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tile Simulation");
    window.setFramerateLimit(60);

    const int gridWidth = 10;
    const int gridHeight = 10;
    const sf::Vector2f blockSize(100.f, 50.f);
    const float blockHeight = 50.f;
    const sf::Vector2f origin(1000.f, 100.f);

    BlockMap block_map(gridWidth, gridHeight, origin, blockSize, blockHeight);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float time = clock.getElapsedTime().asSeconds();
        block_map.sinWave(time, 10.f, 0.05f, 2.f, 0.2f);
        window.clear(sf::Color::Black);
        block_map.draw(window);
        window.display();
    }

    return 0;
}


