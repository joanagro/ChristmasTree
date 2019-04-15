#include <stdio.h>

#define ROZM 50
#define T 5

int wiersz(FILE * f, struct para *p);

struct para
{
	char napis[ROZM];
	int liczba;
};

int main()
{
	struct para tab[T];

	FILE *plik_odczyt;
	FILE *plik_zapis;

	printf("Podaj nazwe pliku do odczytu: ");
	char nazwa[ROZM];
	scanf("%s", nazwa);

	printf("Podaj nazwe pliku do zapsiu: ");
	char zapis[ROZM];
	scanf("%s", zapis);

	if ((plik_odczyt = fopen(nazwa, "r")) == NULL)
	{
		printf("\nNie udalo sie otworzyc pliku do odczytu.");
	}
	else
	{
		printf("\nUdalo sie otworzyc plik do odczytu.");
	}

	if ((plik_zapis = fopen(zapis, "w")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku do zapsiu.");
	}
	else
	{
		printf("\nUdalo sie otworzyc plik do zapisu.");
	}

	int i, j;

	for (i = 0; feof(plik_odczyt) == 0; i++)
	{
		wiersz(plik_odczyt, &tab[i]);
		
		for (j = 0; tab[i].napis[j] != '\0'; j++)
		{
			if (tab[i].napis[j] == 'a' || tab[i].napis[j] == 'e' || tab[i].napis[j] == 'i' || tab[i].napis[j] == 'o' || tab[i].napis[j] == 'u' || tab[i].napis[j] == 'y')
				tab[i].napis[j] = '*';
		}
		fprintf(plik_zapis, "%s ", tab[i].napis);
		fprintf(plik_zapis, "%d\n", tab[i].liczba);
	}

	fclose(plik_zapis);
	fclose(plik_odczyt);

	printf("\n\nKoniec programu.\n");
	getchar();
	getchar();
	return 0;
}

int wiersz(FILE * f, struct para *p)
{
	char odczyt1[ROZM];

	if (feof(f) == 0)
	{
		fscanf(f, "%s", odczyt1);
		fscanf(f, "%s", p->napis);
		fscanf(f, "%d", &p->liczba);
		return 0;
	}
	else
		return 1;
}