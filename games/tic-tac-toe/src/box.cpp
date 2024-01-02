#include "box.hpp"
#include "canvas.hpp"

void Box::draw()
{
	canvas.ctx.set("fillStyle", color.toString());
	canvas.ctx.call<void>("fillRect", x, y, w, h);
}

bool Box::contains(int x, int y) const
{
	if (x > this->x && y > this->y && x < this->x + w && y < this->y + h) return true;
	return false;
}