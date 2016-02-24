#include "Player.h"

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color) : Rectangle(position, size, color)
{
	speed = 4;
	lives = 3;
	playerScore = 0;
}


Player::~Player()
{
}

void Player::Update(sf::RenderWindow &Window)
{
	// Fix if statement
	position.x = (sf::Mouse::getPosition(Window).x - (size.x / 2));
	rectangle.setPosition(position);
}

void Player::moveLeft()
{
	if (position.x > 0)
		position.x -= speed;

	rectangle.setPosition(position);
}

void Player::moveRight()
{
	position.x += speed;

	rectangle.setPosition(position);
}

void Player::laefy()
{
	lives--;
	std::cout << "Lives: " << lives << std::endl;
	if (lives <= 0)
		isAlive = false;
}

void Player::score()
{
	playerScore++;
}

int Player::getScore()
{
	return playerScore;
}

bool Player::IsAlive()
{
	return isAlive;
}
