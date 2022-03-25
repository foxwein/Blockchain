#include "include/encryption.h"
#include "uint256_t.h"
#include <string>


uint256_t Encryption::get_private_key() {
	return private_key;
}

void Encryption::set_private_key(uint256_t privatekey) {
	private_key = privatekey;
}

uint256_t Encryption::get_public_key() {
	return public_key;
}

uint256_t Encryption::sign_document(uint256_t private_key, std::string text) {
	return private_key;
}

bool Encryption::verify(uint256_t public_key, uint256_t signature, std::string text) {
	return true;
}



