#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle : public Drawable
{
public:
	Paddle(float t_X, float t_Y);
	Paddle()= delete;
	~Paddle()=default;

	float left();
	float right();
	float top();
	float bottom();

	void update();
	Vector2f getPosition();
private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	float width = 80.0;
	float hight = 20.0;
	float paddle_V = 6.0;
	Vector2f velocity{ paddle_V, 0.f };
};

