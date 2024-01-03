#include "game.hpp"
#include "jsbindings.hpp"
#include "canvas.hpp"
#include <iostream>

std::unordered_map<int, Color> playerColors;
void initPlayerColors()
{
	playerColors[NONE] = Color(255, 255, 255);
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

	BOX_SIZE = canvas.height() / (1.5 * h);
	SPACE = canvas.height() / (10 * h);

	X_START = 10, Y_START = 10;

	repaint();
}

int* Game::tileAt(int x, int y)
{
	if (x < 0 || x >= w || y < 0 || y >= h) return nullptr;
	return &grid[x * h + y];
}

void Game::repaint()
{
	canvas.clear();

	canvas.ctx.set("fillStyle", Color(0, 0, 0).toString());
	canvas.ctx.call<void>("fillRect", X_START - SPACE, Y_START - SPACE,  w * (BOX_SIZE + SPACE) + SPACE, h * (BOX_SIZE + SPACE) + SPACE);
	for (int x = 0; x < w; ++x)
	{
		for (int y = 0; y < h; ++y)
		{
			canvas.ctx.set("fillStyle", playerColors[*tileAt(x, y)].toString());
			canvas.ctx.call<void>("fillRect", x * (BOX_SIZE + SPACE) + X_START, y * (BOX_SIZE + SPACE) + Y_START, BOX_SIZE, BOX_SIZE);
		}
	}
}

void Game::nextTurn()
{
	currentPlayer = (currentPlayer + 1) % PLAYERS;
}

void Game::handleClick(int x, int y)
{
	x -= X_START;
	y -= Y_START;

	x /= (BOX_SIZE + SPACE);
	y /= (BOX_SIZE + SPACE);

	int* clicked = tileAt(x, y);
	if (clicked != nullptr)
	{
		if (*clicked == NONE)
		{
			*clicked = currentPlayer;
			nextTurn();
			repaint();
		}
	}
}

Game globalGame;

extern "C"
{

void chandleClick(int x, int y)
{
	globalGame.handleClick(x * canvas.width() / js::window["innerWidth"].as<int>(), y * canvas.height() / js::window["innerHeight"].as<int>());
}

}