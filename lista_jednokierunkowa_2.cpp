#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
};

struct pom {
	struct pomiar *head1;
	struct pomiar *head2;
	struct pomiar *head3;
	struct pomiar *head4;
};

struct pomiar * fun1(char nazwa[]);
void fun2(struct pomiar *head);
struct pom fun3(struct pomiar *head);
struct pomiar *fun4(struct pomiar *head);

int main()
{
	printf("Podaj nazwe pliku, z ktorego maja zostac odczytane dane: ");
	char nazwa[20];
	scanf("%s", nazwa);
	struct pomiar * head;
	head = fun1(nazwa);
	printf("\nCala lista\n\n");
	fun2(head);

	struct pom glowy;
	glowy = fun3(head);

	free(head);

	printf("\nLista pierwsza\n");
	fun2(glowy.head1);
	printf("Lista druga\n");
	fun2(glowy.head2);
	printf("Lista trzecia\n");
	fun2(glowy.head3);
	printf("Lista czwarta\n");
	fun2(glowy.head4);

	printf("(f4)Lista pierwsza\n");
	glowy.head1 = fun4(glowy.head1);
	printf("\n(f4)Lista druga\n");
	glowy.head2 = fun4(glowy.head2);
	printf("\n(f4)Lista trzecia\n");
	glowy.head3  = fun4(glowy.head3);
	printf("\n(f4)Lista czwarta\n");
	glowy.head4 = fun4(glowy.head4);

	printf("\nLista pierwsza\n");
	fun2(glowy.head1);
	printf("Lista druga\n");
	fun2(glowy.head2);
	printf("Lista trzecia\n");
	fun2(glowy.head3);
	printf("Lista czwarta\n");
	fun2(glowy.head4);


	free(glowy.head1);
	free(glowy.head2);
	free(glowy.head3);
	free(glowy.head4);

	printf("\n\nKoniec programu.\n");
	getchar();
	getchar();
	return 0;
}

struct pomiar * fun1(char nazwa[])
{
	struct pomiar *wsk = NULL;
	struct pomiar *head = NULL;

	FILE * plik;

	if ((plik = fopen(nazwa, "r")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		getchar();
		exit(0);
	}
	else
		printf("Udalo sie otworzyc plik.\n");


	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;

	if (fscanf(plik, "%d%d%s%lf", &nr_pomiaru, &nr_czujnika, data_i_czas, &temp) == EOF)
	{
		printf("Plik jest pusty.\n");
		return NULL;
	}

	while (!feof(plik))
	{
		if (head == NULL)
		{
			head = wsk = (struct pomiar *)malloc(sizeof(struct pomiar));
		}
		else
		{
			wsk->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
			wsk = wsk->nast;
		}
		wsk->nr_pomiaru = nr_pomiaru;
		wsk->nr_czujnika = nr_czujnika;
		strcpy(wsk->data_i_czas, data_i_czas);
		wsk->temp = temp;
		wsk->nast = NULL;
		fscanf(plik, "%d%d%s%lf", &nr_pomiaru, &nr_czujnika, data_i_czas, &temp);
	}

	fclose(plik);

	return head;
}

void fun2(struct pomiar *head)
{
	struct pomiar *wsk = head;
	int ile = 0;

	while (wsk != NULL)
	{
		ile++;
		wsk = wsk->nast;
	}
	printf("Ile rekordow: %d\n", ile);
	printf("Pierwszy rekord:\n%d %d %s %.2lf\n", head->nr_pomiaru, head->nr_czujnika, head->data_i_czas, head->temp);

	wsk = head;
	for (int i = 0; i < (ile-1); i++)
		wsk = wsk->nast;
	printf("Ostatni rekord:\n%5d %d %s %.2lf\n\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
}

struct pom fun3(struct pomiar *head)
{
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;

	struct pomiar *wsk = NULL;
	struct pomiar *head1 = NULL;
	struct pomiar *head2 = NULL;
	struct pomiar *head3 = NULL;
	struct pomiar *head4 = NULL;

	struct pomiar *wsk1 = NULL, *wsk2 = NULL, *wsk3 = NULL, *wsk4 = NULL;

	struct pom glowy;

	wsk = head;

	while (wsk != NULL)
	{
		if (wsk->nr_czujnika == 1)
		{
			if (head1 == NULL)
			{
				head1 = wsk1 = (struct pomiar *)malloc(sizeof(struct pomiar));
			}
			else
			{
				wsk1->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
				wsk1 = wsk1->nast;
			}
			wsk1->nr_pomiaru = wsk->nr_pomiaru;
			wsk1->nr_czujnika = wsk->nr_czujnika;
			strcpy(wsk1->data_i_czas, wsk->data_i_czas);
			wsk1->temp = wsk->temp;
			wsk1->nast = NULL;
			//printf("%5d %d %s %.2lf\n", wsk1->nr_pomiaru, wsk1->nr_czujnika, wsk1->data_i_czas, wsk1->temp);
		}
		else if (wsk->nr_czujnika == 2)
		{
			if (head2 == NULL)
			{
				head2 = wsk2 = (struct pomiar *)malloc(sizeof(struct pomiar));
			}
			else
			{
				wsk2->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
				wsk2 = wsk2->nast;
			}
			wsk2->nr_pomiaru = wsk->nr_pomiaru;
			wsk2->nr_czujnika = wsk->nr_czujnika;
			strcpy(wsk2->data_i_czas, wsk->data_i_czas);
			wsk2->temp = wsk->temp;
			wsk2->nast = NULL;
			//printf("%5d %d %s %.2lf\n", wsk2->nr_pomiaru, wsk2->nr_czujnika, wsk2->data_i_czas, wsk2->temp);
		}
		else if (wsk->nr_czujnika == 3)
		{
			if (head3 == NULL)
			{
				head3 = wsk3 = (struct pomiar *)malloc(sizeof(struct pomiar));
			}
			else
			{
				wsk3->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
				wsk3 = wsk3->nast;
			}
			wsk3->nr_pomiaru = wsk->nr_pomiaru;
			wsk3->nr_czujnika = wsk->nr_czujnika;
			strcpy(wsk3->data_i_czas, wsk->data_i_czas);
			wsk3->temp = wsk->temp;
			wsk3->nast = NULL;
			//printf("%5d %d %s %.2lf\n", wsk3->nr_pomiaru, wsk3->nr_czujnika, wsk3->data_i_czas, wsk3->temp);
		}
		else if (wsk->nr_czujnika == 4)
		{
			if (head4 == NULL)
			{
				head4 = wsk4 = (struct pomiar *)malloc(sizeof(struct pomiar));
			}
			else
			{
				wsk4->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
				wsk4 = wsk4->nast;
			}
			wsk4->nr_pomiaru = wsk->nr_pomiaru;
			wsk4->nr_czujnika = wsk->nr_czujnika;
			strcpy(wsk4->data_i_czas, wsk->data_i_czas);
			wsk4->temp = wsk->temp;
			wsk4->nast = NULL;
			//printf("%5d %d %s %.2lf\n", wsk4->nr_pomiaru, wsk4->nr_czujnika, wsk4->data_i_czas, wsk4->temp);
		}
		wsk = wsk->nast;
	}

	glowy.head1 = head1;
	glowy.head2 = head2;
	glowy.head3 = head3;
	glowy.head4 = head4;

	return glowy;
}

struct pomiar *fun4(struct pomiar *head)
{
	struct pomiar *wsk = NULL;
	struct pomiar *wsk2 = NULL;
	struct pomiar *dane = NULL;

	wsk = head;
	wsk2 = head;

	while (wsk != NULL)
	{
		if (wsk->temp > wsk2->temp)
		{
			wsk2 = wsk;
		}
		wsk = wsk->nast;
	}

	dane = (struct pomiar *)malloc(sizeof(struct pomiar));
	dane->nr_pomiaru = wsk2->nr_pomiaru;
	dane->nr_czujnika = wsk2->nr_czujnika;
	strcpy(dane->data_i_czas, wsk2->data_i_czas);
	dane->temp = wsk2->temp;

	dane->nast = head;

	printf("Rekord z najwyzsza wartoscia temp.:\n%d %d %s %.2lf\n", wsk2->nr_pomiaru, wsk2->nr_czujnika, wsk2->data_i_czas, wsk2->temp);

	return dane;
}