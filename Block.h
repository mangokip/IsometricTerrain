//
// Created by bryce-klein on 3/13/25.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block {
 public:
     Block(const sf::Vector2f& center, int row, const sf::Vector2f& size, float height);

     void setTopColor(const sf::Color& color);
     void setLeftColor(const sf::Color& color);
     void setRightColor(const sf::Color& color);
     void setPosition(const sf::Vector2f& position);
     int getRow() const;
     sf::Vector2f getOriginalPosition() const;
     void draw(sf::RenderWindow& window) const;

 private:
     sf::ConvexShape top;
     sf::ConvexShape left;
     sf::ConvexShape right;
     sf::Vector2f originalPosition;
     sf::Vector2f center;
     sf::Vector2f size;
     int gridRow;
     float height;

     void updateShapes();

};



#endif //BLOCK_H
