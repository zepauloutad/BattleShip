#include "player.h"
#include <iostream>
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
			GetBoard()->Draw2(5, 4, T2);
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
		GetBoard()->Draw2(5, 4, T2);
	}
}

void Player::Shoot(Board* oponent)
{
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
		cout << "Indique onde pretende atirar" << endl;
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
			cout << "Zona ja atingida selecione outro alvo" << endl;
			cin >> x >> y;
			shots[i].SetX(x);
			shots[i].SetY(y);
			shots[i] = oponent->GetCell(shots[i]);
			shots[i].GetC();
			std::system("cls");
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			GetBoard()->Draw2(5, 4, (oponent));
		}
		if (shots[i].GetC() == '.')
		{
			shots[i].SetC('A');
			oponent->SetCell(shots[i]);
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			std::system("cls");
			GetBoard()->Draw2(5, 4, (oponent));
		}
		if (shots[i].GetC() == 'O')
		{
			shots[i].SetC('T');
			oponent->SetCell(shots[i]);
			Save("allcords.txt", oponent);
			ReadShots("allcords.txt", oponent);
			Save("shots.txt", oponent);
			std::system("cls");
			GetBoard()->Draw2(5, 4, oponent);
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
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
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
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
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
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
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
		cerr << "ERRO: não é possível abrir o ficheiro " << file << '\n';
		exit(0);
	}
	counter = oponent->ReadBoatsDestroyed(is);
	if (counter == 4) 
	{

		cout << "The Player " << GetName() <<" Won"<<endl;
		system("pause");
		exit(0);
	}
	is.close();
}



