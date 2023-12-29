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

	globalGame.init();
	globalGame.newGame(5);
	globalGame.repaint();

	return 0;
}