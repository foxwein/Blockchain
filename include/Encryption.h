#pragma once
#include <uint256_t.h>
#include <string>

class Encryption 
{
public:
	void SetPrivateKey(uint256_t private_key);
	bool Verify(uint256_t public_key, uint256_t signature, std::string text);

	uint256_t GetPublicKey();
	uint256_t GetPrivateKey();
	uint256_t GenerateSignature(uint256_t private_key, std::string text);

private:
	uint256_t private_key;
	uint256_t public_key;
};
