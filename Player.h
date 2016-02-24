#pragma once
#include "Rectangle.h"
#include <iostream>

class Player :
	public Rectangle
{
public:
	Player(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	~Player();
	void Update(sf::RenderWindow &Window);
	void moveLeft();
	void moveRight();
	void laefy();
	void score(int toAdd = 1);
	int getScore();
	bool IsAlive();
protected:
private:
	float speed;
	int lives;
	int playerScore;
};

