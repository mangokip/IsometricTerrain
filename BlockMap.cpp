//
// Created by bryce-klein on 3/13/25.
//

#include "BlockMap.h"
#include <cmath>

BlockMap::BlockMap(int width, int height, const sf::Vector2f& origin, const sf::Vector2f& blockSize, float blockHeight) : gridWidth(width), gridHeight(height) {
    for(int x = 0; x < gridWidth; ++x) {
        for(int y = 0; y < gridHeight; ++y) {
            float isotopeX = (x - y) * (blockSize.x / 2.f);
            float isotypeY = (x + y) * (blockSize.y / 2.f);
            sf::Vector2f center = origin + sf::Vector2f(isotopeX, isotypeY);
            sf::Color topColor = ((x+y) % 2 == 0) ? sf::Color::Red : sf::Color::Green;
            Block block(center, y, blockSize, blockHeight);
            block.setTopColor(topColor);
            blocks.push_back(block);

        }
    }
}

void BlockMap::sinWave(float time, float amplitude, float frequency, float speed, float rowPhaseOffset) {
    for(Block& block : blocks) {
        sf::Vector2f base = block.getOriginalPosition();
        int row = block.getRow();
        float offsetY = amplitude * std::sin(frequency * base.x + speed * time + rowPhaseOffset * row);
        block.setPosition(sf::Vector2f(base.x, base.y + offsetY));
    }
}

void BlockMap::draw(sf::RenderWindow& window) const {
    for(const Block& block : blocks) {
        block.draw(window);
    }
}