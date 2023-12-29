#include "canvas.hpp"

Canvas::Canvas() : canvas(emscripten::val::undefined()), ctx(emscripten::val::undefined())
{
}

void Canvas::init()
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

Canvas canvas;