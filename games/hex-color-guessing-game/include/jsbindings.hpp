#ifndef JSBINDINGS_HPP
#define JSBINDINGS_HPP

#include <emscripten/val.h>

namespace js
{
	extern const emscripten::val document;
	extern const emscripten::val console;
}

#endif