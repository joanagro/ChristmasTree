#include <stdio.h>

#define SIZE 5

int main()
{
	printf("autor: Joanna Grodzicka\n\n");

	printf("Tablica A o wymiarach %dx%d:\n", SIZE, SIZE);

	//wypelnienie tablicy A literami alfabetu
	char A[SIZE][SIZE] = { {'a','b','c','d','e'}, {'f','g','h','i','j'}, {'k','l','m','n','o'}, {'p','r','s','t', 'u'}, {'v','w','x','y', 'z'} };
	//stworzenie tablicy przechowujacej wskazniki
	char *B[SIZE*SIZE];

	char *B2[SIZE*SIZE];

	int i, j, k;

	//wyswietlenie tablicy A
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%c\t", A[j][i]);
		}
		printf("\n");
	}

	for (i = 0; i < (SIZE*SIZE); i++)
	{
		B[i] = NULL;
		B2[i] = NULL;
	}

	printf("\nPodaj ciag znakow wykorzystujac litery z tablicy A, nie dluzszy niz %d:\n", SIZE*SIZE);

	char pom[SIZE*SIZE];
	int ile_znakow = 0;

	scanf_s("%s", pom, SIZE*SIZE);
	//printf("%s", pom); //wyswietlenie wyrazu podanego przez uzytkownika, sprawdzenie czy wyraz zostal poprawnie zapisany

	//przypisanie wskaznikow
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			for (k = 0; k < (SIZE*SIZE); k++)
			{
				if (pom[k] == A[i][j])
				{
					B[k] = &A[i][j];
					ile_znakow++;
				}
			}
		}
	}

	//wyswietlenie slowa za pomoca wskaznikow
	printf("\nNapis podany przez uzytkownika z wykorzystaniem tablicy B:\n");
	for (i = 0; i < ile_znakow; i++)
		printf("%c", *B[i]);
	printf("\n");

	//SZYFROWANIE A
	for (i = (SIZE - 1); i >= 0; i--)
	{
		for (j = (SIZE - 1); (j - 1) >= 0; j--)
		{
			char POM[SIZE];
			POM[j] = A[i][j];
			A[i][j] = A[i][j - 1];
			A[i][j - 1] = POM[j];
		}
	}

	//wyswietlenie zaszyfrowanej tab.A
	/*printf("\n\n");
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%c\t", A[j][i]);
		}
		printf("\n");
	}*/

	//wyswietlenie slowa za pomoca wskaznikow po zaszyfrowaniu
	printf("\nNapis podany przez uzytkownika z wykorzystaniem tablicy B po zaszyfrowaniu:\n");
	for (i = 0; i < ile_znakow; i++)
		printf("%c", *B[i]);
	printf("\n");

	//PRZYPISANIE DO B2 z zaszyfrowanego tekstu, odszyfrowane litery

	ile_znakow = 0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			for (k = 0; k < (SIZE*SIZE); k++)
			{
				if (pom[k] == A[i][j])//przeszukuje A niezaleznie od innych rzeczy, szuka po literach i przypisuje adresy
				{
					B2[k] = &A[i][j];
					ile_znakow++;
				}
			}
		}
	}
	printf("\nNapis podany przez uzytkownika z wykorzystaniem tablicy B2:\n");
	for (i = 0; i < ile_znakow; i++)
		printf("%c", *B2[i]);
	printf("\n");

	//ODSZYFROWANIE A
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; (j + 1) < SIZE; j++)
		{
			char POM[SIZE];
			POM[j] = A[i][j];
			A[i][j] = A[i][j + 1];
			A[i][j + 1] = POM[j];
		}
	}

	//wyswietlenie odszyfrowanej tab.A
	/*printf("\n\n");
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%c\t", A[j][i]);
		}
		printf("\n");
	}*/

	//wyswietlenie slowa za pomoca wskaznikow po odszyfrowaniu
	printf("\nNapis podany przez uzytkownika z wykorzystaniem tablicy B po odszyfrowaniu:\n");
	for (i = 0; i < ile_znakow; i++)
		printf("%c", *B[i]);

	//Wyswietlenie slowa od tylu
	/*char **C[SIZE*SIZE];
	
	i = 0;
	for (j = (ile_znakow - 1); j >= 0; j--)
	{
		C[i] = &B[j];
		i++;
	}

	for (j = ile_znakow; j < (SIZE*SIZE); j++)
	{
		C[i] = &B[j];
		i++;
	}

	printf("\n\nWyswietlenie napisu za pomoca tablicy C (slowo od tylu):\n");
	for (i = 0; i < ile_znakow; i++)
	{
		printf("%c", **C[i]);
	}*/

	//Wyswietlenie samych samoglosek
	//char **C[SIZE*SIZE];

	//i = 0;
	//int ile_sam = 0;//ile samoglosek
	//for (j = 0; j < ile_znakow; j++)
	//{
	//	if (*B[j] == 'a' || *B[j] == 'e' || *B[j] == 'i' || *B[j] == 'o' || *B[j] == 'u' || *B[j] == 'y')
	//	{
	//		C[i] = &B[j];
	//		ile_sam++;
	//		i++;
	//	}
	//}
	//for (i, j = ile_znakow; i < (SIZE*SIZE); i++)
	//{
	//	C[i] = &B[j];
	//}
	////lub
	///*for (i; i < (SIZE*SIZE); i++)
	//{
	//	C[i] = NULL;
	//}*/

	//printf("\n\nWyswietlenie napisu za pomoca tablicy C (tylko samogloski):\n");
	//for (i = 0; i < ile_sam; i++)
	//{
	//	printf("%c", **C[i]);
	//}

	//Wyswietlenie slowa z podwojnymi samogloskami
	//char **C[SIZE*SIZE*2];

	//i = 0;
	//int ile_sam = 0;//ile samoglosek
	//for (j = 0; j < ile_znakow; j++)
	//{
	//	
	//	if (*B[j] == 'a' || *B[j] == 'e' || *B[j] == 'i' || *B[j] == 'o' || *B[j] == 'u' || *B[j] == 'y')
	//	{
	//		C[i] = &B[j];
	//		i++;
	//		C[i] = &B[j];
	//		i++;
	//		ile_sam++;
	//	}
	//	else
	//	{
	//		C[i] = &B[j];
	//		i++;
	//	}
	//}

	//for (i, j = (ile_znakow+ile_sam); i < (SIZE*SIZE*2); i++)
	//{
	//	C[i] = &B[j];
	//}
	////lub
	///*for (i; i < (SIZE*SIZE*2); i++)
	//{
	//	C[i] = NULL;
	//}*/

	//printf("\n\nWyswietlenie napisu za pomoca tablicy C (podwojne samogloski):\n");
	//for (i = 0; i < (ile_znakow + ile_sam); i++)
	//{
	//	printf("%c", **C[i]);
	//}

	printf("\n\nKoniec programu.\n");
	system("pause");
	return 0;
}