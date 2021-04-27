#include "Bot.h"
#include <iostream>
#include <ctime>
#include<windows.h>
using namespace std;
Bot::Bot()
{
}

Bot::~Bot()
{
}

void Bot::Place(Board* oponent)
{
	int i = 0;
	Navalpoint cel, celRight, celLeft, celTop, celTopRight, celTopLeft, celUnder, celUnderRight, celUnderLeft;

	cout << "Computer placing boats" << endl;
	
	for (i = 0; i < 4; i++)
	{
		MB[i].SetPosition(MB->BoatcreateRandom());
		//Regra para colocar os submarinos
		celTop = GetBoard()->GetCellTop(MB[i].GetPosition());
		celTopLeft = GetBoard()->GetCellTopLeft(MB[i].GetPosition());
		celTopRight = GetBoard()->GetCellTopRight(MB[i].GetPosition());
		cel = GetBoard()->GetCell(MB[i].GetPosition());
		celLeft = GetBoard()->GetCellLeft(MB[i].GetPosition());
		celRight = GetBoard()->GetCellRight(MB[i].GetPosition());
		celUnder = GetBoard()->GetCellUnder(MB[i].GetPosition());
		celUnderLeft = GetBoard()->GetCellUnderLeft(MB[i].GetPosition());
		celUnderRight = GetBoard()->GetCellUnderRight(MB[i].GetPosition());
		while (cel.GetC() == 'O' || celLeft.GetC() == 'O' || celRight.GetC() == 'O' || celTop.GetC() == 'O' || celTopLeft.GetC() == 'O' || celTopRight.GetC() == 'O' || celUnder.GetC() == 'O' || celUnderLeft.GetC() == 'O' || celUnderRight.GetC() == 'O')
		{
			MB[i].SetPosition(MB->BoatcreateRandom());
			celTop = GetBoard()->GetCellTop(MB[i].GetPosition());
			celTopLeft = GetBoard()->GetCellTopLeft(MB[i].GetPosition());
			celTopRight = GetBoard()->GetCellTopRight(MB[i].GetPosition());
			cel = GetBoard()->GetCell(MB[i].GetPosition());
			celLeft = GetBoard()->GetCellLeft(MB[i].GetPosition());
			celRight = GetBoard()->GetCellRight(MB[i].GetPosition());
			celUnder = GetBoard()->GetCellUnder(MB[i].GetPosition());
			celUnderLeft = GetBoard()->GetCellUnderLeft(MB[i].GetPosition());
			celUnderRight = GetBoard()->GetCellUnderRight(MB[i].GetPosition());
		}
		//---------------------------------------------------------------
		GetBoard()->SetCell(MB[i].GetPosition());
	}
	
}

void Bot::Shoot(Board* oponent)
{
	int x = 0, y = 0, i = 0;

	srand(time(0));
	
	cout << "Computer is shooting" <<endl;
	Sleep(500);
	for (i = 0; i < 3; i++)
	{
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		shots[i].SetX(x);
		shots[i].SetY(y);
		shots[i] = oponent->GetCell(shots[i]);
		while (shots[i].GetC() == 'T' || shots[i].GetC() == 'A')
		{
			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			shots[i].SetX(x);
			shots[i].SetY(y);
			shots[i] = oponent->GetCell(shots[i]);
			shots[i].GetC();
			Sleep(500);
			system("cls");
			oponent->Draw2(5, 4, GetBoard());
		}
		if (shots[i].GetC() == '.')
		{
			cout << i + 1 << " shot.It was a miss!";
			Sleep(500);
			shots[i].SetC('A');
			oponent->SetCell(shots[i]);
			Sleep(500);
			system("cls");
			oponent->Draw2(5, 4, GetBoard());
		}
		if (shots[i].GetC() == 'O')
		{
			cout << i + 1 << "shot.It was a hit!!!";
			Sleep(500);
			shots[i].SetC('T');
			oponent->SetCell(shots[i]);
			Save("allcordsbot.txt", oponent);
			Sleep(500);
			system("cls");
			oponent->Draw2(5, 4, GetBoard());
			WinningCondition("allcordsbot.txt", oponent);
		}
	}
}

void Bot::Save(string file, Board* oponent)
{
	ofstream os;

	os.open(file);
	if (!os)
	{
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	oponent->Save(os);
	os.close();
}

void Bot::WinningCondition(string file, Board* oponent)
{
	ifstream is;
	int counter = 0;

	is.open(file);
	if (!is)
	{
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	counter = oponent->ReadBoatsDestroyed(is);
	if (counter == 4)
	{

		cout << "The Computer  Won" << endl;
		system("pause");
		exit(0);
	}
	is.close();
}
