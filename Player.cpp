#include "player.h"
#include <iostream>
#include "Menu.h"

using namespace std;
Player::Player()
{
	name = "Player";
}

 Player::~Player()
{
}

void Player::Place(Board* T2)
{
	Bot B;
	int i = 0;
	Navalpoint cel, celRight, celLeft, celTop, celTopRight, celTopLeft, celUnder, celUnderRight, celUnderLeft;


	for (i = 0; i < 4; i++)
	{
		MB[i].SetPosition(MB->Boatcreate(i + 1)); //return position 

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
		//                                                                                ***
		//Verifica a celula do barco onde o jogador pretende colocar e as celulas á volta *** desta maneira de forma a verificar se tem um barco já colocado nesse quadrado 3x3,se tiver, pede para colocar uma nova posição
		//                                                                                ***
		while (cel.GetC() == 'O' || celLeft.GetC() == 'O' || celRight.GetC() == 'O' || celTop.GetC() == 'O' || celTopLeft.GetC() == 'O' || celTopRight.GetC() == 'O' || celUnder.GetC() == 'O' || celUnderLeft.GetC() == 'O' || celUnderRight.GetC() == 'O')
		{
			ReadShots("BotPositions.txt",T2);
			system("cls");
			GetBoard()->Draw2(40, 5, T2);
			Stats();
			B.Stats();
			MB[i].SetPosition(MB->Boatcreate(i + 1));
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
		ReadShots("BotPositions.txt", T2);
		GetBoard()->SetCell(MB[i].GetPosition());
		system("cls");
		GetBoard()->Draw2(40, 5, T2);
		Stats();
		B.Stats();
		Save("PlayerPositions.txt", GetBoard());
	}
}

void Player::Shoot(Board* oponent)
{
	Bot B;
	int x = 0, i = 0;
	char y;
	int status;
	ifstream is;

	//Ciclo que permite cada jogador dar tres tiros no tabuleiro do adversario.
	//Tem a funcionalidade de verificar se o jogador já atirou na mesma casa e permite novamente dar o tiro

	for (i = 0; i < 3; i++)
	{
		//Guarda as posições do barcos do Bot sobrepostas pelos tiros do jogador num ficheiro com todas as coordenadas
		//caso o jogador atire num barco o allcords.txt contem o barco atingido
		Read("BotPositions.txt", oponent);
		//O metodo read foi implementado aqui sem o aviso de erro , pois no 1 ciclo o ficheiro não existe e ia acionar o exit 0
		is.open("shots.txt"); 
		oponent->Read(is);
		is.close();
		Save("allcords.txt", oponent);
		cout << "Where do you want to shot?" << endl;
		cin >> x >> y;
		shots[i].SetX(x);
		shots[i].SetY(y);
	    shots[i] = oponent->GetCell(shots[i]);
		while (shots[i].GetC() == 'T' || shots[i].GetC() == 'A')
		{
			Read("BotPositions.txt", oponent);
			is.open("shots.txt");
			oponent->Read(is);
			is.close();
			Save("allcords.txt", oponent);
			cout << "You already shot here, select another target" << endl;
			cin >> x >> y;
			shots[i].SetX(x);
			shots[i].SetY(y);
			shots[i] = oponent->GetCell(shots[i]);
			shots[i].GetC();
			system("cls");
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			GetBoard()->Draw2(40, 5, (oponent));
			Stats();
			B.Stats();
		}
		if (shots[i].GetC() == '.')
		{
			shots[i].SetC('A');
			oponent->SetCell(shots[i]);
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			system("cls");
			GetBoard()->Draw2(40, 5, (oponent));
			Stats();
			B.Stats();
		}
		if (shots[i].GetC() == 'O')
		{
			shots[i].SetC('T');
			oponent->SetCell(shots[i]);
			Save("allcords.txt", oponent);
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			system("cls");
			GetBoard()->Draw2(40, 5, oponent);
			Stats();
			B.Stats();
			WinningCondition("allcords.txt",oponent);
		}
	}
}

//Guarda as coordenadas do tabuleiro num ficheiro
void Player::Save(string file, Board* oponent)
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

//carrega as coordenadas no tabuleiro
void Player::Read(string file, Board* oponent) 
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

//Filtra os barcos do adversário de forma a o adversário não os poder visualizar e carrega as restantes coordenadas no tabuleiro
void Player::ReadShots(string file, Board* oponent)
{
	ifstream is;

	is.open(file);
	if (!is)
	{
		cerr << "ERROR: problem in opening the file " << file << '\n';
		exit(0);
	}
	oponent->ReadShots(is);
	is.close();
}

void Player::WinningCondition(string file, Board* oponent) 
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

		cout <<  GetName() <<" Won"<<endl;
		system("pause");
		exit(0);
	}
	is.close();
}

int Player::CountBoats()
{
	int count = 0,i = 0;
	
	for (i = 0; i < 4; i++) 
	{
		if (MB[i].GetPosition().GetC() == 'O')
		{
			count++;
		}
	}
	return count;
}

int Player::CountShots(Board* oponent)
{
	int count = 0, size = 0, i = 0;
	size++;
	for(i = 0; i < size; i++)
	{
	if (GetShots()->GetC() == 'A' || GetShots()->GetC() == 'T');
		count++;
	}
	return count;
}

void Player::Stats()
{
	Menu M;
	M.gotoxy(5, 6); cout << char(218);  //canto superior esquerdo
	M.gotoxy(5, 18); cout << char(192);  //canto inferior esquerdo
	M.gotoxy(35, 6); cout << char(191); //canto superior direito
	M.gotoxy(35, 18); cout << char(217); //canto inferior direito

	for (int i = 1; i <= 29; i++)
	{
		M.gotoxy(5 + i, 6); cout << char(196); //linha de cima
		M.gotoxy(5 + i, 18); cout << char(196); // linha de baixo
	}

	for (int j = 1; j <= 11; j++)
	{
		M.gotoxy(5, 6 + j); cout << char(179); //linha da esquerda
		M.gotoxy(35, 6 + j); cout << char(179); //linha da direita
	}
	M.gotoxy(8, 7); cout << GetName();
	M.gotoxy(8, 10); cout << "Shot : " << "/3";
	M.gotoxy(8, 12); cout << "Submarine : " << CountBoats() << "/4";
	M.gotoxy(8, 14); cout << "Hits: " << "/4";
	M.gotoxy(8, 16); cout << "Game Turn:" << "/100";

	M.gotoxy(0, 35);
}



