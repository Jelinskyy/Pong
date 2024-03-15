#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ball: public Drawable
{
public:
	ball(float t_X, float t_Y);
	~ball() = default;

	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();

private:
	CircleShape shape;
	const float ballradius{ 10.0f };
	const float ballV{ 5.0f };
	Vector2f velocity{ ballV, ballV };
	void draw(RenderTarget& target, RenderStates state) const override;
};

