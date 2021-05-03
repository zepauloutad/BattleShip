#pragma once
#include "Navalpoint.h"

class Board
{
private:
	int DimX;
	int DimY;
	Navalpoint M[10][10];

public:
	Board();
	Board(int mdx, int mdy);
	~Board();

	void SetDimX(int mdx) { DimX = mdx; }
	void SetDimY(int mdy) { DimY = mdy; }
	int GetDimX() { return DimX; }
	int GetDimY() { return DimY; }

	void SetCell(int lin, int col, char m_c);
	void SetCell(Navalpoint P) { M[P.GetX() - 1][P.GetIntY() - 1] = P; }
	Navalpoint GetCell(int lin, int col) { return M[lin - 1][col - 1]; }
	Navalpoint GetCell(Navalpoint P) { return M[P.GetX() - 1][P.GetIntY() - 1]; }
	Navalpoint GetCellRight(Navalpoint P) { return M[P.GetX() - 1][P.GetIntY()]; }
	Navalpoint GetCellLeft(Navalpoint P) { return M[P.GetX() - 1][P.GetIntY() - 2]; }
	Navalpoint GetCellTop(Navalpoint P) { return M[P.GetX()][P.GetIntY() - 1]; }
	Navalpoint GetCellTopLeft(Navalpoint P) { return M[P.GetX()][P.GetIntY() - 2]; }
	Navalpoint GetCellTopRight(Navalpoint P) { return M[P.GetX()][P.GetIntY()]; }
	Navalpoint GetCellUnder(Navalpoint P) { return M[P.GetX()- 2][P.GetIntY() - 1]; }
	Navalpoint GetCellUnderLeft(Navalpoint P) { return M[P.GetX() - 2][P.GetIntY() - 2]; }
	Navalpoint GetCellUnderRight(Navalpoint P) { return M[P.GetX() - 2][P.GetIntY()]; }
	

	void SimbolBoxListDraw();
	void DrawFirstLine(int x0, int dxcel);
	void DrawMiddleLine(int x0, int dxcel);
	void DrawEndLine(int x0, int dxcel);
	void DrawDataLine(int line, int x0, int dxcel);
	void Draw(int x0, int y0);
	void Draw2(int x0, int y0, Board *T);
	void Save(std::ofstream& os);
	void Read(std::ifstream& is);
	void ReadShots(std::ifstream& is);
	int ReadBoatsDestroyed(std::ifstream& is);
};

