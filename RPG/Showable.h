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
	sf::Vector2f dimension;
	sf::Texture texture;
	sf::Sprite body;

	int bodyScale;
	bool isSolid;

	Showable(Window* _window, std::string textureAddress, float scale=1, int x = 0, int y = 0, int width = 32, int height = 32);
	virtual ~Showable();
	virtual void Update() = 0;
	void Draw();
	void SetBodyScale(float newScale);
};
