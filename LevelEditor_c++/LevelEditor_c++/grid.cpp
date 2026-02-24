#include "grid.h"
#include "Player.h"
#include "raylib.h"
#include <iostream>
using namespace std;

Grid::Grid() {
    cellsize = 40;
    start = true;
}

void Grid::draw(Camera2D& camera) {
    Vector2 topLeft = GetScreenToWorld2D({ 0, 0 }, camera);
    Vector2 bottomRight = GetScreenToWorld2D(
        { (float)GetScreenWidth(), (float)GetScreenHeight() }, camera);

    int startCol = (int)(topLeft.x / cellsize) - 1;
    int endCol = (int)(bottomRight.x / cellsize) + 1;
    int startRow = (int)(topLeft.y / cellsize) - 1;
    int endRow = (int)(bottomRight.y / cellsize) + 1;

    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            bool solid = istilitedSolid(row, col);
            Color tileColor = solid ? LIGHTGRAY : DARKGRAY;
            DrawRectangle(col * cellsize, row * cellsize, cellsize, cellsize, tileColor);
            if (start)
                DrawRectangleLines(col * cellsize, row * cellsize, cellsize, cellsize, BLACK);
        }
    }
}

void Grid::Update(Player& player, Camera2D& camera) {
    Vector2 mouseWorld = GetScreenToWorld2D(GetMousePosition(), camera);
    int col = (int)floor(mouseWorld.x / cellsize);
    int row = (int)floor(mouseWorld.y / cellsize);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !player.dragging)
        tiles[{row, col}] = 1;

    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        tiles.erase({ row, col });
}

bool Grid::istilitedSolid(int row, int col) {
    auto it = tiles.find({ row, col });
    return it != tiles.end() && it->second == 1;
}

int Grid::getcolsize() { return cellsize; }