#include "game.hpp"
#include "jsbindings.hpp"
#include "canvas.hpp"
#include <iostream>

const int VICTORY_LENGTH = 5;

void Game::init(int width, int height)
{
	w = width;
	h = height;

	grid.resize(w * h);

	BOX_SIZE = canvas.height() / (1.5 * h);
	SPACE = canvas.height() / (10 * h);

	X_START = 10, Y_START = 10;

	for (int x = 0; x < w; ++x)
	{
		for (int y = 0; y < h; ++y)
		{
			Box* b = tileAt(x, y);
			b->player = NONE;
			b->x = x * (BOX_SIZE + SPACE) + X_START;
			b->y = y * (BOX_SIZE + SPACE) + Y_START;
			b->w = BOX_SIZE;
			b->h = BOX_SIZE;
		}
	}

	repaint();
}

Box* Game::tileAt(int x, int y)
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
			tileAt(x, y)->draw();
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

	Box* clicked = tileAt(x, y);
	if (clicked != nullptr)
	{
		if (clicked->player == NONE)
		{
			clicked->player = currentPlayer;
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