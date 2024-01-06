#include "canvas.hpp"
#include "color.hpp"
#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char* argv[])
{
	canvas.init();
	initPlayerColors();
	initLookupTables();

	globalGame.init(DEFAULT_WIDTH, DEFAULT_HEIGHT);

	return 0;
}