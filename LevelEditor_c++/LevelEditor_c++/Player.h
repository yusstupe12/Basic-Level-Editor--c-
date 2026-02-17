#pragma once 
#include"raylib.h"
#include "grid.h"
class Player {
public:
	Player();
	float speed;
	Vector2 Pos;
	Vector2 defPos;
	float velocityY;
	float Raduis;
	Rectangle GetRect();
	void CheckCollison(Grid& grid);
	void Update();
	void Draw();
	void gravity();
};
