#pragma once
#include "raylib.h"
class Player;
class GameCamera {
public:
	GameCamera();
	Camera2D camera;
	Vector2 camera_pos;
	void Update();
	void followingPlayer(Player& player);
};
