#include <Block.h>
#include <json/json.h>

int main()
{   
    Block block(0, 1, "");
    Transaction tr;
    tr.from = "dima"; tr.to = "sergey";
    tr.amount = 0.123456; tr.signature = GenerateKey();
    block.AddTransaction(tr);
    block.CalculateNonce();
    block.SaveToFile();
}
