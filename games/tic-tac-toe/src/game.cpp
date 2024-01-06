#include "game.hpp"
#include "box.hpp"
#include "jsbindings.hpp"
#include "canvas.hpp"
#include <iostream>

const int DEFAULT_WIDTH = 20, DEFAULT_HEIGHT = 20;

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
	blackout.x = X_START - SPACE;
	blackout.y = Y_START - SPACE;
	blackout.w = w * (BOX_SIZE + SPACE) + SPACE;
	blackout.h = h * (BOX_SIZE + SPACE) + SPACE;
	blackout.player = BACKGROUND;

	victoryBox.x = blackout.x + blackout.w + SPACE * 3;
	victoryBox.y = blackout.y;
	victoryBox.w = BOX_SIZE;
	victoryBox.h = BOX_SIZE;

	victory.text = " won";

	newGameButton.x = victoryBox.x;
	newGameButton.y = victoryBox.y + victoryBox.h + SPACE * 3;
	newGameButton.w = victoryBox.w;
	newGameButton.h = victoryBox.h;
	newGameButton.player = NEWGAME;

	newGame.text = " <--- New Game";

	currentPlayer = 0;
	victoryBox.player = NONE;

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

	blackout.draw();
	for (int x = 0; x < w; ++x)
	{
		for (int y = 0; y < h; ++y)
		{
			tileAt(x, y)->draw();
		}
	}

	if (victoryBox.player != NONE)
	{
		victoryBox.draw();
		victory.draw(BOX_SIZE, victoryBox.x + victoryBox.w, victoryBox.y);
	}
	newGameButton.draw();
	newGame.draw(BOX_SIZE, newGameButton.x + newGameButton.w, newGameButton.y);
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
	if (newGameButton.contains(x, y))
	{
		init(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		return;
	}

	if (victoryBox.player == NONE)
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
				victoryBox.player = checkVictory(x, y);
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