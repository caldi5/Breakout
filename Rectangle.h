#pragma once
#include "PhysicalObject.h"

class Rectangle :
	public PhysicalObject
{
public:
	Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	~Rectangle();
	void Draw(sf::RenderWindow &Window);
	virtual bool checkCollisoin(Ball *ball);
	virtual void collisionAction();
	sf::Vector2f getPos();
protected:
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape rectangle;
	bool isAlive;
private:
};

