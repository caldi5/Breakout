#include "Rectangle.h"


Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, int value) : PhysicalObject(position)
{
	this->size = size;
	this->color = color;
	this->value = value;
	isAlive = true;

	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
}


Rectangle::~Rectangle()
{
}

void Rectangle::Draw(sf::RenderWindow & Window)
{
	if (isAlive)
		Window.draw(rectangle);
}

bool Rectangle::checkCollisoin(Ball *ball)
{
	if (isAlive)
	{
		sf::Vector2f pos = ball->getPosition();
		sf::Vector2f speed = ball->getSpeed();
		int rad = ball->getRad();
		sf::IntRect rect(position.x, position.y, size.x, size.y);

		if (rect.contains(pos.x + rad, pos.y) || rect.contains(pos.x - rad, pos.y))
		{
			if ((pos.x + rad) < (position.x + (size.x / 2)))
			{
				pos.x = position.x - rad;
				ball->setPosition(pos);
			}
			else
			{
				pos.x = position.x + size.x + rad;
				ball->setPosition(pos);
			}

			speed.x *= -1;
			ball->setSpeed(speed);
			return true;
		}

		if (rect.contains(pos.x, pos.y + rad) || rect.contains(pos.x, pos.y - rad))
		{
			if ((pos.y + rad) < (position.y + (size.y/2)))
			{
				pos.y = position.y - rad;
				ball->setPosition(pos);
			}
			else
			{
				pos.y = position.y + size.y + rad;
				ball->setPosition(pos);
			}
			speed.y *= -1;
			ball->setSpeed(speed);
			return true;
		}
	}

	return false;
}

// Useless method
void Rectangle::collisionAction()
{
	isAlive = false;
}

sf::Vector2f Rectangle::getPos()
{
	return position;
}

void Rectangle::addValue()
{
	value++;
}

int Rectangle::getValue()
{
	return value;
}
