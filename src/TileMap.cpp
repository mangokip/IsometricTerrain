//
// Created by bryce-klein on 3/13/25.
//

#include "TileMap.h"
#include<cmath>

TileMap::TileMap(int width, int height, const sf::Vector2f& origin, const sf::Vector2f& tileSize) : gridWidth(width), gridHeight(height)  {
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            float isometricX = (x - y) * (tileSize.x / 2.f);
            float isometricY = (x + y) * (tileSize.y / 2.f);
            sf::Vector2f center = origin + sf::Vector2f(isometricX, isometricY);
            sf::Color color =  ((x+y) % 2 == 0) ? sf::Color::Blue : sf::Color::Green;
            Tile tile(center, tileSize, y, color);
            tiles.push_back(tile);
        }
    }
}


void TileMap::sinWave(float time, float amplitude, float frequency, float speed, float rowPhaseOffset) {
    for (Tile& tile : tiles) {
        sf::Vector2f basePos = tile.getOriginalPosition();
        int row = tile.getRow();
        float offsetY = amplitude * std::sin(frequency * basePos.x + speed * time + row * rowPhaseOffset);
        tile.setPosition(sf::Vector2f(basePos.x, basePos.y + offsetY));
    }
}

void TileMap::draw(sf::RenderWindow& window) {
    for(const Tile& tile : tiles) {
        tile.draw(window);
    }
}