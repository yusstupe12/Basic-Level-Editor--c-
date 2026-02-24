
#include"raylib.h"
#include "grid.h"
class Player {
public:
	Player();
	float speed;
	Vector2 Pos;
	Vector2 defPos;
	Vector2 mousepos;
	float velocityY;
	float Raduis;
	bool dragging;
	Vector2 dragffest;
	Rectangle GetRect();
	void CheckCollison(Grid& grid);
	void Update();
	void Draw();
	void Control(Camera2D& camera);
	void gravity();
};
