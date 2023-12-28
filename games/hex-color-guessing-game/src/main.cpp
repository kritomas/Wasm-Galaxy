#include "canvas.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	Canvas canvas;
	std::string size = std::to_string(canvas.height()/10);
	canvas.ctx.set("font", size + "px serif");
	canvas.ctx.call<void>("fillText", (std::string)"Hello World!", 10, 100);
	return 0;
}