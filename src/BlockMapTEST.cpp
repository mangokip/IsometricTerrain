#include <cmath>
#include <iostream>
#include <random>
#include "Block.h"
#include "BlockMap.h"
#include "PerlinNoise.h"

BlockMap::BlockMap(int width, int height, const sf::Vector2f &origin, const sf::Vector2f &blockSize,
                   float blockVerticalOffset, int maxColumn, float baseNoiseScale) :
    gridWidth(width), gridHeight(height) {
    PerlinNoise perlin;

    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            float isoX = (x - y) * (blockSize.x / 2.f);
            float isoY = (x + y) * (blockSize.y / 2.f);
            sf::Vector2f basePosition = origin + sf::Vector2f(isoX, isoY);


            float f1 = perlin.Perlin(x * baseNoiseScale, y * baseNoiseScale) * 0.7f;
            float f2 = perlin.Perlin(x * baseNoiseScale * 2, y * baseNoiseScale * 2) * 0.5f;
            float f3 = perlin.Perlin(x * baseNoiseScale * 4, y * baseNoiseScale * 4) * 0.3f;
            float f4 = perlin.Perlin(x * baseNoiseScale * 8, y * baseNoiseScale * 8) * 0.2f;

            float noiseValue = f1 + f2 + f3 + f4;
            noiseValue = noiseValue * 2.5f - 0.5f;

            float normalized = (noiseValue + 1.f) / 2.f;
            normalized = std::clamp(normalized, 0.f, 1.f);

            int columnHeight = std::max(2, static_cast<int>(1 + normalized * (maxColumn - 1)));


            for (int i = 0; i < columnHeight; i++) {
                sf::Vector2f blockCenter = basePosition - sf::Vector2f(0, i * (blockSize.y / 2.f));


                int blockType;

                if (i == 0) {
                    blockType = 3;
                } else if (i == columnHeight - 1) {

                    if (normalized < 0.2f) {
                        blockType = 1; // water
                    } else if (normalized < 0.3f) {
                        blockType = 3; // sand
                    } else if (normalized < 0.7f) {
                        blockType = 0; // grass
                    } else if (normalized < 0.85f) {
                        blockType = 2; // rock/mountain
                    } else {
                        blockType = 2; // snow
                    }
                } else {
                    blockType = 3;
                }


                Block block(blockCenter, y, blockSize, blockVerticalOffset, blockType);
                blocks.push_back(block);
            }
        }
    }
}

void BlockMap::sinWave(float time, float amplitude, float frequency, float speed, float rowPhaseOffset) {
    for (Block &block: blocks) {
        sf::Vector2f base = block.getOriginalPosition();
        int row = block.getRow();
        float offsetY = amplitude * std::sin(frequency * base.x + speed * time + rowPhaseOffset * row);
        block.setPosition(sf::Vector2f(base.x, base.y + offsetY));
    }
}

void BlockMap::draw(sf::RenderWindow &window) const {
    std::vector<Block> sortedBlocks = blocks;
    std::sort(sortedBlocks.begin(), sortedBlocks.end(), [](const Block &a, const Block &b) {
        if (a.getCenter().y != b.getCenter().y) {
            return a.getCenter().y < b.getCenter().y;
        }
        return a.getDepthKey() < b.getDepthKey();
    });


    for (const auto &block: sortedBlocks) {
        block.draw(window);
    }
}
