#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Byte.h"

class Aes256 {
	static const int nb = 4, nk = 8, nr = 14;
	static const std::vector <std::vector <byte>> Rcon, Sbox, InvSbox;

	static byte sbyte(byte n);

	static void keyExpansion(std::vector <std::vector <byte>>& key_byte, const std::string& key);

	static void addRoundKey(std::vector <std::vector <byte>>& state, const std::vector <std::vector <byte>>& key_byte, const int k);

	static void subBytes(std::vector <std::vector <byte>>& state);

	static void invSubBytes(std::vector <std::vector <byte>>& state);

	static void shiftRows(std::vector <std::vector <byte>>& state);

	static void invShiftRows(std::vector <std::vector <byte>>& state);

	static void mixColumns(std::vector <std::vector <byte>>& state);

	static void invMixColumns(std::vector <std::vector <byte>>& state);

	static void encrypt(std::string& temp, const std::vector <std::vector<byte>>& key);

	static void decrypt(std::string& temp, const std::vector <std::vector <byte>>& key);

public:

	static std::string encrypt(const std::string& text, const std::string& key);

	static std::string decrypt(const std::string& crypt, const std::string& key);
};