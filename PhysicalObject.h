#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

class PhysicalObject
{
public:
	PhysicalObject(sf::Vector2f position);
	~PhysicalObject();
	virtual bool checkCollisoin(Ball *ball) = 0;
	virtual void collisionAction() = 0;
	virtual void Draw(sf::RenderWindow &Window) = 0;
protected:
	sf::Vector2f position;
private:
};

