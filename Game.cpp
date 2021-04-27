#include "Game.h"
#include "Navalpoint.h"
#include <iostream>
#include "Bot.h"
#include "time.h"
#include "windows.h"
using namespace std;

Game::Game()
{

}

Game::~Game()
{
	
}
void Game::Demo()
{
	Player P1;
	Bot P2;
	ifstream is;
	int i = 0;
	int flipcoin;

	srand(time(0));
	flipcoin = rand() % 2;
	//Começa a jogar o jogador
	if (flipcoin == 1) 
	{
		system("cls");
		remove("allcords.txt");
		remove("allcordsbot.txt");
		remove("shots.txt");
		cout << "Moeda a ser atirada" << endl;
		Sleep(1000);
		system("cls");
		cout << "Comeca o jogador";
		Sleep(1000);
		system("cls");
		P1.GetBoard()->Draw2(5, 4, (P2.GetBoard()));
		P1.Place(P2.GetBoard());
		Save("PlayerPositions.txt", P1);
		P2.Place(P1.GetBoard());
		Save("BotPositions.txt", P2);
		while (1) 
		{
			P1.Shoot(P2.GetBoard());
			P2.Shoot(P1.GetBoard());
		}
	}
	//Começa a jogar o bot
	else 
	{
		system("cls");
		remove("allcords.txt");
		remove("allcordsbot.txt");
		remove("shots.txt");
		cout << "Moeda a ser atirada" << endl;
		Sleep(1000);
		system("cls");
		cout << "Comeca o computador";
		Sleep(1000);
		system("cls");
		P1.GetBoard()->Draw2(5, 4, (P2.GetBoard()));
		P2.Place(P1.GetBoard());
		Save("BotPositions.txt", P2);
		P1.Place(P2.GetBoard());
		Save("PlayerPositions.txt", P1);
		while (1)
		{
			P2.Shoot(P1.GetBoard());
			P1.Shoot(P2.GetBoard());
		

		}
	}
}
void Game::NewGame()
{
	
 
}

#pragma region  Read/Save
void Game::Save(string file,Bot P)
{
	ofstream os;
	
	os.open(file);
	if (!os) {
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	P.GetBoard()->Save(os);
	os.close();
}

void Game::Save(string file, Player P)
{
	ofstream os;

	os.open(file);
	if (!os) {
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	P.GetBoard()->Save(os);
	os.close();
}

void Game::Read(string file,Bot P)
{
	ifstream is;

	is.open(file);
	if (!is) 
	{
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	P.GetBoard()->Read(is);
	is.close();
}
#pragma endregions