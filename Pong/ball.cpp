#include "ball.h"
#include <SFML/Graphics.hpp>

using namespace sf;


ball::ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballradius);
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->ballradius, this->ballradius);
}

void ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void ball::update()
{
	shape.move(this->velocity);

	if (this->left() < 0)
	{
		velocity.x = ballV;
	}else if (this->right() > 800)
	{
		velocity.x = -ballV;
	}else if (this->top() < 0)
	{
		velocity.y = ballV;
	}else if (this->bottom() > 600)
	{
		velocity.y = -ballV;
	}
}

float ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void ball::moveDown()
{
	this->velocity.y = ballV;
}

void ball::moveUp()
{
	this->velocity.y = -ballV;
}

void ball::moveLeft()
{
	this->velocity.x = -ballV;
}

void ball::moveRight()
{
	this->velocity.x = ballV;
}

Vector2f ball::getPosition()
{
	return this->shape.getPosition();
}