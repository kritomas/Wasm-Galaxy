#include "canvas.hpp"

Canvas::Canvas() : canvas(0), ctx(0)
{
	canvas = js::document.call<emscripten::val>("getElementById", (std::string)"ccanvas");
	ctx = canvas.call<emscripten::val>("getContext", (std::string)"2d");
}

int Canvas::width() const
{
	return canvas["width"].as<int>();
}
int Canvas::height() const
{
	return canvas["height"].as<int>();
}