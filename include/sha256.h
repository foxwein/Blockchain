#pragma once
#include <iostream>
#include <openssl/sha.h>

static std::string WTF(std::string input)
{
    std::string result;
    result.resize(64);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&result[i * 2], "%02x", hash[i]);
    result[64] = 0;
    return result;
}
