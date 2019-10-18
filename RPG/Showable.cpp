#include "Showable.h"
#include "Window.h"


Showable::Showable(Window* _window, std::string textureAddress, int x, int y, int height, int width) :
	window(_window),
	position(x, y),
	size(width, height),
	bodyScale(1)
{
	texture.loadFromFile(textureAddress);
	body.setTexture(texture);
	body.setPosition(position);
	body.setScale(bodyScale, bodyScale);
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
