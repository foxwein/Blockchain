#include <Block.h>

Block::Block(int index, int version, std::string prev_hash) : index(index), version(version), prev_hash(prev_hash)
{
    UpdateJSON();
    hash = Sha256(root.toStyledString());
}

void Block::SaveToFile()
{
    std::ofstream output("block_" + std::to_string(index) + ".json");
    UpdateJSON();
    output << root.toStyledString();
}

void Block::AddTransaction(const Transaction& tr)
{
    transactions.push_back(tr);
}

void Block::CalculateNonce()
{
    UpdateJSON();
    std::string str = Sha256(root.toStyledString());
    while(str[0] != '0' || str[1] != '0')
    {
        nonce++;
        UpdateJSON();
        str = Sha256(root.toStyledString());
    }
    hash = str;
}

void Block::UpdateJSON()
{
    root["hash"] = hash;
    root["block"]["previous_hash"] = prev_hash;
    root["block"]["nonce"] = nonce;
    root["block"]["index"] = index;
    root["block"]["version"] = version;

    for(int i = 0; i < transactions.size(); i++)
    {
        root["transactions"][i]["from"] = transactions[i].from;
        root["transactions"][i]["to"] = transactions[i].to;
        root["transactions"][i]["amount"] = transactions[i].amount;
        root["transactions"][i]["signature"] = transactions[i].signature;
    }
}

std::string Block::GetHash()
{
    return hash;
}
