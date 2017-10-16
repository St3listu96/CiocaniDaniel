#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuvinte{
  int numar_aparitii;
  char info[100];
  struct cuvinte *urm;
}cuv_t;

cuv_t* adauga_final(cuv_t *l , char *x){
    cuv_t *p = l;
    cuv_t *nou = (cuv_t*)malloc(sizeof(cuv_t));
    strcpy(nou->info,x);
    if(l == NULL){
        nou->urm = NULL;
        return nou;
    }
    while(p->urm !=NULL)
        p=p->urm;
    nou->urm = NULL;
    p->urm = nou;
    return l;
}

void afiseazaLista(cuv_t *l){
    while(l!=NULL){
        printf("%s\t",l->info);
        l = l->urm;
    }
}


int main(){
  cuv_t *rad = NULL;
  //char numefisier[21];
  char cuvinte[100][100];
  int nr_cuvinte;
  //strcpy(numefisier,argv[1]);
  FILE *f;

  f = fopen("informatii.txt" , "r");

  if(!f){
    printf("Eroare deschidere fisier ! ");
    exit(1);
  }

  int i = 0;
  while(fscanf(f,"%s",cuvinte[i])==1)
    i++;
  nr_cuvinte = i;


  for(i=0;i<nr_cuvinte;i++){
    rad = adauga_final(rad,cuvinte[i]);
  }

  afiseazaLista(rad);
  fclose(f);
  return 0;
}
