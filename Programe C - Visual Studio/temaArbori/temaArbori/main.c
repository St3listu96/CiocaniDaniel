
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod {
	char nume[35];
	int zi;
	int luna;
	int an;
	struct Nod *fiuStang;
	struct Nod *fiuDrept;
}Arbore;

Arbore *rad = NULL;

Arbore *adaugaRadacina(Arbore *rad, char name[] ,int day,int month,int year) {
	if (rad == NULL) {
		rad->fiuStang = NULL;
		rad->fiuDrept = NULL;
		strcpy(rad->nume,name);
		rad->zi = day;
		rad->luna= month;
		rad->an = year;
	}

	return rad;
}

/*void preordine(Arbore *rad) {
	if (rad != NULL) {
		printf("%d  ", rad->cheie);
		preordine(rad->fiuStang);
		preordine(rad->fiuDrept);
	}
}*/

Arbore *adaugare(Arbore *rad, char name[], int day, int month, int year) {

	if (rad == NULL) {
		rad = (Arbore*)malloc(sizeof(Arbore));
		rad->fiuStang = NULL;
		rad->fiuDrept = NULL;
		strcpy(rad->nume, name);
		rad->zi = day;
		rad->luna = month;
		rad->an = year;
		return rad;
	}

	else {

		if (strcmp(rad->nume, name) < 0) {
			if (rad->fiuDrept == NULL)
				rad->fiuDrept = adaugare(rad->fiuDrept, name, day, month, year);
			else
				adaugare(rad->fiuDrept, name, day, month, year);
		}

		else {
			if (rad->fiuStang == NULL)
				rad->fiuStang = adaugare(rad->fiuStang, name, day, month, year);
			else
				adaugare(rad->fiuStang, name, day, month, year);
		}
	}
}

/*
int cautare(Arbore *rad, int info) {

	int bool = 0;
	if (rad != NULL) {
		if (info == rad->cheie) {
			bool = 1;
		}
		else {
			bool = cautare(rad->fiuDrept, info) + cautare(rad->fiuStang, info);
		}
		return bool;
	}
	else {
		return 0;
	}
}

int inaltimeArbore(Arbore *rad) {
	int inaltime = 0;
	if (rad != NULL) {
		inaltime++;
		if (inaltimeArbore(rad->fiuStang) > inaltimeArbore(rad->fiuDrept))
			inaltime += inaltimeArbore(rad->fiuStang);
		else
			inaltime += inaltimeArbore(rad->fiuDrept);
	}
	return inaltime;
}*/
int main() {
	int optiune;
	int numarPersoane = 0;
	char numele[40];
	int day;
	int month;
	int year;
	FILE *f;
	f = fopen("FisierTest.txt", "r");
	if (!f) {
		printf("Eroare la deschidere fisier.\n");
		exit(1);
	}


	/*while (fgets(numele, 40, f) != NULL) {
		numele[strlen(numele) - 1] = '\0';
		fscanf(f, "%d/%d/%d", &day, &month, &year);
		if (numarPersoane == 0)
			rad = adaugare(rad, numele, day, month, year);
		else
		    adaugare(rad, numele, day, month, year);
		numarPersoane++;
	}*/

	do {
	
		printf("Alegeti optiunea!\n");
		printf("\n\n");

		printf("1.Afisare studenti nascuti pe o anumita data.\n2.Afisare studenti nascuti inainte de o anumita data.\n3.Afisarea celui mai tanar student.\n4.Stergerea unui student localizat dupa nume.\n5.Afisarea inaltimii arborelui.\n\n\n\n9.EXIT\n");
		scanf("%d", &optiune);

		switch (optiune) {
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5:
			//printf("Inaltimea arborelui este: ");
			//printf("%d\n", inaltimeArbore(rad));
			break;
		}
	} while (optiune != 9);
	return 0;
}