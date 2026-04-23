#pragma once

#include <random>

class engineRandom
{
public:
    engineRandom() = default;
    ~engineRandom() = default;

    static int getRandomNumber(int min, int max);
};