#pragma once
#include "Board.h" 
#include "Navalpoint.h"
#include "Boat.h"
using namespace std;
class Bot
{
	private:
		Board T;
		Boat MB[10];
		Navalpoint shots[100];
	public:
		Bot();
		virtual ~Bot();
		Board* GetBoard() { return &T; }
		Boat* Getboat() { return MB; }
		Board* getBoard() { return &T; }
		void Save(std::string file, Board* oponent);
		void Place(Board* T2);
		void Shoot(Board* Oponent);
		void WinningCondition(std::string file, Board* oponent);
};
