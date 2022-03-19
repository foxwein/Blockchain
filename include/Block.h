#pragma once
#include "Key.h"
#include "RSA.h"
#include "sha256.h"

#include <json/json.h>
#include <fstream>

struct Transaction
{
    double amount;
    std::string from, to, signature;
};

class Block
{
public:
    Block(int index, std::string prev_hash);

    void SaveToFile();
    
    std::string GetHash();

private:
    Json::Value root;

    int index, nonce, version;

    std::string hash, prev_hash;

    std::vector<Transaction> transactions;
};
