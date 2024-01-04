#include "box.hpp"
#include "canvas.hpp"

std::unordered_map<int, Color> playerColors;
void initPlayerColors()
{
	playerColors[NONE] = Color(255, 255, 255);
	playerColors[X] = Color(255, 0, 0);
	playerColors[O] = Color(0, 0, 255);
}

void Box::draw()
{
	canvas.ctx.set("fillStyle", playerColors[player].toString());
	canvas.ctx.call<void>("fillRect", x, y, w, h);
}

bool Box::contains(int x, int y) const
{
	if (x > this->x && y > this->y && x < this->x + w && y < this->y + h) return true;
	return false;
}