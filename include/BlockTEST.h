//
// Created by bryce-klein on 3/13/25.
//

#ifndef BLOCKTEST_H
#define BLOCKTEST_H

#include <SFML/Graphics.hpp>
#include <random>
class Block {
 public:
     Block(const sf::Vector2f& center, int row, const sf::Vector2f& size, float height, int blockType);

     void setTopColor(const sf::Color& color);
     void setLeftColor(const sf::Color& color);
     void setRightColor(const sf::Color& color);
     void setPosition(const sf::Vector2f& position);
     int getRow() const;
     sf::Vector2f getOriginalPosition() const;
     void draw(sf::RenderWindow& window) const;
     sf::Vector2f getCenter() const;
     void applyColors(int blockType);
     float getDepthKey() const;

 private:
     sf::ConvexShape top;
     sf::ConvexShape left;
     sf::ConvexShape right;
     sf::Vector2f originalPosition;
     sf::Vector2f center;
     sf::Vector2f size;
     int gridRow;
     int blockType;
     float extrusion;
     sf::Color generateRandomColor(int blockType);
     void updateShapes();
     float depthKey;
     void applyColor(int blockType);

};



#endif //BLOCK_H
