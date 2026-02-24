#pragma once
#include "raylib.h"
#include <map>
#include <utility>
class Player;

class Grid {
public:
    Grid();
    void draw(Camera2D& camera);
    void Update(Player& player, Camera2D& camera);
    bool istilitedSolid(int row, int col);
    int getcolsize();
    bool start;
private:
    std::map<std::pair<int, int>, int> tiles; 
    int cellsize;
};