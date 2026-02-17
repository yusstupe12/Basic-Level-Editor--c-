#pragma once

class Grid {
public:
	Grid();
	void initialize();
	void draw();
	void Update();
	bool istilitedSolid(int row, int col);
	int getcolsize();
	int getrows();
	int getcols();
	bool start;
	int grid[24][43];
private:
	int NumRows;
	int NumCols;
	int cellsize;
};
