#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include "ball.h"
#include "Paddle.h"
#include "Block.h"

using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& a, T2& b)
{
	return a.right() >= b.left() && b.right() >= a.left()
		&& a.top() <= b.bottom() && b.top() <= a.bottom();
}

bool colisionTest(Paddle& paletka, ball& kulka)
{
	if (!isIntersecting(paletka, kulka))
	{
		return false;
	}

	kulka.moveUp();

	if (paletka.getPosition().x > kulka.getPosition().x)
	{
		kulka.moveLeft();
	}
	else if (paletka.getPosition().x < kulka.getPosition().x)
	{
		kulka.moveRight();
	}

}

bool colisionTest(ball& kulka, Block& block, int& pozostale)
{
	if (!isIntersecting(block, kulka)) return false;

	block.Destroy();
	pozostale--;
	cout << "pozostale:" << pozostale << endl;

	float overlapLeft{ kulka.right() - block.left() };
	float overlapRight{ kulka.left() - block.right() };
	float overlapTop{ kulka.bottom() - block.top() };
	float overlapBottom{ kulka.top() - block.bottom() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? kulka.moveLeft() : kulka.moveRight();
	}
	else
	{
		ballFromTop ? kulka.moveUp() : kulka.moveDown();
	}
}

int main()
{
	ball kulka(400, 300);
	Paddle paletka(400, 550);
	Block block(400, 300, 100, 25);
	RenderWindow window(VideoMode(800, 600), "Arcanoid");
	window.setFramerateLimit(60);
	Event e;
	unsigned blocksX{ 8 }, blocksY{ 4 }, blockWidth{ 80 }, blockHight{ 25 };
	vector<Block> blocks;
	int pozostale=blocksX*blocksY;
	cout << "pozostale:" << pozostale << endl;

	for (unsigned i = 0; i < blocksY; i++)
	{
		for (unsigned j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1)* (blockWidth + 10), (i + 2)*(blockHight + 5), blockWidth, blockHight);
		}
	}

	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(e);
		if (e.type == Event::Closed)
		{
			window.close();
			break;
		}
		kulka.update();
		paletka.update();
		colisionTest(paletka, kulka);
		for (auto& block : blocks) if (colisionTest(kulka, block, pozostale)) break;
		
		auto iterator = remove_if(begin(blocks), end(blocks), [](Block&block) {return block.isDestroy(); });
		blocks.erase(iterator, end(blocks));

		for (auto& block : blocks) window.draw(block);
		window.draw(kulka);
		window.draw(paletka);
		window.display();
		if (pozostale == 0) break;
	}
	return 0;
}