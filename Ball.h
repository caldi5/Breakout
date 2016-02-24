#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float radius, sf::Vector2f position, sf::Vector2f speed, sf::Color color);
	~Ball();
	void Draw(sf::RenderWindow &Window);
	void setSpeed(sf::Vector2f speed);
	sf::Vector2f getPosition();
	sf::Vector2f getSpeed();
	float getRad();
	void Update(sf::RenderWindow &Window);
	void setPosition(sf::Vector2f position);
protected:
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Color color;
	float radius;
};

