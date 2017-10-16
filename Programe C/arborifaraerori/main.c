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


int d=0,m=0,y=0;
Arbore *rad = NULL;

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
			y = rad->an;
			m = rad->luna;
			d= rad->zi;
			youngest(rad->fiuDrept);
			youngest(rad->fiuStang);

		}
		else {
			youngest(rad->fiuDrept);
			youngest(rad->fiuStang);
		}
	}
}

Arbore *supred(Arbore *t,Arbore *p)
{
  Arbore *q;

  if (t->fiuDrept!=NULL)
       t->fiuDrept=supred(t->fiuDrept,p);
   else
   {
      q= t;
      strcpy(p->nume,t->nume);
	  p->an=t->an;
	  p->luna=t->luna;
	  p->zi=t->zi;
      t = t->fiuStang;
      free(q);
   }
  return t;
}

Arbore *elimina(Arbore *p,char nume[])
{
  Arbore *q ;

  if(p==NULL)
    printf(" nu exista!\n");
   else
     if(strcmp(p->nume,nume)>0)
       p->fiuStang=elimina(p->fiuStang,nume);
     else if(strcmp(p->nume,nume)<0)
	     p->fiuDrept=elimina(p->fiuDrept,nume);
	  else if(p->fiuStang==NULL)
	       {
		q = p->fiuDrept;
		free(p);
		return q;
	       }
	       else if(p->fiuDrept==NULL)
		    {
		       q = p->fiuStang;
		       free(p);
		       return q;
		    }
		    else p->fiuStang=supred(p->fiuStang,p);
  return p;
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
	char nume[30];
	int day;
	int month;
	int year;
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
			rad = adaugare(rad, numele, day, month, year);
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
			printf("Cel mai tanar student este: \n");
			youngest(rad);
			afisStudData(rad, d, m, y);
			break;

		case 4:
			printf("Introduceti numele.\n");
			scanf("%s",nume);
			rad = elimina(rad,nume);
			break;

		case 5:
			printf("Inaltimea arborelui este: ");
			printf("%d\n", inaltimeArbore(rad));
			break;
		}
	} while (optiune != 9);
	return 0;
}
