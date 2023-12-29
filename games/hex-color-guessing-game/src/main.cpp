#include "canvas.hpp"
#include "color.hpp"
#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char* argv[])
{
	srand(time(0));

	canvas.init();

	Color col;
	col.r = 255;
	col.g = 127;
	col.b = 3;
	std::cout << col.toString() << std::endl;

	Game game;
	game.newGame(5);
	game.repaint();

	return 0;
}