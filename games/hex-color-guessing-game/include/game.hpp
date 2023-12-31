#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "box.hpp"
#include "color.hpp"
#include "label.hpp"

class Game
{
private:
	int TO_BE_FOUND_FONT_SIZE, DIFF_FONT_SIZE;
	int BOX_SIZE, SPACE;

	int currentDifficulty = 5;

public:
	Color toBeFound;
	std::vector<Box> colors;
	Label findLabel;

	Label diffText;
	std::vector<Label> difficulties;

	Label wrongText;

	void init();

	int difficulty() const;

	void newGame(int amount);

	void repaint();

	void handleClick(int x, int y);
};

extern Game globalGame;

extern "C"
{

void chandleClick(int x, int y);

}

#endif