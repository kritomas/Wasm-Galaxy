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

	globalGame.init(20, 20);

	return 0;
}