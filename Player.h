#pragma once
#include "Bot.h"

using namespace std;

class Player
{
private:
	string name;
	Board T;
	Boat MB[4];
	Navalpoint shots[100];
public:
	Player();
	virtual ~Player();
	Board* GetBoard() { return &T; }
	void SetName(string _name) { name = _name; }
	string GetName() { return name; }
	Boat* GetBoat() { return MB; }
	Navalpoint* GetShots() { return shots; }
	int CountBoats();
	int CountShots(Board* oponent);
	void Place(Board *T2);
	void Shoot(Board* Oponent);
	void Save(std::string file, Board* oponent);
	void ReadShots(std::string file, Board* oponent);
	void Read(std::string file, Board* oponent);
	void WinningCondition(std::string file, Board* oponent);
	void Stats();
    
};
