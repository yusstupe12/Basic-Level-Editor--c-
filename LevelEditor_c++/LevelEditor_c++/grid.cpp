#include "grid.h"
#include <iostream>
#include "raylib.h"
using namespace std;
Grid::Grid() {
	NumRows = 24;
	NumCols = 43;
	cellsize = 40;
	initialize();
}
void Grid::initialize() {
	for (int rows = 0; rows < NumRows; rows++) {
		for (int col = 0; col < NumCols; col++)
		{
			grid[rows][col] = 0;
		}
		cout << endl;
	}
}
void Grid::draw() {
	for (int rows = 0; rows < NumRows; rows++) {
		for (int col = 0; col < NumCols; col++) {

			Color tileColor = (grid[rows][col] == 1) ? LIGHTGRAY : DARKGRAY;
			DrawRectangle(col * cellsize, rows * cellsize, cellsize, cellsize, tileColor);
			if(start)
				DrawRectangleLines(col * cellsize, rows * cellsize, cellsize, cellsize, BLACK);
			
		}
	
	}
}
void Grid::Update() {
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();

	int col = mouseX / cellsize;
	int row = mouseY / cellsize;

	if (row >= 0 && row < NumRows &&
		col >= 0 && col < NumCols)
	{
		// adding tiles
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			grid[row][col] = 1;
			cout << "working";
		}

		// earsing tiles
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			grid[row][col] = 0;
			cout << "removing";
		}
	}
}
bool Grid::istilitedSolid(int row, int col)
{
	return grid[row][col] == 1;
}
int Grid::getcolsize() { return{ cellsize }; }
int Grid::getrows() { return{ NumRows }; }
int Grid::getcols() { return{ NumCols }; }