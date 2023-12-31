#include "game.hpp"
#include <map>
#include "canvas.hpp"
#include "jsbindings.hpp"
#include <cstdlib>

std::map<int, std::string> DIFFICULTIES;

void Game::init()
{
	TO_BE_FOUND_FONT_SIZE = canvas.height() / 20;
	DIFF_FONT_SIZE = canvas.height() / 30;
	BOX_SIZE = canvas.height() / 15;
	SPACE = canvas.height() / 100;

	DIFFICULTIES.clear();
	DIFFICULTIES[2] = "U colorblind?";
	DIFFICULTIES[5] = "Normal";
	DIFFICULTIES[20] = "How good is your vision? Yes";

	diffText.text = "Difficulties:";
	difficulties.clear();
	for (auto& d : DIFFICULTIES)
	{
		difficulties.push_back(Label());
		difficulties.back().text = d.second;
	}
}

int Game::difficulty() const
{
	return currentDifficulty;
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
	canvas.clear();
	findLabel.text = "Find " + toBeFound.toString();
	findLabel.draw(TO_BE_FOUND_FONT_SIZE, 10, 10);

	for (auto& b : colors)
	{
		b.draw();
	}

	diffText.draw(DIFF_FONT_SIZE, 10, canvas.height() / 2 - diffText.measure(DIFF_FONT_SIZE).height - SPACE);
	for (int i = 0; i < difficulties.size(); ++i)
	{
		difficulties[i].draw(DIFF_FONT_SIZE, 10, canvas.height() / 2 + (difficulties[i].measure(DIFF_FONT_SIZE).height + SPACE) * i);
	}
}

void Game::handleClick(int x, int y)
{
	for (auto c : colors)
	{
		if (c.contains(x, y))
		{
			if (c.color == toBeFound)
			{
				newGame(currentDifficulty);
				repaint();
				break;
			}
		}
	}
	int i = 0;
	for (auto d : DIFFICULTIES)
	{
		int butY = canvas.height() / 2 + (difficulties[i].measure(DIFF_FONT_SIZE).height + SPACE) * i;
		if (y > butY && y < butY + difficulties[i].measure(DIFF_FONT_SIZE).height)
		{
			currentDifficulty = d.first;
			newGame(currentDifficulty);
			repaint();
			break;
		}

		++i;
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