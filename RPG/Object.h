#pragma once
#include "Showable.h"

class Window;

class Object : public Showable
{
public:
	Object(Window* _window, std::string textureAddress, float scale, int x = 0, int y = 0, int width = 32, int height = 32);
	~Object();
	void Update();
};

