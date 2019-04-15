#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX 20

void zapis(FILE * plik1);

int main(int argc, char ** argv)
{
	FILE * plik1, *plik2;
	struct tm *data;
	time_t info;

	if ((plik1 = fopen("log.txt", "a")) == NULL)
	{
		zapis(plik1);
		fprintf(plik1, "Uruchomienie programu\n");
		printf("Nie udalo sie otworzyc pliku");
		zapis(plik1);
		fprintf(plik1, "Nie udalo sie otworzyc pliku\n");
		printf("\n\nKoniec programu.\n");
		system("pause");
		zapis(plik1);
		fprintf(plik1, "Zakoncznie programu\n");
		fclose(plik1);

		return 0;
	}
	
	zapis(plik1);
	fprintf(plik1, "Uruchomienie programu\n");

	char odp;

	do
	{
		char nick[20];
		char napis[20] = "gra-";
		int czy_ok = 0;

		printf("Witaj w grze!\n\n");
		zapis(plik1);
		fprintf(plik1, "Uruchomienie gry\n");

		printf("W tej grze musisz stwierdzic czy z 3 liczb wylosowanych przez program mozna utowrzyc trojkat.\n\n");
		
		printf("Podaj swoj nick: ");
		scanf("%s", nick);
		zapis(plik1);
		fprintf(plik1, "Gracz %s\n", nick);
		
		strcat(napis, nick);
		strcat(napis, ".txt");

		if ((plik2 = fopen(napis, "a")) == NULL)
		{
			
			printf("Nie udalo sie otworzyc pliku");
			zapis(plik1);
			fprintf(plik1, "Nie udalo sie otworzyc pliku o nazwie %s\n", napis);
		}

		printf("Jak juz sie znamy, podaj liczbe trojek: ");
		float liczba;
		while (scanf("%f", &liczba) != 1 || getchar() != '\n')
		{
			zapis(plik1);
			fprintf(plik1, "Bledna odpowiedz\n");
			printf("Blad! Sprobuj ponownie\n");
			printf("Podaj liczbe trojek: ");
			while (getchar() != '\n')
				;
		}

		if (liczba - (long int)liczba != 0 || liczba < 0)
		{
			printf("To nie jest liczba naturalna! ");
			zapis(plik1);
			fprintf(plik1, "Bledna liczba: %g\n", liczba);
			printf("Sprobuj ponownie.\nPodaj niewielka liczbe naturalna: ");
			while (scanf("%f", &liczba) != 0 && (liczba - (long int)liczba != 0))
			{
				printf("To nie jest liczba naturalna! ");
				zapis(plik1);
				fprintf(plik1, "Bledna liczba: %g\n", liczba);
				printf("Sprobuj ponownie.\nPodaj niewielka liczbe naturalna: ");
				while (getchar() != '\n')
					;
			}
		}
		if (liczba - (long int)liczba == 0)
		{
			printf("Dobrze, to jest liczba naturalna");
			if (liczba > 10)
			{
				printf("\nZa duza liczba dla tego programu. To koniec.");
				zapis(plik1);
				fprintf(plik1, "Za duza liczba: %g\n", liczba);
				printf("\n\nKoniec programu.\n");
				system("pause");
				zapis(plik1);
				fprintf(plik1, "Zakonczenie programu\n");
				return 0;
			}
		}
		if (liczba == 0)
		{
			printf("Na zerze nie podzialamy.\n");
			printf("\n\nKoniec programu.\n");
			system("pause");
			zapis(plik1);
			fprintf(plik1, "Zakonczenie programu\n");
			return 0;
		}


		srand(time(NULL));

		

		printf("\n\nWylosowane liczby:\n");
		float l1, l2, l3;

		for (int i = 0; i < liczba; i++)
		{
			l1 = rand() % 20 + 1;
			l2 = rand() % 20 + 1;
			l3 = rand() % 20 + 1;
			printf("%4.2lf %4.2lf %4.2lf\n", l1, l2, l3);
			fprintf(plik2, "Wylosowane liczby: %4.2lf %4.2lf %4.2lf\n", l1, l2, l3);
			printf("Twoja odpowiedz (t - tak lub n - nie): ");
			
			scanf("%c", &odp);

			while (odp != 't' && odp != 'n')
			{
				zapis(plik1);
				fprintf(plik1, "Bledna odpowiedz\n");
				fprintf(plik2, "Odpowiedz: %c 0\n", odp);
				printf("Blad! Sprobuj ponownie.\n");
				printf("Twoja odpowiedz (t - tak lub n - nie): ");
				
				while (getchar() != '\n')
					;
				scanf("%c", &odp);
			}
			//else
				fprintf(plik2, "Odpowiedz: %c", odp);

			if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1 && odp == 't')
			{
				czy_ok++;
				fprintf(plik2, " 1\n");
			}
			else if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1 && odp == 'n')
			{
				zapis(plik1);
				fprintf(plik1, "Bledna odpowiedz\n");
				fprintf(plik2, " 0\n");
			}
			else if (l1 + l2 <= l3 || l1 + l3 <= l2 || l2 + l3 <= l1 && odp == 't')
			{
				zapis(plik1);
				fprintf(plik1, "Bledna odpowiedz\n");
				fprintf(plik2, " 0\n");
			}
			else if (l1 + l2 <= l3 || l1 + l3 <= l2 || l2 + l3 <= l1 && odp == 'n')
			{
				fprintf(plik2, " 1\n");
				czy_ok++;
			}
			while (getchar() != '\n')
				;
			printf("\n");
		}

		
		fprintf(plik2, "Wynik: %d\n", czy_ok);

		
		fclose(plik2);
		printf("Swoje wyniki sprawdzisz w pliku %s\n", napis);

		printf("\nCzy chcesz zagrac jeszcze raz? (t - tak, n - nie): ");
		scanf("%c", &odp);
		while (odp != 't' && odp != 'n')
		{
			zapis(plik1);
			fprintf(plik1, "Bledna odpowiedz\n");
			printf("Blad! Sprobuj ponownie.\n");
			printf("Twoja odpowiedz (t - tak lub n - nie): ");
			scanf("%c", &odp);
			while (getchar() != '\n')
				;
		}


	} while (odp == 't');

	printf("Dziekujemy za gre.");
	
	

	printf("\n\nKoniec programu.\n");
	system("pause");
	zapis(plik1);
	fprintf(plik1, "Zakoncznie programu\n");
	fclose(plik1);
	
	return 0;
}

void zapis(FILE * plik1)
{
	struct tm *data;
	time_t info;
	char buffer[80];
	time(&info);
	data = localtime(&info);
	strftime(buffer, 80, "%Y.%m.%d %H:%M:%S", data);
	fprintf(plik1, "%s ", buffer);
}