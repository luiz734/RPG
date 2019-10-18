#pragma once
#include <string>
#include "SFML/Graphics.hpp"

class Window;

class Showable
{
public:
	Window* window;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite body;

	int bodyScale;

	Showable(Window* _window, std::string textureAddress, int x = 0, int y = 0, int height = 32, int width = 32);
	virtual ~Showable();
	virtual void Update() = 0;
	virtual void Draw();
	void SetBodyScale(float newScale);
};
