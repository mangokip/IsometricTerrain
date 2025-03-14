//
// Created by bryce-klein on 3/14/25.
//
#ifndef BLOCKMAP_H
#define BLOCKMAP_H

#include <SFML/Graphics.hpp>
#include <memory> // for std::unique_ptr
#include <vector>
#include "Block.h"
#include "FastNoiseLite.h"


class BlockMap {
public:
    BlockMap(int width, int height);

    void generate();
    void cacheLayers();
    void animateWater();
    void draw(sf::RenderWindow &window);

private:
    int width, height;
    std::vector<std::vector<int>> heightMap;
    std::vector<Block> staticBlocks;
    std::vector<Block> waterBlocks;
    std::vector<std::unique_ptr<sf::RenderTexture>> layerTextures;
    bool layersCached = false;
    FastNoiseLite noise;
    std::vector<std::vector<float>> waveOffsets;
    std::vector<float> waveTable;
    float timeElapsed = 0.f;
    sf::Vector2f toIsometric(int x, int y, int z, float waveOffset = 0.f);
    std::pair<sf::Color, sf::Color> getBlockColor(float noiseValue);

    static const int TILE_WIDTH = 8;
    static const int TILE_HEIGHT = 4;
    static const int MAX_HEIGHT = 100;

    static constexpr float WATER_LEVEL = -0.2f;
    static constexpr float SAND_LEVEL = 0.f;
    static constexpr float GRASS_LEVEL = 0.5f;
    static constexpr float ROCK_LEVEL = 0.7f;
    static constexpr float MOUNTAIN_LEVEL = 0.75f;

    static constexpr float WINDOW_WIDTH = 1900.f;
    static constexpr float WINDOW_HEIGHT = 1080.f;
};

#endif // BLOCKMAP_H
