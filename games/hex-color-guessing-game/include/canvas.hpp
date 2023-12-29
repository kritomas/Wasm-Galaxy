#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "jsbindings.hpp"

class Canvas
{
public:
	emscripten::val canvas;
	emscripten::val ctx;

	Canvas();

	void init();

	int width() const;
	int height() const;

	void clear();
};

extern Canvas canvas;

#endif