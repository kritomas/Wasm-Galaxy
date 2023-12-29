#include "canvas.hpp"
#include "color.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	canvas.init();
	std::string size = std::to_string(canvas.height()/10);
	canvas.ctx.set("font", size + "px serif");
	canvas.ctx.call<void>("fillText", (std::string)"Hello World!", 10, 100);

	Color col;
	col.r = 255;
	col.g = 127;
	col.b = 3;
	std::cout << col.toString() << std::endl;

	return 0;
}