#include <Encryption.h>

void Encryption::SetPrivateKey(uint256_t private_key)
{
	this->private_key = private_key;
}

bool Encryption::Verify(uint256_t public_key, uint256_t signature, std::string text)
{
	return true;
}

uint256_t Encryption::GetPublicKey()
{
	return public_key;
}

uint256_t Encryption::GetPrivateKey()
{
	return private_key;
}

uint256_t Encryption::GenerateSignature(uint256_t private_key, std::string text)
{
	return private_key;
}
