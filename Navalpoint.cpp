//#include "stdafx.h"
#include "Navalpoint.h"
#include <iostream>

using namespace std;

Navalpoint::Navalpoint()
{
	SetX(1);
	SetY('A');
	SetC('.');
}

Navalpoint::Navalpoint(int m_x, char m_y, char m_c)
{
	SetX(m_x);
	SetY(m_y);
	SetC(m_c);
}

Navalpoint::Navalpoint(int m_x, int m_y, char m_c)
{
	SetX(m_x);
	SetY(m_y);
	SetC(m_c);
}

Navalpoint::~Navalpoint()
{

}

bool Navalpoint::SetX(int m_x)
{
	bool status = false;
	while (m_x > 10 || m_x < 0)
	{
		cout << "Write a number from 1 to 10 " <<endl;
		cin >> m_x;
	}
	if (m_x >= 1 && m_x <= 10) 
	{
		x = m_x;
		return true;
	}

	return false;
}

bool Navalpoint::SetY(char m_y)
{
	m_y = toupper(m_y);//Converte caracter para maiuscula,assim o programa passa a funcionar com minusculas
	
	while (m_y >'J')
	{
		cout << "Write a caracter from A to J" <<endl;
		cin >> m_y;
		m_y = toupper(m_y);
	}
	if (m_y >= 'A' && m_y <= 'J') 
	{
		y = m_y;
		return true;
	}

	return false;

}

bool Navalpoint::SetY(int m_y)
{
	if (m_y >= 1 && m_y <= 10) {
		y = char(m_y + 64);
		return true;
	}

	//cout << "Valor de Y invalido" << endl;
	return false;
}

bool Navalpoint::SetC(char m_c)
{
	if (m_c == 'A' || m_c == 'T' || m_c == 'O' || m_c == '.') {
		c = m_c;
		return true;
	}

	//cout << "Valor de C invalido" << endl;
	return false;
}

int Navalpoint::GetIntY()
{
	int aux;
	aux = int(y) - 64;
	return aux;
}

void Navalpoint::Ask2Set(void)
{
	int aux_x = 0;
	char aux_y = ' ';
	char aux_c = '.';

	cout << "Insira um valor para X:";
	do { cin >> aux_x; } while (!SetX(aux_x));

	cout << "Insira um valor para Y:";
	do { cin >> aux_y; } while (!SetY(aux_y));

	cout << "Insira um valor para C:";
	do { cin >> aux_c; } while (!SetC(aux_c));
}

void Navalpoint::Show(void)
{
	cout << '(' << GetX() << ',' << GetY() << ')' << endl;
}

bool Navalpoint::operator == (const Navalpoint ponto) const
{
	if (GetX() == ponto.GetX() && GetY() == ponto.GetY())
		return true;

	return false;
}

bool Navalpoint::operator != (const Navalpoint ponto) const
{
	if (GetX() != ponto.GetX() || GetY() != ponto.GetY())
		return true;

	return false;
}

#pragma region  Read/Save
void Navalpoint::Save(ofstream& os)
{
	os << "(" << GetX() << "," << GetY() << "," << GetC() << ")";
}

void Navalpoint::Read(ifstream& is)
{
	char aux[3];

	is.getline(aux, 3, '(');
	is.getline(aux, 3, ',');
	SetX(atoi(aux));
	is.getline(aux, 3, ',');
	SetY(aux[0]);
	is.getline(aux, 3, ')');
	SetC(aux[0]);
}
#pragma endregion