#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random
{
private:
    std::mt19937 gen; // Mersenne Twister random number generator
public:
    Random() : gen(std::random_device()()) {} // initialize with random seed

    // Returns a random integer between lower and upper (inclusive)
    int getIntInRange(int lower, int upper) {
        return std::uniform_int_distribution<>(lower, upper)(gen);
    }

    // Rolls a probability check; returns true if the roll is within the success percentage
    bool rollPercentage(int successPercentage) {
        return getIntInRange(1, 100) <= successPercentage;
    }
};

#endif
