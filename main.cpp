#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "Ball.h"
#include "Player.h"

void endScreen(sf::Time time, int score);

int main()
{
	int counter = 0, rectCounter = 40;
	sf::Vector2i windowSize(800, 500);
	sf::RenderWindow Window(sf::VideoMode(windowSize.x, windowSize.y), "Breakout", sf::Style::Default);
	sf::Clock clock;
	sf::Time time;
	//Window.setKeyRepeatEnabled(false);
	Window.setMouseCursorVisible(false);
	Window.setVerticalSyncEnabled(true);

	Player player(sf::Vector2f(windowSize.x / 2, windowSize.y - 100), sf::Vector2f(80, 20), sf::Color::White);
	//Ball ball(10, sf::Vector2f(200, 200), sf::Vector2f(0.03, 0.03), sf::Color::Red);
	Ball ball(10, sf::Vector2f(200, 200), sf::Vector2f(3, 3), sf::Color::Red);
	Rectangle **recs = new Rectangle*[rectCounter];
	
	// RED LOOP
	for (int i = 0; i < 10; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80*counter, 50), sf::Vector2f(80, 20), sf::Color::Red, 4);
		counter++;
	}
	counter = 0;

	// YELLOW LOOP
	for (int i = 10; i < 20; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50+20), sf::Vector2f(80, 20), sf::Color::Yellow, 3);
		counter++;
	}
	counter = 0;

	// GREEN LOOP
	for (int i = 20; i < 30; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50 + 40), sf::Vector2f(80, 20), sf::Color::Green, 2);
		counter++;
	}
	counter = 0;

	// BLUE LOOP
	for (int i = 30; i < 40; i++)
	{
		recs[i] = new Rectangle(sf::Vector2f(80 * counter, 50 + 60), sf::Vector2f(80, 20), sf::Color::Blue, 1);
		counter++;
	}

	while (Window.isOpen())
	{
		sf::Event Event;
		if (Window.hasFocus())
		{
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

			for (int i = 0; i < rectCounter; i++)
			{
				if (recs[i]->checkCollisoin(&ball))
				{
					recs[i]->collisionAction();
					player.score(recs[i]->getValue());
					std::cout << "Score: " << player.getScore() << std::endl;
				}
			}
			player.checkCollisoin(&ball);

			if ((ball.getPosition().y + ball.getRad()) >= windowSize.y)
				player.laefy();
			if (!player.IsAlive())
			{
				Window.close();
				time = clock.getElapsedTime();
				endScreen(time, player.getScore());
			}

			Window.clear();
			for (int i = 0; i < rectCounter; i++)
			{
				recs[i]->Draw(Window);
			}

			player.Draw(Window);
			ball.Draw(Window);
			Window.display();


		}
	}
		return 0;
}

void endScreen(sf::Time time, int score) 
{
	system("cls");
	if (score == 100)
		std::cout << "Congrats! You won the game in " << (int)time.asSeconds() << " seconds!" << std::endl;
	else
		std::cout << "You lasted " << (int)time.asSeconds() << " seconds before dying." << std::endl;

	system("pause");
}