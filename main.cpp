#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "Ball.h"
#include "Player.h"

int main()
{
	int counter = 0;
	sf::Vector2i windowSize(800, 500);
	sf::RenderWindow Window(sf::VideoMode(windowSize.x, windowSize.y), "Breakout", sf::Style::Default);
	//Window.setKeyRepeatEnabled(false);
	Window.setMouseCursorVisible(false);
	Window.setVerticalSyncEnabled(true);

	Player player(sf::Vector2f(windowSize.x / 2, windowSize.y - 100), sf::Vector2f(80, 20), sf::Color::White);
	//Ball ball(10, sf::Vector2f(200, 200), sf::Vector2f(0.03, 0.03), sf::Color::Red);
	Ball ball(10, sf::Vector2f(200, 200), sf::Vector2f(3, 3), sf::Color::Red);
	Rectangle **recs = new Rectangle*[40];

	// RED LOOP
	for (int i = 0; i < 10; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80*counter, 50), sf::Vector2f(80, 20), sf::Color::Red);
		counter++;
	}
	counter = 0;
	// YELLOW LOOP
	for (int i = 10; i < 20; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50+20), sf::Vector2f(80, 20), sf::Color::Yellow);
		counter++;
	}
	counter = 0;
	// GREEN LOOP
	for (int i = 20; i < 30; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50 + 40), sf::Vector2f(80, 20), sf::Color::Green);
		counter++;
	}
	counter = 0;
	// BLUE LOOP
	for (int i = 30; i < 40; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50 + 60), sf::Vector2f(80, 20), sf::Color::Blue);
		counter++;
	}
	counter = 0;

	while (Window.isOpen())
	{
		sf::Event Event;

		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case (sf::Event::Closed) :
				Window.close();
				break;
			case (sf::Event::MouseMoved) :
				player.Update(Window);
				break;
			case (sf::Event::KeyPressed) :
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();
				break;
			default:
				break;
			}
		}

		//if (Event.key.code == sf::Keyboard::Left)
		//	player.moveLeft();
		//if (Event.key.code == sf::Keyboard::Right)
		//	player.moveRight();

		ball.Update(Window);

		for (int i = 0; i < 40; i++)
		{
			if (recs[i]->checkCollisoin(&ball))
			{
				recs[i]->collisionAction();
				player.score();
			}
		}

		if ((ball.getPosition().y + ball.getRad()) >= windowSize.y)
			player.laefy();
		
		player.checkCollisoin(&ball);

		Window.clear();
		for (int i = 0; i < 40; i++)
		{
			recs[i]->Draw(Window);
		}

		player.Draw(Window);
		ball.Draw(Window);
		Window.display();

		if (!player.IsAlive())
			Window.close();
	}

	return 0;
}