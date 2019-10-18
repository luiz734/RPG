#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Showable.h"

class Map : public Showable
{
public:
	std::string name;
	std::string id;
	std::vector<std::vector<std::string>> map;
	//sf::Texture texture;
	//sf::Sprite body;

	std::string tempSize;

	Map(Window* _window, std::string textureAddress, int x, int y, int height, int width);
	~Map();
	void LoadMap();
	void LoadFile(std::string address);
	void Draw();
	void Update();
};

