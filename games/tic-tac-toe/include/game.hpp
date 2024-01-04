#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <vector>
#include "color.hpp"
#include "box.hpp"

class Game
{
private:
	int SPACE, BOX_SIZE;
	int X_START, Y_START;

	std::vector<Box> grid;
	int w = -1, h = -1;

	int currentPlayer = 0;

public:
	void init(int width, int height);

	Box* tileAt(int x, int y);

	void repaint();

	void nextTurn();

	void handleClick(int x, int y);
};

extern Game globalGame;

extern "C"
{

void chandleClick(int x, int y);

}

#endif