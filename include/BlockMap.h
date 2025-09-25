//
// Created by bryce-klein on 3/14/25.
//
#ifndef BLOCKMAP_H
#define BLOCKMAP_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Block.h"
#include "FastNoiseLite.h"

class BlockMap {
public:
    BlockMap(int width, int height);

    void generate();
    void cacheLayers();      // builds per-sum textures from buckets (fast)
    void animateWater();
    void draw(sf::RenderWindow &window);

private:
    // map size
    int width, height;

    // height & noise caches
    std::vector<std::vector<int>>   heightMap;
    std::vector<std::vector<float>> noiseGrid;   // cache noise so we don’t call GetNoise twice

    // geometry
    std::vector<Block> staticBlocks;  // everything except top-of-water blocks
    std::vector<Block> waterBlocks;   // only top-of-water to animate

    // ---- FAST CACHING ----
    // one bucket per (x+y+z) "sum layer", filled once in generate()
    std::vector<std::vector<const Block*>> staticBuckets;
    int maxSumCached = -1;

    // render textures for each sum layer; nullptr = empty layer
    std::vector<std::unique_ptr<sf::RenderTexture>> layerTextures;
    bool layersCached = false;

    // noise + waves
    FastNoiseLite noise;
    std::vector<std::vector<float>> waveOffsets; // random phase per (x,y)
    std::vector<float> waveTable;                // optional lookup (kept for convenience)
    float timeElapsed = 0.f;

    // helpers
    sf::Vector2f toIsometric(int x, int y, int z, float waveOffset = 0.f);
    std::pair<sf::Color, sf::Color> getBlockColor(float noiseValue);

    // tuning constants
    static const int TILE_WIDTH  = 8;
    static const int TILE_HEIGHT = 4;
    static const int MAX_HEIGHT  = 100;

    static constexpr float WINDOW_WIDTH  = 1900.f;
    static constexpr float WINDOW_HEIGHT = 1080.f;

    // biome thresholds (on raw noise in [-1,1])
    static constexpr float WATER_LEVEL    = -0.2f;
    static constexpr float SAND_LEVEL     =  0.0f;
    static constexpr float GRASS_LEVEL    =  0.5f;
    static constexpr float ROCK_LEVEL     =  0.7f;
    static constexpr float MOUNTAIN_LEVEL =  0.75f;
};

#endif // BLOCKMAP_H
