#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f;
	FILE *g;
	int materii = 0;
	float nota;
	float suma = 0;
	float medie;

	f = fopen("note.txt", "r");

	if (!f) {
		printf("Eroare la deschiderea fisierului 'note.txt'.\n");
		exit(1);
	}
	
	while (!feof(f)) {
		fscanf(f,"%f",&nota);
		suma = suma + nota;
		materii++;
	}

	medie = suma / materii;

	fclose(f);

	g = fopen("teza.txt", "r");

	if (!g) {
		printf("Eroare la deschiderea fisierului 'teza.txt'.\n");
		exit(1);
	}

	if (fscanf(g,"%f",&nota)==1) {
		medie = ((medie * 3) + nota) / 4;
		printf("Media cu teza este: %.3f\n",medie);
		return 0;
	}
		
		
	printf("Media este : %.3f\n",medie);
	
	
	return 0;
}