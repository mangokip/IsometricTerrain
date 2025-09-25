//
// Created by bryce-klein on 3/14/25.
//
#include "Block.h"

// ----- constructor -----
Block::Block(const sf::Vector2f &position, int z, sf::Color topColor, sf::Color sideColor, int gx, int gy) :
    position(position), z(z), gridX(gx), gridY(gy) {
    top.setPointCount(4);
    left.setPointCount(4);
    right.setPointCount(4);

    updateShapes();

    top.setFillColor(topColor);
    left.setFillColor(sideColor);
    right.setFillColor(sideColor);

    top.setPosition(position);
    left.setPosition(position);
    right.setPosition(position);
}

void Block::updateShapes() {
    const int TILE_WIDTH = 8;
    const int TILE_HEIGHT = 4;

    top.setPoint(0, sf::Vector2f(0, TILE_HEIGHT / 2.f));
    top.setPoint(1, sf::Vector2f(TILE_WIDTH / 2.f, 0));
    top.setPoint(2, sf::Vector2f(TILE_WIDTH, TILE_HEIGHT / 2.f));
    top.setPoint(3, sf::Vector2f(TILE_WIDTH / 2.f, TILE_HEIGHT));

    left.setPoint(0, sf::Vector2f(0, TILE_HEIGHT / 2.f));
    left.setPoint(1, sf::Vector2f(TILE_WIDTH / 2.f, TILE_HEIGHT));
    left.setPoint(2, sf::Vector2f(TILE_WIDTH / 2.f, TILE_HEIGHT * 1.5f));
    left.setPoint(3, sf::Vector2f(0, TILE_HEIGHT));

    right.setPoint(0, sf::Vector2f(TILE_WIDTH / 2.f, TILE_HEIGHT));
    right.setPoint(1, sf::Vector2f(TILE_WIDTH, TILE_HEIGHT / 2.f));
    right.setPoint(2, sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
    right.setPoint(3, sf::Vector2f(TILE_WIDTH / 2.f, TILE_HEIGHT * 1.5f));
}

void Block::setPosition(const sf::Vector2f &pos) {
    position = pos;
    top.setPosition(position);
    left.setPosition(position);
    right.setPosition(position);
}

void Block::draw(sf::RenderTarget &target) const {
    target.draw(left);
    target.draw(right);
    target.draw(top);
}
