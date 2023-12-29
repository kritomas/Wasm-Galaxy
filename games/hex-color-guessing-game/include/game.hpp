#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "box.hpp"
#include "color.hpp"
#include "label.hpp"

class Game
{
private:
	int TO_BE_FOUND_FONT_SIZE;
	int BOX_SIZE, SPACE;

public:
	Color toBeFound;
	std::vector<Box> colors;
	Label findLabel;

	Game();

	void newGame(int amount);

	void repaint();
};

#endif