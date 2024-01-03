#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <cstdint>

class Color
{
public:
	uint8_t r = 0, g = 0, b = 0;

	Color();
	Color(uint8_t red, uint8_t green, uint8_t blue);

	std::string toString() const;

	bool operator==(const Color& other) const;
	bool operator!=(const Color& other) const;
};

#endif