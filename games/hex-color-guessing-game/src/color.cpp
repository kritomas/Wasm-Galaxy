#include "color.hpp"
#include <iostream>

std::string byteToHex(uint8_t byte)
{
	std::string res = "";

	uint8_t quartet = (byte & (16 | 32 | 64 | 128)) >> 4;
	if (quartet < 10) res += ('0' + quartet);
	else res += ('A' + quartet - 10);
	std::cout << (int)(quartet) << " " << res << std::endl;

	quartet = (byte & (1 | 2 | 4 | 8));
	if (quartet < 10) res += ('0' + quartet);
	else res += ('A' + quartet - 10);
	std::cout << (int)(quartet) << " " << res << std::endl;

	return res;
}

std::string Color::toString() const
{
	std::string res = "#";
	res += byteToHex(r);
	res += byteToHex(g);
	res += byteToHex(b);
	return res;
}