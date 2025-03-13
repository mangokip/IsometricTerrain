//
// Created by bryce-klein on 3/13/25.
//

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Tile {
 public:
     Tile(const sf::Vector2f& position, const sf::Vector2f& size, int row, const sf::Color& color = sf::Color::Green);
     void setColor(const sf::Color& color);
     void setPosition(const sf::Vector2f& position);
     void move(const sf::Vector2f& offset);
     void draw(sf::RenderWindow& window) const;
     sf::Vector2f getOriginalPosition() const;
     int getRow() const;


 private:
     sf::ConvexShape shape;
     sf::Vector2f originalPosition;
     int gridRow;
};



#endif //TILE_H
