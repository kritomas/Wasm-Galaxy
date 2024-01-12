#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <vector>
#include "color.hpp"
#include "box.hpp"
#include "label.hpp"

extern const int DEFAULT_WIDTH, DEFAULT_HEIGHT;

extern std::unordered_map<int, int> xSeeks, ySeeks;
void initLookupTables();

class Game
{
private:
	int SPACE, BOX_SIZE;
	int X_START, Y_START;

	std::vector<Box> grid;
	int w = -1, h = -1;
	Box blackout;

	int currentPlayer = 0;

	Box victoryBox;
	Label victory;

	Box newGameButton;
	Label newGame;

public:
	/**
	 * Starts a new game.
	 */
	void init(int width, int height);

	/**
	 * @return The tile at the specified coordinates, or nullptr if out of bounds.
	 */
	Box* tileAt(int x, int y);

	void repaint();

	/**
	 * @return The player, that won at the specified coordinates, or NONE, if no one has won yet.
	 */
	int checkVictory(const int x, const int y);

	void nextTurn();

	void handleClick(int x, int y);
};

extern Game globalGame;

extern "C"
{

void chandleClick(int x, int y);

}

#endif