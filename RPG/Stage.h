#pragma once
#include <list>
#include "Showable.h"
#include "Map.h"
#include "Object.h"

class Window;
class Character;

class Stage
{
public:
	Window* window;
	Character* player;
	Map* map;
	std::list<Showable*> objects;
	std::list<Character*> characters;

	Stage(Window* _window);
	~Stage();
	void DrawShowables();
	bool CheckBlockIsAvaliable(Character* chr);

};

