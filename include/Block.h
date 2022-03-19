#pragma once
#include "Key.h"
#include "RSA.h"

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
    Block(int index);

    void SaveToFile();

private:
    Json::Value root;

    int index, nonse, version;

    std::string hash, prev_hash;

    std::vector<Transaction> transactions;
};
