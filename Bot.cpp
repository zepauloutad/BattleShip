#include "Bot.h"
#include <iostream>
#include <ctime>
#include<windows.h>
#include "Menu.h"
using namespace std;
Bot::Bot()
{

}

Bot::~Bot()
{
	
}

void Bot::Place(Board* oponent)
{
	Player P;
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
		Save("BotPositions.txt", GetBoard() );
	}
	
}

void Bot::Shoot(Board* oponent)
{
	Player P;
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
			oponent->Draw2(40, 5, GetBoard());
			Stats();
			P.Stats();
		}
		if (shots[i].GetC() == '.')
		{
			cout << i + 1 << " shot.It was a miss!";
			Sleep(500);
			shots[i].SetC('A');
			oponent->SetCell(shots[i]);
			Save("allcordsbot.txt", oponent);
			Sleep(500);
			system("cls");
			oponent->Draw2(40, 5, GetBoard());
			Stats();
			P.Stats();
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
			oponent->Draw2(40, 5, GetBoard());
			Stats();
			P.Stats();
			WinningCondition("allcordsbot.txt", oponent);
		}
	}
}



int Bot::CountShots(Board* oponent)
{
	int count = 0, size = 0, i = 0;
	size++;
	for (i = 0; i < size; i++)
	{
		if (GetShots()->GetC() == 'A' || GetShots()->GetC() == 'T');
		count++;
	}
	return count;
}

void Bot::Save(string file, Board* oponent)
{
	ofstream os;

	os.open(file);
	if (!os)
	{
		cerr << "ERROR: problem in opening the file " << file << '\n';
		exit(0);
	}
	oponent->Save(os);
	os.close();
}

void Bot::Read(string file, Board* oponent)
{
	ifstream is;

	is.open(file);
	if (!is)
	{
		cerr << "ERROR: problem in opening the file " << file << '\n';
		exit(0);
	}
	oponent->Read(is);
	is.close();
}

void Bot::WinningCondition(string file, Board* oponent)
{
	ifstream is;
	int counter = 0;

	is.open(file);
	if (!is)
	{
		cerr << "ERROR: problem in opening the file " << file << '\n';
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

int Bot::CountBoats()
{
	int count = 0, i = 0;
	for (i = 0; i < 4; i++)
	{
		if (MB[i].GetPosition().GetC() == 'O')
		{
			count++;
		}
	}
	return count;
}

void Bot::Stats()
{
	Menu M;
	M.gotoxy(172, 6); cout << char(218);  //canto superior esquerdo
	M.gotoxy(172, 18); cout << char(192);  //canto inferior esquerdo
	M.gotoxy(202, 6); cout << char(191); //canto superior direito
	M.gotoxy(202, 18); cout << char(217); //canto inferior direito

	for (int i = 1; i <= 29; i++)
	{
		M.gotoxy(172 + i, 6); cout << char(196); //linha de cima
		M.gotoxy(172 + i, 18); cout << char(196); // linha de baixo
	}

	for (int j = 1; j <= 11; j++)
	{
		M.gotoxy(172, 6 + j); cout << char(179); //linha da esquerda
		M.gotoxy(202, 6 + j); cout << char(179); //linha da direita
	}

	M.gotoxy(175, 7); cout << "Bot";
	M.gotoxy(175, 10); cout << "Shot : " << "/3";
	M.gotoxy(175, 12); cout << "Submarine : " << CountBoats() << "/4";
	M.gotoxy(175, 14); cout << "Hits: " << "/4";
	M.gotoxy(175, 16); cout << "Game Turn:" << "/100";

	M.gotoxy(0, 35);
}