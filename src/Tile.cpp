//
// Created by bryce-klein on 3/13/25.
//

#include "Tile.h"
Tile::Tile(const sf::Vector2f& position, const sf::Vector2f& size, int row, const sf::Color& color) : originalPosition(position), gridRow(row) {
    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(position.x, position.y - size.y / 2));
    shape.setPoint(1, sf::Vector2f(position.x + size.x / 2, position.y));
    shape.setPoint(2, sf::Vector2f(position.x, position.y + size.y / 2));
    shape.setPoint(3, sf::Vector2f(position.x - size.x / 2, position.y));
    shape.setFillColor(color);
}

void Tile::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}

void Tile::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
}

sf::Vector2f Tile::getOriginalPosition() const {
    return originalPosition;
}

int Tile::getRow() const {
    return gridRow;
}

void Tile::move(const sf::Vector2f& offset) {
    shape.move(offset);
}

void Tile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}