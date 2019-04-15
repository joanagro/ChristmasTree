#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define ROZM 20

int bin2int(char * t);

int main()
{
	printf("Podaj wymiery tablicy (m - liczba wierszy, n - liczba kolumn)\n");
	int m, n;
	int i;
	printf("m: ");
	scanf("%d", &m);
	printf("n: ");
	scanf("%d", &n);

	char **tab = (char**) malloc(m * sizeof(char*));

	for (i = 0; i < m; i++)
	{
		tab[i] = (char*) malloc(n * sizeof(char));
	}

	FILE *plik_odczyt;

	printf("\nPodaj nazwe pliku do odczytu: ");
	char nazwa[ROZM];
	scanf("%s", nazwa);

	if ((plik_odczyt = fopen(nazwa, "r")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku do odczytu.");
		printf("\n\nKoniec programu.\n");
		getchar();
		getchar();
		return 0;
	}
	else
	{
		printf("Udalo sie otworzyc plik do odczytu.");
	}


	for (i = 0; feof(plik_odczyt) == 0; i++)
	{
		if (i == m)
		{
			printf("\n\nConajmniej jeden parametr nie spelnia wymagan programu!");
			printf("\n\nKoniec programu.\n");
			getchar();
			getchar();
			return 0;
		}
		
		if (fscanf(plik_odczyt, "%s", &tab[i][0]) != 1 && i == 0)
		{
			printf("\n\nPlik jest pusty!");
			printf("\n\nKoniec programu.\n");
			getchar();
			getchar();
			return 0;
		}
		if (strlen(tab[i]) > n)
		{
			printf("\n\nConajmniej jeden parametr nie spelnia wymagan programu!");
			printf("\n\nKoniec programu.\n");
			getchar();
			getchar();
			return 0;
		}
		if (tab[i][0] == '0')
		{
			printf("\n\nLiczba zaczynajaca sie od 0 nie zostanie wyswietlona.\nA liczby, ktore sa po niej nie beda wziete pod uwage.\n");
		}
	}

	fclose(plik_odczyt);

	printf("\nLiczby w pliku:\n\n");

	for (i = 0; tab[i][0] == '1'; i++)
	{
		printf("%s\n", tab[i]);
	}
	printf("\n");
	for (i = 0; tab[i][0] == '1'; i++)
	{
		int liczba;
		liczba = bin2int(tab[i]);
		printf("%s to %d\n", tab[i], liczba);
	}


	printf("\nPosortowane liczby w postaci binarnej:\n");
	for (i = 0; tab[i][0] == '1'; i++)//wybiera aktualny wiersz
	{
		for (int j = i + 1; tab[j][0] == '1'; j++)
		{
			if (atoi(tab[i]) < atoi(tab[j]))
			{
				char * pom = tab[i];
				tab[i] = tab[j];
				tab[j] = pom;
			}
		}
	}
	for (i = 0; tab[i][0] == '1'; i++)
		printf("%s\n", tab[i]);

	printf("\nPosortowane liczby w postaci binarnej z dziesietnymi odpowiednikami:\n");
	for (i = 0; tab[i][0] == '1'; i++)
	{
		int liczba;
		liczba = bin2int(tab[i]);
		printf("%s to %d\n", tab[i], liczba);
	}

	printf("\nKoniec programu.\n");
	getchar();
	getchar();
	return 0;
}

int bin2int(char * t)
{
	int potega = 0;
	int liczba = 0;
	int i;

	for (potega = 0; potega < strlen(t); potega++)
		;
	
	for (i = 0; i < strlen(t); i++)
	{
		potega--;
		if(t[i] == '1')
			liczba += pow(2, potega);
		
	}
	return liczba;
}