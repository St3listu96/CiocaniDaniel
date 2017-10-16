#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct Nod{
	char cheie;
	int parinte;
}ArboreGen;

ArboreGen tablou[MAX];
int nrElemente = 0;

void adaugareRadacina(char help){
	if (nrElemente == 0){
		tablou[nrElemente].cheie = help;
		tablou[nrElemente].parinte = -1;
		nrElemente++;
	}
	else
		printf("Deja exista o radacina");
}

int cautare(char help){
	int i = 0;
	for (i = 0; i < nrElemente; i++){
		if (tablou[i].cheie == help)
			return i;
	}
	return -1;
}

void adauga(char help,char father){
	int aux;
	aux = cautare(father);
	tablou[nrElemente].cheie = help;
	tablou[nrElemente].parinte = aux;
	nrElemente++;
}

int relatie(char stramos, char descendent){
	
}

int main(){
	
	adaugareRadacina('a');
	adauga('b', 'a');
	adauga('c', 'a');
	adauga('d', 'a');
	adauga('e', 'b');
	adauga('f', 'b');
	adauga('g', 'd');
	adauga('h', 'd');
	adauga('i', 'd');

	return 1;
	



}