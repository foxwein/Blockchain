#include <Block.h>
#include <json/json.h>

int main()
{
    std::random_device r;
    std::default_random_engine eng(r());

    std::vector<Transaction> trs;
    for(int i = 0; i < 250000; i++)
        trs.emplace_back(GenerateKey(), GenerateKey(), std::uniform_real_distribution<double>(0, 256)(eng), GenerateKey());

    std::vector<Block> blocks;
    for(int i = 0; i < 500; i++)
    {
        blocks.emplace_back(i, 1, (i == 0 ? "" : blocks[i - 1].GetHash()));
        for(int j = 0; j < 500; j++)
            blocks[i].AddTransaction(trs[j + (i * 500)]);
        blocks[i].CalculateNonce();
        blocks[i].SaveToFile();
    }
}
