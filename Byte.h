#pragma once
#include <cmath>

class byte {
	using uchar = unsigned char;
	uchar pow(uchar n, uchar k);

public:
	uchar n;

	byte() : n(0) {}
	byte(const uchar a) : n(a) {}
	byte(const byte& a) : n(a.n) {}

	uchar first();
	uchar second();

	byte operator+(const byte a);

	byte operator^(const byte a);

	byte operator^=(const byte a);

	byte operator+=(const byte a);

	byte operator*(const byte a);
};