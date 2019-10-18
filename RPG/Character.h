#pragma once
#define RIGHT 1, 0
#define DOWN 0, 1
#define LEFT -1, 0
#define UP 0, -1
#include "SFML/Graphics.hpp"
#include "Showable.h"

class Window;

class Character : public Showable
{
public:
	const int DEFAULT_SPRITE_SIZE;
	const int ANIMATION_SPEED;
	
	sf::Vector2f nextPosition;
	sf::Vector2f direction;
	
	int animationType;  // row
	int animationFrame; // column
	int totalFrames;
	int velocity;
	bool isMoving;
	bool interactable;

	
	Character(Window* _window, std::string textureAddress, int x, int y, int height, int width);
	~Character();
	void Draw();
	void Move();
	void Update();
	void SetDirection(int x, int y);
	void Interact();
	void Animate(int windowFrame);

};

