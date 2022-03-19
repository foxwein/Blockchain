#pragma once
#include <random>
#include <iostream>
#include <sstream>

std::string GenerateKey()
{
    std::random_device r;
    std::default_random_engine eng(r());
    std::stringstream stream;
    for(int i = 0; i < 64; i++)
        stream << std::hex << std::uniform_int_distribution<int>(0, 16)(eng);
    return stream.str();
}
