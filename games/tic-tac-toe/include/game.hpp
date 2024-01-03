#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <vector>
#include "color.hpp"

enum Players { NONE = -1, X = 0, O = 1 };

extern std::unordered_map<Players, Color> playerColors;
void initPlayerColors();

class Game
{
private:
	int SPACE, BOX_SIZE;

	std::vector<Players> grid;
	int w = -1, h = -1;

public:
	void init(int width, int height);

	Players* tileAt(int x, int y);

	void handleClick(int x, int y);
};

extern Game globalGame;

extern "C"
{

void chandleClick(int x, int y);

}

#endif