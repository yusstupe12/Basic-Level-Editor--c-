// it's a level editor protoype, why no texures? because of some problems i have as i was implementing it, i have to complete the prototype, thanks:)
#include <iostream>
#include "raylib.h"
#include "grid.h"
#include "Player.h"
#include "Camera.h"
using namespace std;
enum GameMode
{
	EDITOR,
	PLAY
};
class Window {
public:
	float winWidth = 1280, winHeight = 720;
};
Window win;
int main() {
	GameMode mode = EDITOR;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(win.winWidth, win.winHeight, "Window");
	SetTargetFPS(60);
	Grid grid = Grid();
	Player player = Player();
	GameCamera  camera = GameCamera();
	while (!WindowShouldClose()) {
		//update
		if (IsKeyPressed(KEY_ENTER)) {
			mode = PLAY;
			player.velocityY = 0.0f; 
			player.Pos = player.defPos;
		}


		if (IsKeyPressed(KEY_F))
			mode = EDITOR;


		if (mode == EDITOR)
		{
			player.Control(camera.camera);
			player.Pos = player.defPos;
			grid.Update(player,camera.camera);
			camera.Update();
		}

		if (mode == PLAY) {
			player.gravity();
			player.Update();
			player.CheckCollison(grid);
			camera.followingPlayer(player);
		}

		//drawing
		BeginDrawing();
		BeginMode2D(camera.camera);
		ClearBackground(DARKBLUE);
		grid.draw(camera.camera);
		player.Draw();
		EndMode2D();
		const char* modeText = (mode == EDITOR) ? "mode : EDITOR" : "mode : PLAY";
		DrawText(("mode : ", modeText), GetScreenWidth() / 2 + 400, 60, 30, BLACK);
		DrawRectangle(0, 0, win.winWidth / 2 - 230, win.winHeight / 2 - 200, Fade(BLACK, 0.5f));
		DrawText("A/D TO MOVE", 5, 10, 20, YELLOW);
		DrawText("PRESS ENTER TO PLAY MODE", 5, 40, 20, YELLOW);
		DrawText("PRESS F TO EDITOR MODE", 5, 70, 20, YELLOW);
		DrawText("PRESS LEFT CLICK TO ADD TILE", 5, 100, 20, YELLOW);
		DrawText("PRESS RIGHT CLICK TO ERASE TILE", 5, 130, 20, YELLOW);
		EndDrawing();
	}
	CloseWindow();
}