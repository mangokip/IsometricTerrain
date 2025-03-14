//
// Created by bryce-klein on 3/14/25.
//

#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <SFML/Graphics.hpp>
class PerlinNoise {
    public:
    sf::Vector2f randomGradient(int x, int y);
    float gridGradient (int ix, int iy, float x, float y);
    float Interpolate(float x, float y, float z);
    float Perlin(float x, float y);
};

#endif //PERLINNOISE_H
