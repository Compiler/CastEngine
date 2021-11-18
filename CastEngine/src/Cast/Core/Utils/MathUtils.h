#pragma once
#include <random>

inline float random_float(float min, float max) {
    std::uniform_real_distribution<float> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}
