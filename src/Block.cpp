#include <Block.h>

Block::Block(int index, std::string prev_hash) : index(index), prev_hash(prev_hash) {}

void Block::SaveToFile()
{
    std::ofstream output("block_" + std::to_string(index) + ".json");

    root["hash"] = hash;
    root["block"]["previous_hash"] = prev_hash;
    root["block"]["nonce"] = nonce;
    root["block"]["index"] = index;
    root["block"]["version"] = version;

    for(auto& i : transactions)
    {
        root["transactions"]["from"] = i.from;
        root["transactions"]["to"] = i.to;
        root["transactions"]["amount"] = i.amount;
        root["transactions"]["signature"] = i.signature;
    }
}
