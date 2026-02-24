#include "Camera.h"
#include "Player.h"
#include "raylib.h"

GameCamera::GameCamera() {
	camera_pos = { 0,0 };

	camera.offset = {
		GetScreenWidth() / 2.0f,
		GetScreenHeight() / 2.0f
	};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
	camera.target = camera_pos;
}

void GameCamera::Update() {
	if (IsKeyDown(KEY_W)) camera_pos.y -= 3;
	if (IsKeyDown(KEY_S)) camera_pos.y += 3;
	if (IsKeyDown(KEY_D)) camera_pos.x += 3;
	if (IsKeyDown(KEY_A)) camera_pos.x -= 3;
	camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.target = camera_pos;
}

void GameCamera::followingPlayer(Player& player) {
	camera_pos = player.Pos;
	camera.target = camera_pos;
}