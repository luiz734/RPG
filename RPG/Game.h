#pragma once
#include "Window.h"

class Game
{
public:
	Window *mainWindow;

	Game();
	~Game();
	void Run();
};

