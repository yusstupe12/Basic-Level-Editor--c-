#include "Player.h"
#include <iostream>
#include "raylib.h"
using namespace std;

Player::Player() {
    speed = 5;
    Raduis = 40;
    mousepos = { 0, 0 };
    defPos = { 1280 / 2 - 100, 200 };
    dragging = false;
    Pos = defPos;
    velocityY = 0.0f;
}

Rectangle Player::GetRect() {
    return { Pos.x, Pos.y, Raduis, Raduis };
}

void Player::Update() {
    if (IsKeyDown(KEY_A)) Pos.x -= speed;
    if (IsKeyDown(KEY_D)) Pos.x += speed;
    if (IsKeyPressed(KEY_SPACE)) Pos.y -= 70;
}

void Player::gravity() {
    velocityY += 0.5f;
    Pos.y += velocityY;
}

void Player::Draw() {
    DrawRectangleV(Pos, Vector2{ Raduis, Raduis }, RED);
}
void Player::CheckCollison(Grid& grid) {
    Rectangle playerrect = GetRect();
    int cell = grid.getcolsize();
    int startcol = (int)floor(playerrect.x / cell);
    int endcol = (int)floor((playerrect.x + playerrect.width) / cell);
    int startrow = (int)floor(playerrect.y / cell);
    int endrow = (int)floor((playerrect.y + playerrect.height) / cell);

    for (int row = startrow; row <= endrow; row++) {
        for (int col = startcol; col <= endcol; col++) {
            // removed bounds check — no longer needed with infinite grid
            if (!grid.istilitedSolid(row, col)) continue;
            Rectangle tilerec = { (float)(col * cell), (float)(row * cell), (float)cell, (float)cell };
            Rectangle prect = GetRect();
            if (CheckCollisionRecs(prect, tilerec)) {
                if (velocityY > 0) {
                    Pos.y = tilerec.y - prect.height;
                    velocityY = 0;
                }
                else if (velocityY < 0) {
                    Pos.y = tilerec.y + tilerec.height;
                    velocityY = 0;
                }
            }
        }
    }
}
void Player::Control(Camera2D& camera) {
    mousepos = GetScreenToWorld2D(GetMousePosition(), camera);
    Rectangle playerrect = GetRect();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(mousepos, playerrect))
    {
        dragging = true;
        dragffest = { mousepos.x - Pos.x, mousepos.y - Pos.y };
        std::cout << "dragging\n";
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        dragging = false;
    if (dragging)
        defPos = { mousepos.x - dragffest.x, mousepos.y - dragffest.y };
}