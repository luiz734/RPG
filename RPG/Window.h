#pragma once
#include <SFML/Graphics.hpp>

class Showable;
class Character;
class Map;

class Window
{
public:
	const int HEIGHT;
	const int WIDTH;
	const int BLOCK_SIZE;
	const int FRAME_RATE;

	int frameCounter;

	sf::RenderWindow window;
	sf::Event events;

	Character *player;
	Map *stage;

	Window(); 
	~Window();
	void GetEvents();
	void GetPlayerKeys();
	void Draw(sf::Sprite &body);
	void GameLoop();
	bool IsRunning();
};
//const int Window::HEIGHT=480;
//const int Window::WIDTH=600;
//const int Window::BLOCK_SIZE=32;
//const int Window::FRAME_RATE=30;