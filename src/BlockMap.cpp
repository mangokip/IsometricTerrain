//
// Created by bryce-klein on 3/14/25.
//

#include "BlockMap.h"
#include <algorithm>
#include <cmath>
#include <memory> // for std::make_unique

BlockMap::BlockMap(int width, int height) : width(width), height(height) {
    heightMap.resize(width, std::vector<int>(height));
    waveOffsets.resize(width, std::vector<float>(height));
    waveTable.resize(360);

    std::srand((unsigned) std::time(nullptr));
    int randomSeed = std::rand() % 100000;
    this->noise.SetSeed(randomSeed);
    this->noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    this->noise.SetFrequency(0.05f);

    for (int i = 0; i < 360; i++) {
        waveTable[i] = std::sin(i * 3.14159f / 180.f) * 2.f;
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            waveOffsets[x][y] = (std::rand() % 100) / 100.f * 6.28f;
        }
    }

    generate();
}

void BlockMap::generate() {
    staticBlocks.clear();
    waterBlocks.clear();

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            float nVal = this->noise.GetNoise((float) x, (float) y);
            float norm = (nVal + 1.f) / 2.f;
            norm = std::pow(norm, 4.f) *
                   1.2f; // increase value y in pow(x,y) to increase low terrain / increase sharp peaks
            heightMap[x][y] = std::max(1, (int) (norm * MAX_HEIGHT));
        }
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            float noiseValue = this->noise.GetNoise((float) x, (float) y);
            auto colors = getBlockColor(noiseValue);

            for (int z = 0; z <= heightMap[x][y]; z++) {
                sf::Vector2f isoPos = toIsometric(x, y, z, 0.f);
                if (noiseValue < WATER_LEVEL && z == heightMap[x][y]) {
                    waterBlocks.emplace_back(isoPos, z, colors.first, colors.second, x, y);
                } else {
                    staticBlocks.emplace_back(isoPos, z, colors.first, colors.second, x, y);
                }
            }
        }
    }
}

void BlockMap::cacheLayers() {
    int maxSum = (width - 1) + (height - 1) + MAX_HEIGHT;
    layerTextures.resize(maxSum + 1);

    for (int sum = 0; sum <= maxSum; sum++) {
        layerTextures[sum] = std::make_unique<sf::RenderTexture>();
        layerTextures[sum]->create((unsigned) WINDOW_WIDTH, (unsigned) WINDOW_HEIGHT);
        layerTextures[sum]->clear(sf::Color::Transparent);

        for (auto &block: staticBlocks) {
            int s = block.getGridX() + block.getGridY() + block.getZ();
            if (s == sum) {
                block.draw(*layerTextures[sum]);
            }
        }

        layerTextures[sum]->display();
    }
    layersCached = true;
}

void BlockMap::animateWater() { timeElapsed += 0.2f; }

void BlockMap::draw(sf::RenderWindow &window) {
    if (!layersCached) {
        cacheLayers();
    }

    int maxSum = (width - 1) + (height - 1) + MAX_HEIGHT;
    for (int sum = 0; sum <= maxSum; sum++) {
        sf::Sprite layerSprite(layerTextures[sum]->getTexture());
        window.draw(layerSprite);

        for (auto &block: waterBlocks) {
            int s = block.getGridX() + block.getGridY() + block.getZ();
            if (s != sum)
                continue;

            float rawOffset = std::sin(timeElapsed * 2.f + waveOffsets[block.getGridX()][block.getGridY()]) * 1.5f;
            float waveOffset = std::clamp(rawOffset, -1.f, 0.f);

            sf::Vector2f newPos = toIsometric(block.getGridX(), block.getGridY(), block.getZ(), waveOffset);
            block.setPosition(newPos);
            block.draw(window);
        }
    }
}

sf::Vector2f BlockMap::toIsometric(int x, int y, int z, float waveOffset) {
    float offsetX = WINDOW_WIDTH / 2.f - (width * TILE_WIDTH / 4.f);
    float offsetY = WINDOW_HEIGHT / 2.f - (width * TILE_HEIGHT / 2.f);
    return sf::Vector2f((x - y) * TILE_WIDTH / 2.f + offsetX,
                        (x + y) * TILE_HEIGHT / 2.f - z * TILE_HEIGHT / 2.f + waveOffset + offsetY);
}

std::pair<sf::Color, sf::Color> BlockMap::getBlockColor(float noiseValue) {
    if (noiseValue < WATER_LEVEL)
        return {sf::Color(0, 100, 200), sf::Color(0, 0, 150)}; // water
    if (noiseValue < SAND_LEVEL)
        return {sf::Color(237, 201, 175), sf::Color(194, 178, 128)}; // sand
    if (noiseValue < GRASS_LEVEL)
        return {sf::Color(34, 139, 34), sf::Color(139, 69, 19)}; // grass
    if (noiseValue < ROCK_LEVEL)
        return {sf::Color(120, 120, 120), sf::Color(80, 80, 80)}; // rock
    return {sf::Color(240, 240, 240), sf::Color(200, 200, 200)}; // snow
}
