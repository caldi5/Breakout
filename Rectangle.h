#pragma once
#include "PhysicalObject.h"

class Rectangle :
	public PhysicalObject
{
public:
	Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, int value);
	~Rectangle();
	void Draw(sf::RenderWindow &Window);
	virtual bool checkCollisoin(Ball *ball);
	virtual void collisionAction();
	sf::Vector2f getPos();
	void addValue();
	int getValue();
protected:
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape rectangle;
	bool isAlive;
private:
	int value;
};

