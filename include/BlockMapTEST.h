//
// Created by bryce-klein on 3/13/25.
//

#ifndef BLOCKMAPTEST_H
#define BLOCKMAPTEST_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Block.h"

class BlockMap {
 public:
     BlockMap(int width, int height, const sf::Vector2f& origin, const sf::Vector2f& blockSize, float blockHeight, int maxColumn, float noiseScale);
     void sinWave(float time, float amplitude, float frequency, float speed, float rowPhaseOffset);
     void draw(sf::RenderWindow& window) const;
 private:
     std::vector<Block> blocks;
     int gridWidth;
     int gridHeight;
};



#endif //BLOCKMAPTEST_H
