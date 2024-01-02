#ifndef LABEL_HPP
#define LABEL_HPP

#include "size.hpp"
#include <string>

class Label
{
public:
	std::string text = "";

	Label(const std::string& text = "");

	Size measure(int fontSize);
	void draw(int fontSize, int x, int y);
};

#endif