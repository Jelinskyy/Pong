#include "Block.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Block::Block(float t_X, float t_Y, float width, float hight)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ width, hight });
	shape.setFillColor(Color::Green);
	shape.setOrigin(width / 2.f, hight / 2.f);
}

void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Block::getPosition()
{
	return this->shape.getPosition();
}

Vector2f Block::getSize()
{
	return this->shape.getSize();
}

bool Block::isDestroy()
{
	return this->destroyed;
}

void Block::Destroy()
{
	this->destroyed = true;
}