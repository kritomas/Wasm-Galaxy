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

	/**
	 * Initializes the game.
	 */
	void init();

	/**
	 * @return The amount of colors to guess.
	 */
	int difficulty() const;

	/**
	 * Starts a new game.
	 *
	 * @param amount The amount of colors to guess.
	 */
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