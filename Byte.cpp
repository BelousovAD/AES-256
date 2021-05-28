
#include "Byte.h"

using uchar = unsigned char;

uchar byte::pow(uchar n, uchar k) {
	uchar res = 1;

	while (k) {
		if (k % 2) {
			res *= res;
			k /= 2;
		}
		else {
			res *= n;
			--k;
		}
	}

	return res;
}

uchar byte::first() {
	return n / 16;
}
uchar byte::second() {
	return n % 16;
}
//математика в поле галуа
byte byte::operator+(const byte a) {
	return n ^ a.n;
}

byte byte::operator^(const byte a) {
	return n ^ a.n;
}

byte byte::operator^=(const byte a) {
	n ^= a.n;
	return n;
}

byte byte::operator+=(const byte a) {
	n ^= a.n;
	return n;
}

byte byte::operator*(const byte a) {
	uchar res = 0;
	uchar c;
	while (n) {
		c = 1 << (uchar)floor(log2(n));
		res ^= c * a.n;
		n -= c;
	}
	return res;
}