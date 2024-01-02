#include "label.hpp"
#include "canvas.hpp"

Label::Label(const std::string& text)
{
	this->text = text;
}

Size Label::measure(int fontSize)
{
	canvas.ctx.set("font", std::to_string(fontSize) + "px serif");
	emscripten::val jssize = canvas.ctx.call<emscripten::val>("measureText", text);
	Size res;
	res.width = jssize["width"].as<int>();
	res.height = fontSize;
	return res;
}
void Label::draw(int fontSize, int x, int y)
{
	canvas.ctx.set("fillStyle", (std::string)"black");
	canvas.ctx.set("font", std::to_string(fontSize) + "px serif");
	canvas.ctx.call<void>("fillText", text, x, y + fontSize);
}