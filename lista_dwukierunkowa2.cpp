#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
	struct pomiar *poprz;
};

struct pom {
	struct pomiar * head1;
	struct pomiar * head2;
	struct pomiar * head3;
	struct pomiar * head4;
};

struct pomiar * fun1(char nazwa[]);
void fun2(struct pomiar * head);
struct pom fun3(struct pomiar * head);
int fun4(struct pomiar * head);
float fun5(struct pomiar * head);

int main()
{
	char nazwa[] = "temp.txt";

	struct pomiar * head = NULL;

	head = fun1(nazwa);

	printf("\nCala lista:\n");
	fun2(head);

	struct pom glowy;

	glowy = fun3(head);
	printf("****************************************************\n\n");
	
	int roznica = 0;
	float diff = 0;
	diff = fun5(head);
	printf("roznica: %g\n", diff);

	
	printf("LISTA 1:\n");
	fun2(glowy.head1);
	roznica = fun4(glowy.head1);
	printf("roznica: %d\n", roznica);
	printf("****************************************************\n\n");

	printf("LISTA 2:\n");
	fun2(glowy.head2);
	roznica = fun4(glowy.head2);
	printf("roznica: %d\n", roznica);
	printf("****************************************************\n\n");

	printf("LISTA 3:\n");
	fun2(glowy.head3);
	roznica = fun4(glowy.head3);
	printf("roznica: %d\n", roznica);
	printf("****************************************************\n\n");

	printf("LISTA 4:\n");
	fun2(glowy.head4);
	roznica = fun4(glowy.head4);
	printf("roznica: %d\n", roznica);
	diff = fun5(glowy.head4);
	printf("roznica2: %g\n", diff);
	printf("****************************************************\n\n");
	
	free(glowy.head1);
	free(glowy.head2);
	free(glowy.head3);
	free(glowy.head4);

	printf("\n\nKoniec programu.\n");
	getchar();
	return 0;
}

struct pomiar * fun1(char nazwa[])
{
	FILE * plik;

	if ((plik = fopen(nazwa, "r")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.");
		exit(0);
	}
	else
		printf("Plik otwarty");

	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;

	if (fscanf(plik, "%d%d%s%lf", &nr_pomiaru, &nr_czujnika, data_i_czas, &temp) == EOF)
	{
		printf("Plik jest pusty.");
		return NULL;
	}

	struct pomiar* head = NULL;
	struct pomiar* wsk = NULL;

	printf("\n");
	while (!feof(plik))
	{
		if (head == NULL)
		{
			head = wsk = (struct pomiar *)malloc(sizeof(struct pomiar));
			head->poprz = NULL;
		}
		else
		{
			wsk->nast = (struct pomiar *)malloc(sizeof(struct pomiar));
			wsk->nast->poprz = wsk;
			wsk = wsk->nast;
		}
		wsk->nr_pomiaru = nr_pomiaru;
		wsk->nr_czujnika = nr_czujnika;
		strcpy(wsk->data_i_czas, data_i_czas);
		wsk->temp = temp;

		wsk->nast = NULL;

		fscanf(plik, "%d%d%s%lf", &nr_pomiaru, &nr_czujnika, data_i_czas, &temp);
		//printf("%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
	}

	fclose(plik);

	return head;
}

void fun2(struct pomiar * head)
{
	struct pomiar * wsk = NULL;

	wsk = head;

	int ile = 0;

	printf("\nPierwszy element: %5d %d %s %.2lf", head->nr_pomiaru, head->nr_czujnika, head->data_i_czas, head->temp);

	while (wsk!=NULL)
	{
		ile++;
		wsk = wsk->nast;
	}

	wsk = head;
	for (int i = 0; i < (ile - 1); i++)
	{
		wsk = wsk->nast;
	}

	printf("\nOstatni element:  %5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);

	printf("----------------------------------------------------\n");
	printf("Liczba elementow na liscie: %d", ile);
	printf("\n----------------------------------------------------");


	
}

struct pom fun3(struct pomiar * head)
{
	struct pom glowy;

	struct pomiar * head1 = NULL;
	struct pomiar * head2 = NULL;
	struct pomiar * head3 = NULL;
	struct pomiar * head4 = NULL;

	struct pomiar *wsk1 = NULL, *wsk2 = NULL, *wsk3 = NULL, *wsk4 = NULL;

	printf("\n");

	while (head != NULL)
	{
		if (head->nr_czujnika == 1)
		{
			if (head1 == NULL)
			{
				head1 = wsk1 = head;
				head1->poprz = NULL;
			}
			else
			{
				wsk1->nast = head;
				wsk1->nast->poprz = wsk1;
				wsk1 = wsk1->nast;
			}
			//printf("%5d %d %s %.2lf\n", wsk1->nr_pomiaru, wsk1->nr_czujnika, wsk1->data_i_czas, wsk1->temp);
		}
		else if (head->nr_czujnika == 2)
		{
			if (head2 == NULL)
			{
				head2 = wsk2 = head;
				head2->poprz = NULL;
			}
			else
			{
				wsk2->nast = head;
				wsk2->nast->poprz = wsk2;
				wsk2 = wsk2->nast;
			}
			//printf("%5d %d %s %.2lf\n", wsk2->nr_pomiaru, wsk2->nr_czujnika, wsk2->data_i_czas, wsk2->temp);
		}
		else if (head->nr_czujnika == 3)
		{
			if (head3 == NULL)
			{
				head3 = wsk3 = head;
				head3->poprz = NULL;
			}
			else
			{
				wsk3->nast = head;
				wsk3->nast->poprz = wsk3;
				wsk3 = wsk3->nast;
			}
			//printf("%5d %d %s %.2lf\n", wsk3->nr_pomiaru, wsk3->nr_czujnika, wsk3->data_i_czas, wsk3->temp);
		}
		else if (head->nr_czujnika == 4)
		{
			if (head4 == NULL)
			{
				head4 = wsk4 = head;
				head4->poprz = NULL;
			}
			else
			{
				wsk4->nast = head;
				wsk4->nast->poprz = wsk4;
				wsk4 = wsk4->nast;
			}
			//printf("%5d %d %s %.2lf\n", wsk4->nr_pomiaru, wsk4->nr_czujnika, wsk4->data_i_czas, wsk4->temp);
		}
		head = head->nast;
	}
	wsk1->nast = NULL;
	wsk2->nast = NULL;
	wsk3->nast = NULL;
	wsk4->nast = NULL;

	glowy.head1 = head1;
	glowy.head2 = head2;
	glowy.head3 = head3;
	glowy.head4 = head4;

	free(head);

	return glowy;
}

int fun4(struct pomiar * head)
{
	int roznica = 0;

	struct pomiar * wsk = NULL;

	wsk = head;

	struct pomiar * min = wsk, *max = wsk;

	while (wsk != NULL)
	{
		if (max->temp < wsk->temp)
			max = wsk;
		if (min->temp > wsk->temp)
			min = wsk;

		wsk = wsk->nast;
	}

	printf("\nNajmniejsza temperatura: %.2lf\nNajwieksza temperatura: %.2lf", min->temp, max->temp);
	printf("\nPelne dane:\n%5d %d %s %.2lf", min->nr_pomiaru, min->nr_czujnika, min->data_i_czas, min->temp);
	printf("\n%5d %d %s %.2lf\n", max->nr_pomiaru, max->nr_czujnika, max->data_i_czas, max->temp);
	

	if (max->nr_pomiaru > min->nr_pomiaru)
	{
		while (min->nr_pomiaru != max->nr_pomiaru)
		{
			max = max->poprz;
			roznica++;
		}
	}
	else if (max->nr_pomiaru < min->nr_pomiaru)
	{
		while (min->nr_pomiaru != max->nr_pomiaru)
		{
			max = max->nast;
			roznica++;
		}
	}
	
	return roznica;
}

float fun5(struct pomiar * head)
{
	struct pomiar * wsk = NULL, * wsk2 = NULL;
	wsk = head;
	float roznica = 0;
	roznica = fabs(wsk->temp - wsk->nast->temp);

	while (wsk->nast != NULL)
	{
		if (roznica < fabs(wsk->temp - wsk->nast->temp))
		{
			roznica = fabs(wsk->temp - wsk->nast->temp);
			wsk2 = wsk;
		}
		wsk = wsk->nast;
	}

	printf("Roznica bezwgledna temperatur:\n%d %d %s %.2lf\n", wsk2->nr_pomiaru, wsk2->nr_czujnika, wsk2->data_i_czas, wsk2->temp);
	printf("%d %d %s %.2lf\n", wsk2->nast->nr_pomiaru, wsk2->nast->nr_czujnika, wsk2->nast->data_i_czas, wsk2->nast->temp);

	return roznica;
}