#ifndef BOX_HPP
#define BOX_HPP

#include <unordered_map>
#include "color.hpp"

enum Players { NONE = -1, X = 0, O = 1,   PLAYERS = 2 };

extern std::unordered_map<int, Color> playerColors;
void initPlayerColors();

class Box
{
public:
	int player = NONE;
	int x = 0, y = 0, w = 0, h = 0;

	void draw();

	bool contains(int x, int y) const;
};

#endif