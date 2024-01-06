#include "game.hpp"
#include "jsbindings.hpp"
#include "canvas.hpp"
#include <iostream>

const int VICTORY_LENGTH = 5;

std::unordered_map<int, int> xSeeks, ySeeks;
void initLookupTables()
{
	xSeeks[0] = 1;
	xSeeks[1] = 1;
	xSeeks[2] = 1;
	xSeeks[3] = 0;
	xSeeks[4] = -1;
	xSeeks[5] = -1;
	xSeeks[6] = -1;
	xSeeks[7] = 0;

	ySeeks[0] = -1;
	ySeeks[1] = 0;
	ySeeks[2] = 1;
	ySeeks[3] = 1;
	ySeeks[4] = 1;
	ySeeks[5] = 0;
	ySeeks[6] = -1;
	ySeeks[7] = -1;
}
const int DIRECTIONS = 8;

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

int Game::checkVictory(const int x, const int y)
{
	for (int d = 0; d < DIRECTIONS; ++d)
	{
		int count = 1;
		Box* start = tileAt(x, y);
		int distance = 1;
		Box* current = tileAt(x + xSeeks[d] * distance, y + ySeeks[d] * distance);
		while (current != nullptr && current->player == start->player)
		{
			++count;
			++distance;
			current = tileAt(x + xSeeks[d] * distance, y + ySeeks[d] * distance);
		}
		distance = 1;
		current = tileAt(x - xSeeks[d] * distance, y - ySeeks[d] * distance);
		while (current != nullptr && current->player == start->player)
		{
			++count;
			++distance;
			current = tileAt(x - xSeeks[d] * distance, y - ySeeks[d] * distance);
		}
		if (count >= VICTORY_LENGTH)
		{
			return start->player;
		}
	}
	return NONE;
}

void Game::nextTurn()
{
	currentPlayer = (currentPlayer + 1) % PLAYERS;
}

void Game::handleClick(int x, int y)
{
	if (winningPlayer == NONE)
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
				winningPlayer = checkVictory(x, y);
				if (winningPlayer != NONE) std::cout << winningPlayer << " won." << std::endl;
				nextTurn();
				repaint();
			}
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