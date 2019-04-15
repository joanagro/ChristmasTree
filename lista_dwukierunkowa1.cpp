#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar *nast;
	struct pomiar *poprz;
};

int main()
{
	FILE * plik;
	char nazwa[20];
	printf("Podaj nazwe pliku: ");
	scanf("%s", nazwa);

	if ((plik = fopen(nazwa, "r")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.");
		getchar();
		printf("\n\nKoniec programu.\n");
		getchar();
		return 0;
	}
	else
		printf("Plik otwarty");

	struct pomiar* head = NULL;
	struct pomiar* wsk = NULL;
	//struct pomiar *nast = NULL;
	//struct pomiar * poprz = NULL;

	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;

	if (fscanf(plik, "%d%d%s%lf", &nr_pomiaru, &nr_czujnika, data_i_czas, &temp) == EOF)
	{
		printf("Plik jest pusty.");
		getchar();
		printf("\n\nKoniec programu.\n");
		getchar();
		return 0;
	}

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

	/*wsk = head;
	while (wsk != NULL)
	{
		printf("%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
		wsk = wsk->nast;
	}
	*/
	/*wsk = head;
	while (wsk->nast != NULL)
	{
		printf("%5d %d %s %.2lf\n", wsk->nast->poprz->nr_pomiaru, wsk->nast->poprz->nr_czujnika, wsk->nast->poprz->data_i_czas, wsk->nast->poprz->temp);
		wsk = wsk->nast;
	}*/

	fclose(plik);
	printf("Plik zamkniety.");
	
	struct pomiar * head1 = NULL;
	struct pomiar * head2 = NULL;
	struct pomiar * head3 = NULL;
	struct pomiar * head4 = NULL;

	struct pomiar *wsk1 = NULL, *wsk2 = NULL, *wsk3 = NULL, *wsk4 = NULL;

	int ile1 = 0, ile2 = 0, ile3 = 0, ile4 = 0;

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
			ile1++;
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
			ile2++;
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
			ile3++;
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
			ile4++;
			//printf("%5d %d %s %.2lf\n", wsk4->nr_pomiaru, wsk4->nr_czujnika, wsk4->data_i_czas, wsk4->temp);
		}
		head->poprz = head;
		head = head->nast;
	}

	free(head);

	wsk1 = head1;
	
	struct pomiar * min = wsk1, * max = wsk1;

	while (wsk1!= NULL)
	{
		if (max->temp < wsk1->temp)
			max = wsk1;
		if (min->temp > wsk1->temp)
			min = wsk1;

		wsk1 = wsk1->nast;
	}
	printf("\n**********************************\n");
	printf("\nRozmiar 1. listy: %d\n\nNajmniejsza temperatura: %.2lf\n\nNajwieksza temperatura: %.2lf", ile1, min->temp, max->temp);
	printf("\n\n**********************************\n");

	wsk2 = head2;

	min = wsk2;
	max = wsk2;

	while (wsk2 != NULL)
	{
		if (max->temp < wsk2->temp)
			max = wsk2;
		if (min->temp > wsk2->temp)
			min = wsk2;

		wsk2 = wsk2->nast;
	}
	
	printf("\nRozmiar 2. listy: %d\n\nNajmniejsza temperatura: %.2lf\n\nNajwieksza temperatura: %.2lf", ile2, min->temp, max->temp);
	printf("\n\n**********************************\n");

	wsk3 = head3;

	min = wsk3;
	max = wsk3;

	while (wsk3 != NULL)
	{
		if (max->temp < wsk3->temp)
			max = wsk3;
		if (min->temp > wsk3->temp)
			min = wsk3;

		wsk3 = wsk3->nast;
	}

	printf("\nRozmiar 3. listy: %d\n\nNajmniejszya temperatura: %.2lf\n\nNajwieksza temperatura: %.2lf", ile3, min->temp, max->temp);
	printf("\n\n**********************************\n");

	wsk4 = head4;

	min = wsk4;
	max = wsk4;

	while (wsk4 != NULL)
	{
		if (max->temp < wsk4->temp)
			max = wsk4;
		if (min->temp > wsk4->temp)
			min = wsk4;

		wsk4 = wsk4->nast;
	}

	printf("\nRozmiar 4. listy: %d\n\nNajmniejsza temperatura: %.2lf\n\nNajwieksza temperatura: %.2lf", ile4, min->temp, max->temp);
	printf("\n\n**********************************\n");

	FILE * save1,* save2,* save3,* save4;

	printf("\nPodaj nazwe dla plikow: ");
	char name1[20], name2[20], name3[20], name4[20];

	scanf("%s", name1);

	strcpy(name2, name1);
	strcat(name1, "1.txt");
	

	if ((save1 = fopen(name1, "w")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		exit(1);
	}
	else
	{
		printf("Udalo sie otworzyc plik.\n");
	}

	strcpy(name3, name2);
	strcat(name2, "2.txt");

	if ((save2 = fopen(name2, "w")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		exit(1);
	}
	else
		printf("Udalo sie otworzyc plik.\n");

	strcpy(name4, name3);
	strcat(name3, "3.txt");

	if ((save3 = fopen(name3, "w")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		exit(1);
	}
	else
		printf("Udalo sie otworzyc plik.\n");

	strcat(name4, "4.txt");

	if ((save4 = fopen(name4, "w")) == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		exit(1);
	}
	else
		printf("Udalo sie otworzyc plik.\n");


	int i;
	wsk = head1;

	for(i = 0; i<ile1;i++)
	{
		fprintf(save1, "%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
		wsk = wsk->nast;
	}

	wsk = head2;
	for (i = 0; i < ile2; i++)
	{
		fprintf(save2, "%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
		wsk = wsk->nast;
	}

	wsk = head3;
	for (i = 0; i < ile3; i++)
	{
		fprintf(save3, "%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
		wsk = wsk->nast;
	}

	wsk = head4;
	for (i = 0; i < ile4; i++)
	{
		fprintf(save4, "%5d %d %s %.2lf\n", wsk->nr_pomiaru, wsk->nr_czujnika, wsk->data_i_czas, wsk->temp);
		wsk = wsk->nast;
	}

	free(head1);
	free(head2);
	free(head3);
	free(head4);

	fclose(save1);
	fclose(save2);
	fclose(save3);
	fclose(save4);


	getchar();
	printf("\n\nKoniec programu.\n");
	getchar();
	return 0;
}