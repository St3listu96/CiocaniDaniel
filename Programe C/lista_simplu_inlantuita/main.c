#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuvinte{
    char cuvinte[20];
    struct cuvinte *urm;
}cuvinte_t;

cuvinte_t* adauga_final(cuvinte_t *rad,char cuvant[]){
    cuvinte_t *p = rad;
    cuvinte_t *nou = (cuvinte_t*)malloc(sizeof(cuvinte_t));
    strcpy(nou->cuvinte,cuvant);
    if(rad == NULL){
        nou->urm = NULL;
        return nou;
    }
        while(p->urm !=NULL){
            p=p->urm;
        }
        nou->urm = NULL;
        p->urm = nou;
        return rad;
}

void afiseazaLista(cuvinte_t* rad){
    cuvinte_t *p =rad;
    while(p!=NULL){
        printf("%s ",p->cuvinte);
        p=p->urm;
    }
}

int main()
{
    cuvinte_t *rad = NULL;
    FILE *f;
    char cuvinte2[100];
    //int nr_cuvinte;
    f = fopen("fisier.txt","r");
    if(!f){
        printf("Eroare deschidere 'fisier.txt' !\n");
        exit(1);
    }

    int i=0;
    while(fscanf(f,"%s",cuvinte2)==1){
        rad = adauga_final(rad,cuvinte2);
        i++;
    }

    afiseazaLista(rad);

    //nr_cuvinte = i;





    return 0;
}
