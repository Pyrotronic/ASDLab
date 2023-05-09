#include <iostream>
#include <string>
using namespace std;

struct info;

typedef info* Pinfo;

struct info
{
	int date[3] = { 0, 0, 0 };
	string product;
	string country;
	int colvo;
};

void input(info&referense)
{

	for (int i = 0; i < 3; i++)
	{
		cin >> referense.date[i];
	}
	cin >> referense.product;
	cin >> referense.country;
	cin >> referense.colvo;
	cout << endl;
}
void print(const info& referense)
{
	for (int i = 0; i < 3; i++)
	{

		cout << referense.date[i] << " ";
	}
	cout << endl;
	cout << referense.product << endl;
	cout << referense.country << endl;
	cout << referense.colvo << endl;
	
}

int main()
{
	info tovar;
	info& rtovar = tovar;
	info* pinfo;
	info mass[3];
	pinfo = &mass[0];
	for (int i = 0; i < 3; i++)
	{
		input(rtovar);
		mass[i] = tovar;
	}
	int vsego = 0; 
	string tovarbl;
	cin >> tovarbl;
	for (int i = 0; i < 3; i++)
	{
		if (mass[i].product == tovarbl)
		{
			cout << mass[i].country << endl;
			vsego += mass[i].colvo;
		}
	}
	cout << vsego;
}