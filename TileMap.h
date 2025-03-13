//
// Created by bryce-klein on 3/13/25.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include<SFML/Graphics.hpp>
#include "Tile.h"
#include<vector>

class TileMap {
 public:
     TileMap(int width, int height, const sf::Vector2f& origin, const sf::Vector2f& tileSize);
     void sinWave(float time, float amplitude, float frequency, float speed, float rowPhaseOffset);
     void draw(sf::RenderWindow& window);
 private:
     std::vector<Tile> tiles;
     int gridWidth, gridHeight;
};



#endif //TILEMAP_H
