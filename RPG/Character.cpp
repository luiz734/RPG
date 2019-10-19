#include <iostream>
#include "Character.h"
#include "Window.h"
#include "Stage.h"



Character::Character(Window* _window, std::string textureAddress, float scale, int x, int y, int width, int height) :
	Showable(_window, textureAddress, scale, x, y, width, height),
	DEFAULT_SPRITE_SIZE(32),
	ANIMATION_SPEED(10),
	nextPosition(position), 
	direction(DOWN),
	animationType(1),	
	animationFrame(0),
	totalFrames(2),
	velocity(2),
	isMoving(false)
{
	SetBodyScale(2);

	Animate(0);
}


Character::~Character()
{
}

void Character::Draw()
{
	window->Draw(body);
}

void Character::Move(bool shouldMove)
{
	// should move -> there isnt any block blocking the path
	// if shouldnt move, so didnt
	if (isMoving == false || shouldMove == false) return;

	if (position.x < nextPosition.x) position.x+=velocity;
	else if (position.x > nextPosition.x) position.x-= velocity;
	else if (position.y < nextPosition.y) position.y+=velocity;
	else if (position.y > nextPosition.y) position.y-=velocity;
	else isMoving = false;

	
	body.setPosition(position);
}

void Character::Update()
{
	// if is moving or the preview animation didnt finished
	if (isMoving == true || animationFrame != 1) Animate(window->frameCounter);
}

void Character::SetDirection(int x, int y)
{
	// if is already moving, dont change the next direction ultil reach the courrent nextDirection
	if (isMoving == true) return;

	//	define the next position acording to user input
	direction.x = x;
	direction.y = y;
	nextPosition.x = position.x + direction.x * size.x * bodyScale;
	nextPosition.y = position.y + direction.y * size.y * bodyScale;

	// keep the character on the screen
	if (nextPosition.x < 0 || nextPosition.x > window->WIDTH - size.x * bodyScale)
	{
		nextPosition.x = position.x;
		return;
	}
	else if (nextPosition.y < 0 || nextPosition.y > window->HEIGHT - size.y * bodyScale)
	{
		nextPosition.y = position.y;
		return;
	}


	isMoving = true;
}

void Character::Interact()
{
	// do stuff
}

void Character::Animate(int windowFrame)
{
	if (windowFrame % ANIMATION_SPEED != 0) return;

	// set the animation acording player direction ("looking at")
	animationType = direction == sf::Vector2f(RIGHT) ? animationType = 0 :
					direction == sf::Vector2f(DOWN)  ? animationType = 1 :
					direction == sf::Vector2f(UP)    ? animationType = 2 : 3;

	body.setTextureRect(sf::IntRect(animationFrame * size.x, animationType * size.y, size.x, size.y));
	animationFrame = animationFrame == totalFrames ? 0 : animationFrame + 1;
}


