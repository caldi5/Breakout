#include "Ball.h"

Ball::Ball(float radius, sf::Vector2f position, sf::Vector2f speed, sf::Color color)
{
	this->radius = radius;
	this->position = position;
	this->speed = speed;
	this->color = color;

	circle.setPosition(position);
	circle.setRadius(radius);
	circle.setFillColor(color);
	circle.setOrigin(sf::Vector2f(radius, radius));
}


Ball::~Ball()
{
}

void Ball::Draw(sf::RenderWindow & Window)
{
	Window.draw(circle);
}

void Ball::setSpeed(sf::Vector2f speed)
{
	this->speed = speed;
}

sf::Vector2f Ball::getPosition()
{
	return position;
}

sf::Vector2f Ball::getSpeed()
{
	return speed;
}

float Ball::getRad()
{
	return radius;
}

void Ball::Update(sf::RenderWindow &Window)
{
	sf::Vector2u windowSize = Window.getSize();

	if (position.x + radius >= windowSize.x || position.x - radius <= 0)
		speed.x *= -1;

	if (position.y + radius >= windowSize.y || position.y - radius <= 0)
		speed.y *= -1;

	position.x += speed.x;
	position.y += speed.y;
	circle.setPosition(position);
}

void Ball::setPosition(sf::Vector2f position)
{
	this->position = position;
	circle.setPosition(position);
}
