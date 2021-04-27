#pragma once
#include "Player.h"
#include "Board.h"
#include "Bot.h"
#include <string>
using namespace std;
class Game
{
	private:
//	Jogador* player1, * player2; // Na casse Jogador devem guardar os tiros dados e os seus barcos/navios
		Player P1, P2;

	public:
		Game();
		virtual ~Game();
		void NewGame();
		void Demo();
		void Save(std::string file,Bot P);
		void Save(std::string file,Player oponent);
		void Read(std::string file,Bot P);

		
};		
	



