//// ChristmasTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	printf("Autor: Joanna Grodzicka\n\n");
	printf("Porgram rysuje choinke.\n");
	printf("Podaj liczbe rzedow: ");

	int rzedy;//liczba rzedow; podawana przez uzytkownikow

	while (scanf_s("%d", &rzedy) != 1 || rzedy < 0 || getchar() != '\n')
	{
		printf("Blad. Podaj ponownie liczbe rzedow: ");
		while (getchar() != '\n')
			;
	}

	int i;//ile razy ma sie wykonac petla w zaleznosci od liczby rzedow
	int j;//ile razy powtorzyc wypisywanie gwiazdek lub |
	int m = 0;//ile gwiazdek wypisac
	char spacja = ' ';
	int k;//przejscie do kolejnego wiersza; wypisanie spacji ma sie wykonac dla kazdego wiersza
	int a = rzedy;

	for (i = 1; i <= rzedy; i++)
	{
		printf("\n");

		for (k = 1; k <= a; k++)
		{
			printf("%c", spacja);
		}
		for (j = 0; j <= m; j++)
		{
			printf("*");
		}
		m += 2;
		a--;
	}
	printf("\n");
	a = rzedy / 2;
	if (rzedy)
	{
		for (k = 0; k <= a; k++)
		{
			printf("%c", spacja);
		}
		for (j = 1; j <= 2 * a - 1; j++)
		{
			printf("|");
		}
	}

	printf("\n\nKoniec programu.\n");
	return 0;
}