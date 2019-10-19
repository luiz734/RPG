#pragma once
#define RIGHT 1, 0
#define DOWN 0, 1
#define LEFT -1, 0
#define UP 0, -1
#include "SFML/Graphics.hpp"
#include "Showable.h"

class Window;
class Stage;

class Character : public Showable
{
public:
	const int DEFAULT_SPRITE_SIZE;
	const int DEFAULT_CHARACTER_DIMENSION;
	const int ANIMATION_SPEED;
	
	sf::Vector2f nextPosition;
	sf::Vector2f direction;
	
	int animationType;  // row
	int animationFrame; // column
	int totalFrames;
	int velocity;
	bool isMoving;


	
	Character(Window* _window, std::string textureAddress, float scale, int x, int y, int width, int height);
	~Character();
	void Draw();
	void Move(bool shouldMove);
	void Update();
	void SetDirection(int x, int y);
	void Interact();
	void Animate(int windowFrame);

};

