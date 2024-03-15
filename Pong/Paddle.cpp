#include "Paddle.h"

Paddle::Paddle(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ this->width, this->hight });
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->width / 2.f, this->hight / 2.f);
}

void Paddle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Paddle::update()
{
	this->shape.move(this->velocity);

	if((Keyboard::isKeyPressed(Keyboard::Key::Left)|| Keyboard::isKeyPressed(Keyboard::Key::A))&&this->left()>0)
	{
		this->velocity.x = -paddle_V;
	}else if ((Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) && this->right() < 800)
	{
		this->velocity.x = paddle_V;
	}else
	{
		this->velocity.x = 0.f;
	}
}

float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;	
}

float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y/2.f;
}

float Paddle::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Paddle::getPosition()
{
	return this->shape.getPosition();
}