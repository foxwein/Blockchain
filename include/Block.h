#pragma once
#include "Key.h"
#include "RSA.h"
#include "sha256.h"

#include <json/json.h>
#include <fstream>

struct Transaction
{
    Transaction(std::string from, std::string to, double amount, std::string signature) : 
                from(from), to(to), amount(amount), signature(signature) {}

    double amount;
    std::string from, to, signature;
};

class Block
{
public:
    Block(int index, int version, std::string prev_hash);

    void SaveToFile();
    void AddTransaction(const Transaction& tr);
    void CalculateNonce();
    
    std::string GetHash();

private:
    void UpdateJSON();

    Json::Value root;

    int index, nonce = 0, version;

    std::string hash = "", prev_hash;

    std::vector<Transaction> transactions;
};
