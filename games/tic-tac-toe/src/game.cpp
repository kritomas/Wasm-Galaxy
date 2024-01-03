#include "game.hpp"
#include "jsbindings.hpp"
#include "canvas.hpp"

std::unordered_map<Players, Color> playerColors;
void initPlayerColors()
{
	playerColors[NONE] = Color(0, 0, 0);
	playerColors[X] = Color(255, 0, 0);
	playerColors[O] = Color(0, 0, 255);
}

void Game::init(int width, int height)
{
	w = width;
	h = height;

	grid.resize(w * h);

	for (int i = 0; i < w * h; ++i)
	{
		grid[i] = NONE;
	}
}

Players* Game::tileAt(int x, int y)
{
	if (x < 0 || x >= w || y < 0 || y >= 0) return nullptr;
	return &grid[x * h + y];
}

void Game::handleClick(int x, int y)
{
	//TODO
}

Game globalGame;

extern "C"
{

void chandleClick(int x, int y)
{
	globalGame.handleClick(x * canvas.width() / js::window["innerWidth"].as<int>(), y * canvas.height() / js::window["innerHeight"].as<int>());
}

}