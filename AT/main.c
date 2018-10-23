#include <stdio.h>
#include <stdlib.h>
#include "at.h"

int main(int argc , char *argv[]){
	FILE *f;
	f = fopen(argv[1], "r");
	if (!f){
		printf("Eroare la deschiderea fisierului.\n");
		exit(1);
	}
	char ch;

	while (!feof(f)){
		ch = fgetc(f);
		at_parse(ch);
	}


}