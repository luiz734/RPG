#include "Game.h"

Game::Game() 
{
	mainWindow = new Window();
}

Game::~Game()
{
}

void Game::Run()
{
	mainWindow->GameLoop();
}


