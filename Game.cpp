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
void Game::NewGame()
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
		cout << "Coin being flipped..." << endl;
		Sleep(1000);
		system("cls");
		cout << "Starts " <<P1.GetName();
		Sleep(1000);
		system("cls");
		P1.GetBoard()->Draw2(40, 5, (P2.GetBoard()));
		P1.Place(P2.GetBoard());
		P2.Place(P1.GetBoard());
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
		cout << "Coin being flipped..." << endl;
		Sleep(1000);
		system("cls");
		cout << "Starts the bot";
		Sleep(1000);
		system("cls");
		P1.GetBoard()->Draw2(40, 5, (P2.GetBoard()));
		P2.Place(P1.GetBoard());
		P1.Place(P2.GetBoard());
		while (1)
		{
			P2.Shoot(P1.GetBoard());
			P1.Shoot(P2.GetBoard());
		

		}
	}
}

void Game::LastGame()
{
	//Carrega o tabuleiro do Bot com os tiros do jogador
		ReadBot("shots.txt");
	//Carrega o tabuleiro do jogador com as posições dos barcos
		ReadPlayer("playerpositions.txt");
	// Carrega o tabuleiro do jogador com as jogados dos bot, caso o bot tenha atingido algum barco vai sobrepor a posição do ficheiro anterior
		ReadPlayer("allcordsbot.txt");
	P.GetBoard()->Draw2(40, 5, (B.GetBoard()));
	while (1)
	{
		P.Shoot(B.GetBoard());
		B.Shoot(P.GetBoard());


	}
}

void Game::Info() 
{
	ifstream is;
	char aux[200];
	

	is.open("info.txt");
	if (!is) {
		cerr << "ERROR: Can t open the file info.txt ";
		exit(0);
	}
	
	while (is.good() )
	{
		is.getline(aux,200, '.');
		cout << aux << endl;
	}

	is.close();
	
}

#pragma region  Read/Save
void Game::SaveBot(string file)
{
	ofstream os;
	
	os.open(file);
	if (!os) {
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	B.GetBoard()->Save(os);
	os.close();
}

void Game::SavePlayer(string file)
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

void Game::ReadBot(string file)
{
	ifstream is;

	is.open(file);
	if (!is) 
	{
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	B.GetBoard()->Read(is);
	is.close();
}

void Game::ReadPlayer(string file)
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

/*
void Game::ReadBotShots(string file)
{
	ifstream is;

	is.open(file);
	if (!is)
	{
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	B.GetBoard()->ReadShots(is);
	is.close();
}
*/
#pragma endregions