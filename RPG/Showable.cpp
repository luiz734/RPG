#include "Showable.h"
#include "Window.h"
#include <iostream>

Showable::Showable(Window* _window, std::string textureAddress, float scale, int x, int y, int width, int height) :
	window(_window),
	position(x, y),
	size(width, height),
	bodyScale(scale),
	isSolid(false)
{
	texture.loadFromFile(textureAddress);
	body.setTexture(texture);
	body.setPosition(position);
	body.setScale(bodyScale, bodyScale);

	dimension.x = texture.getSize().x * bodyScale / window->BLOCK_SIZE;
	dimension.y = texture.getSize().y * bodyScale / window->BLOCK_SIZE;

	std::cout << dimension.x << " " << dimension.y << "\n";
}

Showable::~Showable()
{
}

void Showable::Draw()
{
	window->Draw(body);
}

void Showable::SetBodyScale(float newScale)
{
	bodyScale = newScale;
	body.setScale(newScale, newScale);
}
