#include "Window.h"
#include "Stage.h"
#include "Showable.h"
#include "Character.h"
#include "Map.h"
#include "Object.h"

Window::Window() :

	WIDTH(640),
	HEIGHT(512),
	BLOCK_SIZE(64),
	FRAME_RATE(60),
	frameCounter(1),
	window(sf::VideoMode(WIDTH, HEIGHT), "RPG")
	
{
	// configurations
	window.setFramerateLimit(FRAME_RATE);


	stage = new Stage(this);
	player = stage->player;
}

Window::~Window()
{
}
void Window::GetEvents()
{
	while (window.pollEvent(events))
	{
		// events here
		if (events.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Window::GetPlayerKeys()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->SetDirection(1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->SetDirection(0, 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->SetDirection(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->SetDirection(0, -1);
}

void Window::Draw(sf::Sprite &body)
{
	window.draw(body);
}

void Window::GameLoop()
{
	while (window.isOpen())
	{
		GetEvents();
		GetPlayerKeys();
		window.clear(sf::Color(90, 90, 90));

		// draw here
		stage->DrawShowables();

		window.display();

		frameCounter = frameCounter == FRAME_RATE ? 1 : frameCounter + 1;
	}
}

bool Window::IsRunning()
{
	return window.isOpen();
}

