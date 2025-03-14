//
// Created by bryce-klein on 3/14/25.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>


class Block {
public:
    Block(const sf::Vector2f &position, int z, sf::Color topColor, sf::Color sideColor, int gx, int gy);
    void draw(sf::RenderTarget &target) const;
    void setPosition(const sf::Vector2f &pos);

    sf::Vector2f getPosition() const { return position; }
    int getZ() const { return z; }
    int getGridX() const { return gridX; }
    int getGridY() const { return gridY; }
    sf::Color getTopColor() const { return top.getFillColor(); }

private:
    sf::ConvexShape top, left, right;
    sf::Vector2f position;
    int z; // stack index
    int gridX, gridY; // grid coords

    void updateShapes();
};

#endif // BLOCK_H
