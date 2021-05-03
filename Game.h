#pragma once
#include "Player.h"
#include "Board.h"
#include "Bot.h"
#include <string>
using namespace std;
class Game
{
	private:
		Player P;
		Bot B;
	public:
		Game();
		virtual ~Game();
		void NewGame();
		void Demo();
		void LastGame();
		void Info();
		void SavePlayer(std::string file);
		void SaveBot(std::string file);
		void ReadPlayer(std::string file);
		void ReadBot(std::string file);
		//void ReadBotShots(std::string file);
};		
	



