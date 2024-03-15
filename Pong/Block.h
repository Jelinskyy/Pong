#pragma once
#include <SFML/Graphics.hpp>

#include <SFML\Graphics.hpp>

using namespace sf;

class Block: public Drawable
{
public:
	Block(float t_X,float t_Y,float width,float hight);
	Block()=delete;
	~Block()=default;

	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();
	Vector2f getSize();
	bool isDestroy();
	void Destroy();
private:
	RectangleShape shape;
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	bool destroyed{ false };
};

