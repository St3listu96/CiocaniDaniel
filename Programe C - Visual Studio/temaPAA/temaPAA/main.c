#pragma warning(disable : 4996)  
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
int d = 0;
int m = 0;
int y = 0;


Arbore *adaugaRadacina(Arbore *rad, char name[], int day, int month, int year) {
	if (rad == NULL) {
		rad = (Arbore*)malloc(sizeof(Arbore));
		rad->fiuStang = NULL;
		rad->fiuDrept = NULL;
		strcpy(rad->nume, name);
		rad->zi = day;
		rad->luna = month;
		rad->an = year;
	}
	return rad;
}

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


void afisStudData(Arbore *rad,int day,int month,int year) {
	if (rad != NULL) {
		if ((rad->zi == day) && (rad->luna == month) && (rad->an == year))
			printf("%s\n", rad->nume);
		afisStudData(rad->fiuDrept, day, month, year);
		afisStudData(rad->fiuStang, day, month, year);
	}
}

void printBefore(Arbore *rad, int day, int month, int year) { 
	if (rad != NULL) {
		if ((rad->an < year) || (rad->an == year && rad->luna < month) || (rad->an == year && rad->luna == month && rad->zi <= day))
			printf("%s\n",rad->nume);
		printBefore(rad->fiuDrept, day, month, year);
		printBefore(rad->fiuStang, day, month, year);
	}
}

void youngest(Arbore *rad) {
	if (rad != NULL) {
		if ((rad->an > y) || (rad->an == y && rad->luna > m) || (rad->an == y && rad->luna == m && rad->zi >= d)){
			y= rad->an;
			m = rad->luna;
			d = rad->zi;
			youngest(rad->fiuDrept);
			youngest(rad->fiuStang);
		}
		else {
			youngest(rad->fiuDrept);
			youngest(rad->fiuStang);
		}
	}
}

Arbore* smallestLeft(Arbore* rad)
{
	Arbore* aux = rad;
	while (aux->fiuStang != NULL)
		aux = aux->fiuStang;
	return aux;
}


Arbore* stergeNod(Arbore* rad, char name[]) {
	if (rad == NULL)
		return rad;
	if (strcmp(name, rad->nume) > 0) {
		rad->fiuDrept = stergeNod(rad->fiuDrept, name);
	}
	else if (strcmp(name, rad->nume) < 0) {
		rad->fiuStang = stergeNod(rad->fiuStang, name);
	}

	else {
		if (rad->fiuStang == NULL) {
			Arbore *aux = rad->fiuDrept;
			free(rad);
			return aux;
		}

		else if (rad->fiuDrept == NULL) {
			Arbore *aux = rad->fiuStang;
			free(rad);
			return aux;
		}

		Arbore* aux = smallestLeft(rad->fiuDrept);
		strcpy(rad->nume, aux->nume);
		rad->an = aux->an;
		rad->luna = aux->luna;
		rad->zi = aux->zi;
		rad->fiuDrept = stergeNod(rad->fiuDrept, aux->nume);
	}
	return rad;
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
}
int main() {
	int optiune;
	int numarPersoane = 0;
	char numele[40];
	int day;
	int month;
	int year;
	char nume[35];
	FILE *f;
	f = fopen("FisierTest.txt", "r");
	if (!f) {
		printf("Eroare la deschidere fisier.\n");
		exit(1);
	}


	while (fgets(numele, 40, f) != NULL) {
		numele[strlen(numele) - 1] = '\0';
		fscanf(f, "%d/%d/%d\n", &day, &month, &year);
		if (numarPersoane == 0)
			rad = adaugaRadacina(rad, numele, day, month, year);
		else
			adaugare(rad, numele, day, month, year);
		numarPersoane++;
	}

	do {

		printf("\nAlegeti optiunea\n");
		printf("\n\n");

		printf("1. Afisare studenti nascuti pe o anumita data\n2. Afisare studenti nascuti inainte de o anumita data\n3. Afisarea celui mai tanar student\n4. Stergerea unui student localizat dupa nume\n5. Afisarea inaltimii arborelui\n\n\n\n9. Exit\n");
		scanf("%d", &optiune);

		switch (optiune) {
		case 1:
			printf("Introduceti ziua.\n");
			scanf("%d",&day);
			printf("Introduceti luna.\n");
			scanf("%d", &month);
			printf("Introduceti anul.\n");
			scanf("%d", &year);
			printf("Studentii nascuti in data de %d/%d/%d sunt :\n",day,month,year);
			afisStudData(rad, day, month, year);
			break;

		case 2:
			printf("Introduceti ziua.\n");
			scanf("%d", &day);
			printf("Introduceti luna.\n");
			scanf("%d", &month);
			printf("Introduceti anul.\n");
			scanf("%d", &year);
			printf("Studentii nascuti inainte de data %d/%d/%d sunt :\n", day, month, year);
			printBefore(rad, day, month, year);
			break;

		case 3:
			printf("Cei mai tineri studenti sunt: \n");
			youngest(rad);
			afisStudData(rad,d,m,y);
			d = 0;
			m = 0;
			y = 0;
			break;

		case 4:
			printf("Introduceti numele.\n");
			scanf("%s",nume);
			rad = stergeNod(rad,nume);
			break;

		case 5:
			printf("Inaltimea arborelui este: ");
			printf("%d\n", inaltimeArbore(rad));
			break;
		}
	} while (optiune != 9);
	return 0;
}