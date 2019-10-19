#include "Object.h"
#include "Window.h"

Object::Object(Window* _window, std::string textureAddress, float scale, int x, int y, int width, int height) :
	Showable(_window, textureAddress, scale, x, y, width, height)
{
	isSolid = true;
}
Object::~Object()
{
}

void Object::Update()
{
}

