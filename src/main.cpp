#include <Key.h>
#include <RSA.h>
#include <simdjson.h>

int main()
{
    simdjson::ondemand::parser parser;
    simdjson::padded_string json = simdjson::padded_string::load("twitter.json");
    simdjson::ondemand::document tweets = parser.iterate(json);
    std::cout << uint64_t(tweets["search_metadata"]["count"]) << " results." << std::endl;
    std::cout << GetRandomPrime(UINT32_MAX) << std::endl;
}
