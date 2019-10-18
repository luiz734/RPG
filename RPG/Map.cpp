#include "Map.h"
#include "Window.h"

Map::Map(Window* _window, std::string textureAddress, int x, int y, int height, int width)  :
	Showable(_window, textureAddress, x, y, width, height),
	map(4, std::vector<std::string>(4, "0"))
{
	body.setScale(2, 2);
	LoadMap();
}

Map::~Map()
{
}

void Map::LoadMap()
{
	// put the elements of the map ex: rock, brush, etc;	
}

void Map::LoadFile(std::string address)
{
	std::ifstream data(address);
	std::string tmp;

	std::getline(data, tmp);	//copying name
	name.assign(tmp);
	std::getline(data, tmp);	//copying id
	id.assign(tmp);
	std::getline(data, tmp);	//copying size
	tempSize.assign(tmp);


	if (data.is_open())
	{
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
			{
				std::getline(data, tmp);
				map[i][j] = tmp;
			}
		}
	}

	else std::cout << "Unable to open file";

}

void Map::Draw()
{
	window->Draw(body);
}

void Map::Update()
{
}
