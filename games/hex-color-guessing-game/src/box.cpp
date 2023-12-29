#include "box.hpp"
#include "canvas.hpp"

void Box::draw()
{
	canvas.ctx.set("fillStyle", color.toString());
	canvas.ctx.call<void>("fillRect", x, y, w, h);
}