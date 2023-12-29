#ifndef BOX_HPP
#define BOX_HPP

#include "color.hpp"

class Box
{
public:
	Color color;
	int x = 0, y = 0, w = 0, h = 0;

	void draw();

	bool contains(int x, int y) const;
};

#endif