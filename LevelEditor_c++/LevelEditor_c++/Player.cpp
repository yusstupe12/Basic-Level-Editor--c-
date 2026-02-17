#include "Player.h"
#include <iostream>
#include "raylib.h"
using namespace std;
Player::Player() {
	speed = 5;
	Raduis = 40;
	Pos = { 1280 / 2 - 100, -10 };
	defPos = { 1280 / 2 - 100, -10 };
	velocityY = 0.0f;
}
void Player::Update() {
	if (IsKeyDown(KEY_A)) Pos.x -= speed;
	if (IsKeyDown(KEY_D)) Pos.x += speed;
	if (IsKeyPressed(KEY_SPACE))Pos.y -= 70;
}
void Player::gravity() {
	velocityY += .5 ;
	Pos.y += velocityY;
}
void Player::Draw() {
	DrawRectangleV(Pos, Vector2(Raduis, Raduis), RED);
}
Rectangle Player::GetRect() {
	return{ Pos.x, Pos.y, Raduis,Raduis };
}
void Player::CheckCollison(Grid& grid) {
	Rectangle playerrect = GetRect();
	int cell = grid.getcolsize();
	int startcol = playerrect.x / cell;
	int endcol = (playerrect.x + playerrect.width) / cell;
	int startrow = playerrect.y / cell;
	int endrow = (playerrect.y + playerrect.height) / cell;
	for (int row = startrow; row <= endrow; row++) {
		for (int col = startcol; col <= endcol; col++) {
			if (row < 0 || col < 0 || row >= grid.getrows() || col >= grid.getcols()) continue;

			if (!grid.istilitedSolid(row, col))
				continue;
			Rectangle tilerec = { col * cell, row * cell, (float)cell, (float)cell };
			Rectangle playerrect = GetRect();
			if(CheckCollisionRecs(playerrect, tilerec)){
				if (velocityY > 0) {
					Pos.y = tilerec.y - playerrect.height;
					velocityY = 0;
				}
				else if (velocityY < 0)
				{
					Pos.y = tilerec.y + tilerec.height;
					velocityY = 0;
				}
			}
		}
	}

}