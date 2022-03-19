#include <Key.h>
#include <RSA.h>
#include <Block.h>
#include <json/json.h>

int main()
{
    Json::Value root;
    root["block"]["name"] = "hello world";
    root["block"]["number"] = 123;

    std::cout << root << std::endl;
    
    std::cout << GetRandomPrime(UINT32_MAX) << std::endl;
}
