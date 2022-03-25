#pragma once

#include "uint256_t.h"
#include <string>
class Encryption {
private:
	uint256_t private_key;
	uint256_t public_key ;
public:
	uint256_t get_private_key();
	void set_private_key(uint256_t private_key);
	uint256_t get_public_key();
	uint256_t sign_document(uint256_t private_key, std::string text);
	bool verify(uint256_t public_key, uint256_t signature, std::string text);

};