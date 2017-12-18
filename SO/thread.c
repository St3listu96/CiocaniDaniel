#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int matrice[50][50];
int n;
int suma[50];

void *execFir(void *arg){
	int i;
	suma[(int)arg]=0;
	for(i=0;i<n;i++){
		suma[(int)arg] = suma[(int)arg] + matrice[i][(int)arg];
	}

	return (void *) &(suma[(int)arg]);
}



int main(int nrArg, char *argument[]){
	int i;
	int j;
	int sumaTotala=0;
	pthread_t th[50];
	if (nrArg != 3){
		printf("<Usage> %s N file.\n",argument[0]);
		exit(0);
	}

	n = atoi(argument[1]);

	FILE *f;

	f = fopen(argument[2],"r");

	if(!f){
		printf("Eroare deschidere fisier.\n");
		exit(1);
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(f,"%d",&matrice[i][j]);
		}
	}

	for(i=0;i<n;i++){
		pthread_t th[i];
	}	

	for(i=0;i<n;i++){
		pthread_create(&th[i],NULL,execFir,(void*) i);
	}

	for(i=0;i<n;i++){
		pthread_join(th[i],NULL);
		sumaTotala += suma[i];
	}	

	printf("Suma este : %d.\n",sumaTotala);

	return 0;
}
