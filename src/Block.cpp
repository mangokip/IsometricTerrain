//
// Created by bryce-klein on 3/13/25.
//

#include "Block.h"

Block::Block(const sf::Vector2f& center, int row, const sf::Vector2f& size, float height) : center(center), originalPosition(center),gridRow(row), size(size), height(height) {
    top.setPointCount(4);
    left.setPointCount(4);
    right.setPointCount(4);

    updateShapes();

    top.setFillColor(sf::Color::White);
    left.setFillColor(sf::Color(100, 100, 100));
    right.setFillColor(sf::Color(150, 150, 150));
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