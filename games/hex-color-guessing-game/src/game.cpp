#include "game.hpp"
#include "canvas.hpp"
#include <cstdlib>

Game::Game()
{
	TO_BE_FOUND_FONT_SIZE = canvas.height() / 20;
	BOX_SIZE = canvas.height() / 15;
	SPACE = canvas.height() / 100;
}

void Game::newGame(int amount)
{
	toBeFound.r = rand();
	toBeFound.g = rand();
	toBeFound.b = rand();

	colors.clear();
	for (int i = 0; i < amount; ++i)
	{
		colors.push_back(Box());
		colors[i].color.r = rand();
		colors[i].color.g = rand();
		colors[i].color.b = rand();
		colors[i].y = 10 + TO_BE_FOUND_FONT_SIZE * 2;
		colors[i].x = (BOX_SIZE + SPACE) * i + BOX_SIZE;
		colors[i].w = BOX_SIZE;
		colors[i].h = BOX_SIZE;
	}
	colors[rand() % colors.size()].color = toBeFound;
}

void Game::repaint()
{
	findLabel.text = "Find " + toBeFound.toString();
	findLabel.draw(TO_BE_FOUND_FONT_SIZE, 10, 10);

	for (auto& b : colors)
	{
		b.draw();
	}
}