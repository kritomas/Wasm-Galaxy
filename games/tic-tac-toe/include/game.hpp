#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <vector>
#include "color.hpp"
#include "box.hpp"

extern std::unordered_map<int, int> xSeeks, ySeeks;
void initLookupTables();

class Game
{
private:
	int SPACE, BOX_SIZE;
	int X_START, Y_START;

	std::vector<Box> grid;
	int w = -1, h = -1;

	int currentPlayer = 0;
	int winningPlayer = NONE;

public:
	void init(int width, int height);

	Box* tileAt(int x, int y);

	void repaint();

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