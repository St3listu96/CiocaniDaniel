#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct animale{
  int tip_animal;
  union{
    struct maimuta{
      unsigned int nr_picioare:10;
      float kg;
      int periculos:1;
      char abreviere[8];
      unsigned int varsta_maxima:11;
    }m;

    struct flamingo{
      unsigned int nr_picioare:10;
      float kg;
      int periculos:1;
      char abreviere[8];
      unsigned int varsta_maxima:11;
    }f;
  }uniune;
}animale_t;


int main(){
  FILE *f;
  char aux[100];
  int optiune;
  int tip;
  animale_t *a=(animale_t*)malloc(sizeof(animale_t));
  f = fopen("animale.txt","r");

  int i = 0;
  while(fscanf(f,"%d",&a[i].tip_animal)==1){
  if(a[i].tip_animal == 0){
    fscanf(f,"%s",aux);
    a[i].uniune.m.nr_picioare = atoi(aux);
    fscanf(f,"%s",aux);
    a[i].uniune.m.kg = atoi(aux);
    fscanf(f,"%s",aux);
    a[i].uniune.m.periculos = atoi(aux);
    fscanf(f,"%s",a[i].uniune.m.abreviere);
    fscanf(f,"%s",aux);
    a[i].uniune.m.varsta_maxima = atoi(aux);
  }
   if(a[i].tip_animal == 1){
    fscanf(f,"%s",aux);
    a[i].uniune.f.nr_picioare = atoi(aux);
    fscanf(f,"%s",aux);
    a[i].uniune.f.kg = atoi(aux);
    fscanf(f,"%s",aux);
    a[i].uniune.f.periculos = atoi(aux);
    fscanf(f,"%s",a[i].uniune.f.abreviere);
    //strcpy(a[i].uniune.f.abreviere,aux);
    fscanf(f,"%s",aux);
    a[i].uniune.f.varsta_maxima = atoi(aux);
  }
   i++;
  }

  printf("--%s--\n",a[0].uniune.m.abreviere);

  int nr_animale = i;

  do{
    printf("Menu\n");
    printf("1.Introduceti un animal\n");
    printf("2.Afisati toate animalele\n");
    printf("3.Afisati toate animalele periculoase pentru om\n");

    scanf("%d",&optiune);

    switch(optiune){

    case 1:
      printf("Introduceti tipul animalului (0-Maimuta , 1-Flamingo)\n");
      scanf("%u", &tip);
      if(tip == 0 || tip == 1){
      if(tip == 0){
	printf("Introduceti numarul de picioare !\n");
	scanf("%s",aux);
	a[nr_animale].uniune.m.nr_picioare = atoi(aux);
	printf("Introduceti numarul de kg!\n");
	scanf("%s",aux);
	a[nr_animale].uniune.m.kg = atoi(aux);
	printf("Este periculos animalul? (0-NU, 1-DA)\n");
	scanf("%s",aux);
	a[nr_animale].uniune.m.periculos = atoi(aux);
	printf("Introduceti abrevierea lui stiintifica!\n");
	scanf("%s",aux);
        strcpy(a[nr_animale].uniune.m.abreviere,aux);
	printf("Introduceti varsta maxima pe care o poate avea animalul!\n");
	scanf("%s",aux);
	a[nr_animale].uniune.m.varsta_maxima = atoi(aux);
      }
	else if(tip == 1){
	  printf("Introduceti numarul de picioare !\n");
	  scanf("%s",aux);
	  a[nr_animale].uniune.f.nr_picioare = atoi(aux);
	  printf("Introduceti numarul de kg!\n");
	  scanf("%s",aux);
	  a[nr_animale].uniune.f.kg = atoi(aux);
	  printf("Este periculos animalul? (0-NU, 1-DA)\n");
	  scanf("%s",aux);
	  a[nr_animale].uniune.f.periculos = atoi(aux);
	  printf("Introduceti abrevierea lui stiintifica!\n");
	  scanf("%s",aux);
	  strcpy(a[nr_animale].uniune.f.abreviere,aux);
	  printf("Introduceti varsta maxima pe care o poate avea animalul!\n");
	  scanf("%s",aux);
	  a[nr_animale].uniune.f.varsta_maxima = atoi(aux);
	}
      nr_animale++;
      }
	  else{
	    printf("Puteti introduce doar 0 si 1 la tipul animalului!\n");
	  }
      break;

    case 2:
      printf("Lista animale(abreviere): \n");
      for(i=0;i<nr_animale;i++){
        printf("%s\n",a[i].uniune.f.abreviere);
	//printf("%s\n",a[i].uniune.f.abreviere);
      }
      break;

    case 3:
      printf("Lista cu animale periculoase este : \n");
      for(i=0;i<nr_animale;i++){
        if(a[i].uniune.m.periculos == 1)
            printf("%s\n",a[i].uniune.m.abreviere);
       	if(a[i].uniune.f.periculos == 1)
            printf("%s\n",a[i].uniune.f.abreviere);
      }

    }
  }while(optiune!=9);


  return 0;
}
