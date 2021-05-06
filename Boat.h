#pragma once
#include "Navalpoint.h"
class Boat
{
	private:
		Navalpoint position;
	public:
		Boat();
		virtual ~Boat();
		Navalpoint Boatcreate(int num);
		Navalpoint BoatcreateRandom();
		void SetPosition(Navalpoint _position) { position = _position; }
		Navalpoint GetPosition() { return position; }
};


