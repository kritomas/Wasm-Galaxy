#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <cstdint>

class Color
{
public:
	uint8_t r = 0, g = 0, b = 0;

	std::string toString() const;

	bool operator==(const Color& other) const;
	bool operator!=(const Color& other) const;
};

#endif