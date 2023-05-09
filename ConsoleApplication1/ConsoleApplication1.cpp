#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include<fstream>
#include <string.h>
#include<Windows.h>

using namespace std;
int main()
{
	typedef struct _tovar
	{
		char name[10];
		char strana[10];
		int kolvo;

	} tovar;

	FILE* f = fopen("tovar.txt", "r");

	tovar  item[5];

	if (f == NULL)
	{
		cout << "File not found";

	}


	char poisk[10];

	cout << "Chto isem :";
	cin >> poisk;



	int templ = 0;

	int i = -1;
	while (!feof(f)) {
		i++;
		fscanf(f, "%s%d%s", item[i].name, &item[i].kolvo, item[i].strana);
	}

	for (int j = 0; j <= i; j++) {
		if (item[j].name == poisk) {

			printf("Srtana:\n%s postavlyaet %s v kolve %d shtuk.", item[i].name, item[i].strana, item[i].kolvo);
		}
	}
	;
	fclose(f);

	getch();

}