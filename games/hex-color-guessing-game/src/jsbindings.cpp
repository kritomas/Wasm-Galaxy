#include "jsbindings.hpp"


const emscripten::val js::document = emscripten::val::global("document");
const emscripten::val js::console = emscripten::val::global("console");