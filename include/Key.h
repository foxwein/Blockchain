#include <random>
#include <iostream>
#include <sstream>

std::string GenerateKey()
{
    std::random_device r;
    std::default_random_engine eng(r());
    //uint64_t n = std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(eng);
    std::stringstream stream;
    stream << std::hex
        << std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(eng)
        << std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(eng)
        << std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(eng);
    return stream.str();
}
