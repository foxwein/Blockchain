#include <Block.h>
#include <json/json.h>

int main()
{   
    Block block(0, 1, ""), block1(1, 1, block.GetHash());
    Transaction tr, tr1, tr2;
    
    tr.from = "dima"; tr.to = "sergey";
    tr.amount = 0.123456; tr.signature = GenerateKey();

    tr1.from = "dima"; tr1.to = "marcus";
    tr1.amount = 0.1; tr1.signature = GenerateKey();

    tr2.from = "sergey"; tr2.to = "alisa";
    tr2.amount = 0.15; tr2.signature = GenerateKey();

    block.AddTransaction(tr);
    block.AddTransaction(tr1);
    block1.AddTransaction(tr2);

    block.CalculateNonce();
    block.SaveToFile();

    block1.CalculateNonce();
    block1.SaveToFile();
}
