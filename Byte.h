#pragma once
#include <cmath>

class byte {//Байт в поле Галуа
	using uchar = unsigned char;
	uchar pow(uchar n, uchar k);

public:
	uchar n;

	byte() : n(0) {}
	byte(const uchar a) : n(a) {}
	byte(const byte& a) : n(a.n) {}

	uchar first();
	uchar second();

	//математика в поле галуа
	byte operator+(const byte a);

	byte operator^(const byte a);

	byte operator^=(const byte a);

	byte operator+=(const byte a);

	byte operator*(const byte a);
};