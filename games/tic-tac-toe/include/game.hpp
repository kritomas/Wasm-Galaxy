#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <vector>
#include "color.hpp"

enum Players { NONE = -1, X = 0, O = 1,   PLAYERS = 2 };

extern std::unordered_map<int, Color> playerColors;
void initPlayerColors();

class Game
{
private:
	int SPACE, BOX_SIZE;
	int X_START, Y_START;

	std::vector<int> grid;
	int w = -1, h = -1;

	int currentPlayer = 0;

public:
	void init(int width, int height);

	int* tileAt(int x, int y);

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