#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
	int cheie;
	struct Nod *fiuStang;
	struct Nod *fiuDrept;
}Arbore;

Arbore *rad = NULL;

Arbore *adaugaRadacina(Arbore *rad,int info){
	if (rad == NULL){
		rad->fiuStang = NULL;
		rad->fiuDrept = NULL;
		rad->cheie = info;
	}

	return rad;
}

void preordine(Arbore *rad){
	if (rad != NULL){
		printf("%d  ", rad->cheie);
		preordine(rad->fiuStang);
		preordine(rad->fiuDrept);
	}
}

Arbore *adaugare(Arbore *rad,int info){

	if (rad == NULL){
		rad = (Arbore*)malloc(sizeof(Arbore));
		rad->cheie = info;
		rad->fiuStang = NULL;
		rad->fiuDrept = NULL;
		return rad;
	}

	else{

		if (info > rad->cheie){
			if (rad->fiuDrept == NULL)
				rad->fiuDrept = adaugare(rad->fiuDrept, info);
			else
				adaugare(rad->fiuDrept, info);
		}

		else{
			if (rad->fiuStang == NULL)
				rad->fiuStang = adaugare(rad->fiuStang, info);
			else
				adaugare(rad->fiuStang, info);
		}
	}
}

int cautare(Arbore *rad, int info){

	int bool = 0;
	if (rad != NULL){
		if (info == rad->cheie){
			bool = 1;
		}
		else{
			bool = cautare(rad->fiuDrept, info) + cautare(rad->fiuStang, info);
		}
		return bool;
	}
	else{
		return 0;
	}
}

int inaltimeArbore(Arbore *rad){
	int inaltime = 0;
	if (rad != NULL){
		inaltime++;
		if (inaltimeArbore(rad->fiuStang) > inaltimeArbore(rad->fiuDrept))
			inaltime+= inaltimeArbore(rad->fiuStang);
		else
			inaltime += inaltimeArbore(rad->fiuDrept);
	}
	return inaltime;
}
int main(){

	int info;
	rad = adaugare(rad, 5);
	adaugare(rad, 2);
	adaugare(rad, 3);
	adaugare(rad, 7);
	adaugare(rad, 6);
	adaugare(rad, 1);
	printf("Afisare preordine.\n");
	preordine(rad);
	printf("\nIntroduceti cheia pentru cautare.\n");
	scanf("%d",&info);
	if (cautare(rad, info) == 1)
		printf("Nodul cu cheia %d a fost gasit.\n",info);
	else
		printf("Nodul cu cheia %d nu a fost gasit.\n", info);
	printf("\nInaltimea arborelui este : %d\n", inaltimeArbore(rad));

	return 0;
}