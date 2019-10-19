#include "Stage.h"
#include "Map.h"
#include "Character.h"

Stage::Stage(Window* _window) :
	window(_window)
{

	map = new Map(window, "bg-grass.png", 2, 0, 0, 640, 512);
	Object* sofa = new Object(window, "sofa.png", 2, 64 * 4, 64 * 3);
	objects.push_back(sofa);
	Object* sofa2 = new Object(window, "sofa.png", 2, 320, 320);
	objects.push_back(sofa2);

	player = new Character(window, "suit-man.png", 2, 0, 0, 32, 32);
	characters.push_back(player);
	
	
}

Stage::~Stage()
{
}

void Stage::DrawShowables()
{
	// drawing map
	map->Draw();

	// drawing objects
	for (auto const& obj : objects)
		obj->Draw();

	// drawing character
	for (auto const& chr : characters)
	{
		chr->Move(CheckBlockIsAvaliable(chr));
		chr->Update();
		chr->Draw();
	}
}


bool Stage::CheckBlockIsAvaliable(Character* character)
{
	character->isMoving = false;

	for (auto const& obj : objects)
		if (obj->isSolid && obj->position == character->nextPosition)
			return false;

	for (auto const& chr : characters)
		if (chr->isSolid && chr->position == chr->nextPosition && character != chr)
			return false;

	character->isMoving = true;
	return true;
}
