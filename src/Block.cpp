//
// Created by bryce-klein on 3/13/25.
//

#include "Block.h"
#include <random>
#include <algorithm>

Block::Block(const sf::Vector2f& center, int row, const sf::Vector2f& size, float height, int blockType) : center(center), originalPosition(center),gridRow(row), size(size), height(height), blockType(blockType) {
    top.setPointCount(4);
    left.setPointCount(4);
    right.setPointCount(4);

    sf::Color randomTop = generateRandomColor(blockType);
    top.setFillColor(randomTop);

    sf::Color darkSide(
        std::max(0, randomTop.r - 20),
        std::max(0, randomTop.g - 20),
        std::max(0, randomTop.b - 20)
    );
    left.setFillColor(darkSide);
    right.setFillColor(darkSide);
    updateShapes();
}

void Block::updateShapes() {
    sf::Vector2f topLeft   = { center.x - size.x / 2, center.y };
    sf::Vector2f topRight  = { center.x + size.x / 2, center.y };
    sf::Vector2f topTop    = { center.x, center.y - size.y / 2 };
    sf::Vector2f topBottom = { center.x, center.y + size.y / 2 };

    top.setPoint(0, topTop);
    top.setPoint(1, topRight);
    top.setPoint(2, topBottom);
    top.setPoint(3, topLeft);

    left.setPoint(0, topLeft);
    left.setPoint(1, topBottom);
    left.setPoint(2, { topBottom.x, topBottom.y + height });
    left.setPoint(3, { topLeft.x,   topLeft.y   + height });

    right.setPoint(0, topRight);
    right.setPoint(1, topBottom);
    right.setPoint(2, { topBottom.x, topBottom.y + height });
    right.setPoint(3, { topRight.x,  topRight.y  + height });
}

sf::Color Block::generateRandomColor(int blockType) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distR, distG, distB;

    switch(blockType) {
        case 0: // grass
            distR = std::uniform_int_distribution<int>(30,  60);
            distG = std::uniform_int_distribution<int>(150, 200);
            distB = std::uniform_int_distribution<int>(30,  60);
            break;
        case 1: // water
            distR = std::uniform_int_distribution<int>(0,   50);
            distG = std::uniform_int_distribution<int>(0,   100);
            distB = std::uniform_int_distribution<int>(150, 255);
            break;
        case 2: // snow
            distR = std::uniform_int_distribution<int>(220, 255);
            distG = std::uniform_int_distribution<int>(220, 255);
            distB = std::uniform_int_distribution<int>(220, 255);
        break;
        case 3: // sand/dirt
            distR = std::uniform_int_distribution<int>(150, 200);
            distG = std::uniform_int_distribution<int>(120, 170);
            distB = std::uniform_int_distribution<int>(70,  110);
        break;
        default:
            distR = std::uniform_int_distribution<int>(0, 255);
            distG = std::uniform_int_distribution<int>(0, 255);
            distB = std::uniform_int_distribution<int>(0, 255);
            break;
    }

    int r = distR(rng);
    int g = distG(rng);
    int b = distB(rng);
    return sf::Color(r, g, b);
}

void Block::setTopColor(const sf::Color& color) {
    top.setFillColor(color);
}

void Block::setLeftColor(const sf::Color& color) {
    left.setFillColor(color);
}

void Block::setRightColor(const sf::Color& color) {
    right.setFillColor(color);
}

void Block::draw(sf::RenderWindow& window) const {
    window.draw(left);
    window.draw(right);
    window.draw(top);
}

int Block::getRow() const {
    return gridRow;
}

void Block::setPosition(const sf::Vector2f& position) {
    center = position;
    updateShapes();
}

sf::Vector2f Block::getOriginalPosition() const {
    return originalPosition;
}