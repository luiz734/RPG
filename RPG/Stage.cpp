#include "Stage.h"
#include "Map.h"
#include "Character.h"
#include "Window.h"

Stage::Stage(Window* _window) :
	window(_window)
{

	map = new Map(window, "img/bg-grass.png", 2, 0, 0, 640, 512);
	Object* sofa = new Object(window, "img/sofa.png", 2, 64 * 4, 64 * 3, 64, 32);
	objects.push_back(sofa);
	Object* sofa2 = new Object(window, "img/sofa.png", 2, 320, 320, 64, 32);
	objects.push_back(sofa2);

	player = new Character(window, "img/suit-man.png", 2, 0, 0, 32, 32);
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
	/*
		check if the courrent character next position is occuped by some solid block
		if it is, so dont let it go there
	*/
	for (auto const& obj : objects)
		if (obj->isSolid)
			for (int i = 0; i < obj->dimension.x; i++)
				if (obj->position.x + (i * window->BLOCK_SIZE) == character->nextPosition.x)
					for (int i = 0; i < obj->dimension.y; i++)
						if (obj->position.y + (i * window->BLOCK_SIZE) == character->nextPosition.y)
							return false;

	for (auto const& chr : characters)
		if (chr->isSolid && chr->position == chr->nextPosition && character != chr)
			return false;

	character->isMoving = true;
	return true;
}
