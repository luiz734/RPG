#include "Showable.h"
#include "Window.h"


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
