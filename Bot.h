#pragma once
#include "Board.h" 
#include "Boat.h"
#include "Player.h"

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
		Boat* GetBoat() { return MB; }
		Navalpoint* GetShots() { return shots; }
		int CountBoats();
		int CountShots(Board* oponent);
		void Save(std::string file, Board* oponent);
		void Read(std::string file, Board* oponent);
		void Place(Board* T2);
		void Shoot(Board* Oponent);
		void WinningCondition(std::string file, Board* oponent);
		void Stats();
		

};
