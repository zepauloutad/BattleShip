#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "Game.h"
using namespace std;

const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;


class Menu
{
	private:
		Game battleShip;
	public:
		void gotoxy(int x, int y);
		void M_Menu(void);
		void SimbolBoxListDraw();
		void Boat_1();
		void Boat_2();
		void clearScreen(int characterLength);
		void changeColour(int colour);
		void showBlinkColoour();
		void C_ascii();
		void C_ascii_2();
		void intro();
		void Mostar_Intro();
		void loading_s();
		void New_Game_s();
		void Show_New_Game_s();
};



