#include "Boat.h"
#include <iostream>

using namespace std;

Boat::Boat()
{
}

Boat::~Boat()
{
}

Navalpoint Boat::Boatcreate(int num)
{
	int i = 0,x = 0;
	char y;
	for (i = 0; i < 4; i++) 
	{
		cout << "Choose the position for the " << num << " submarine" << endl;
		cin >> x >> y;

		position.SetX(x);
		position.SetY(y);
		position.SetC('O');
		return position;
	}

}

Navalpoint Boat::BoatcreateRandom() 
{
	int i = 0, x = 0, y = 0;
	srand(time(0));
	for (i = 0; i < 4; i++)
	{
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		position.SetX(x);
		position.SetY(y);
		position.SetC('O');
		return position;
	}
}


