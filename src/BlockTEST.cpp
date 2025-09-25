//
// Created by bryce-klein on 3/13/25.
//

#include <algorithm>
#include <random>
#include "Block.h"
/*
Block::Block(const sf::Vector2f &center, int row, const sf::Vector2f &size, float extrusion, int blockType) :
    center(center), originalPosition(center), gridRow(row), size(size), extrusion(extrusion), blockType(blockType) {
    top.setPointCount(4);
    left.setPointCount(4);
    right.setPointCount(4);

    updateShapes();
    applyColor(blockType);
}

void Block::updateShapes() {

    sf::Vector2f topLeft = {center.x - size.x / 2.f, center.y};
    sf::Vector2f topRight = {center.x + size.x / 2.f, center.y};
    sf::Vector2f topTop = {center.x, center.y - size.y / 2.f};
    sf::Vector2f topBottom = {center.x, center.y + size.y / 2.f};


    top.setPoint(0, topTop);
    top.setPoint(1, topRight);
    top.setPoint(2, topBottom);
    top.setPoint(3, topLeft);


    left.setPoint(0, sf::Vector2f(topLeft.x, topLeft.y));
    left.setPoint(1, sf::Vector2f(topBottom.x, topBottom.y));
    left.setPoint(2, sf::Vector2f(topBottom.x, topBottom.y + size.y / 2.f));
    left.setPoint(3, sf::Vector2f(topLeft.x, topLeft.y + size.y / 2.f));


    right.setPoint(0, sf::Vector2f(topRight.x, topRight.y));
    right.setPoint(1, sf::Vector2f(topBottom.x, topBottom.y));
    right.setPoint(2, sf::Vector2f(topBottom.x, topBottom.y + size.y / 2.f));
    right.setPoint(3, sf::Vector2f(topRight.x, topRight.y + size.y / 2.f));

    depthKey = center.y + extrusion;
}

void Block::applyColor(int blockType) {
    sf::Color topColor;
    sf::Color sideColor;

    switch (blockType) {
        case 0: // grass
            topColor = sf::Color(34, 139, 34); // green
            sideColor = sf::Color(139, 69, 19); // brown
            break;
        case 1: // water
            topColor = sf::Color(0, 0, 255); // bright blue
            sideColor = sf::Color(0, 0, 139); // darker blue
            break;
        case 2: // rock
            topColor = sf::Color(220, 220, 220); // light gray
            sideColor = sf::Color(160, 160, 160); // darker gray
            break;
        case 3: // sand
            topColor = sf::Color(194, 178, 128); // sand
            sideColor = sf::Color(139, 115, 85); // darker brown
            break;
        default:
            topColor = sf::Color(128, 128, 128);
            sideColor = sf::Color(80, 80, 80);
            break;
    }

    top.setFillColor(topColor);
    left.setFillColor(sideColor);
    right.setFillColor(sideColor);
}

void Block::draw(sf::RenderWindow &window) const {
    window.draw(right);
    window.draw(left);
    window.draw(top);
}

sf::Color Block::generateRandomColor(int blockType) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distR, distG, distB;

    switch (blockType) {
        case 0: // grass
            distR = std::uniform_int_distribution<int>(30, 60);
            distG = std::uniform_int_distribution<int>(150, 200);
            distB = std::uniform_int_distribution<int>(30, 60);
            break;
        case 1: // water
            distR = std::uniform_int_distribution<int>(0, 50);
            distG = std::uniform_int_distribution<int>(0, 100);
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
            distB = std::uniform_int_distribution<int>(70, 110);
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

void Block::setTopColor(const sf::Color &color) { top.setFillColor(color); }

void Block::setLeftColor(const sf::Color &color) { left.setFillColor(color); }

void Block::setRightColor(const sf::Color &color) { right.setFillColor(color); }

int Block::getRow() const { return gridRow; }

void Block::setPosition(const sf::Vector2f &position) {
    center = position;
    updateShapes();
}

sf::Vector2f Block::getOriginalPosition() const { return originalPosition; }

sf::Vector2f Block::getCenter() const { return center; }

float Block::getDepthKey() const { return depthKey; }
*/