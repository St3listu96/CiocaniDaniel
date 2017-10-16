#include <stdio.h>

#include <stdlib.h>

#include <string.h>



struct animale

{

char nume[20];

char specie[20];

char data[15];

union clasa

{

struct

{

int temp;

int cantitatehrana;

}peste;


struct

{

int nrmese;

}pasare;


struct

{

int cantitatehrana;

int greutate;

int nrmese;

}mamifer;

}clasa;


};


int main()

{

struct animale *x;

int c,i=0,j=0,cl;

int class[50];

x=(struct animale *)malloc(sizeof(struct animale));

while(1)

{

printf("\n\n1. Introduceti o inregistrare\n");

printf("2. Afisati toate animalele dintr-o clasa\n");

printf("3. Afisati toate inregistrarile\n");

printf("4. Exit\n\n");

do {

c = getchar();

switch (c)

{

case '1' :{
printf("Nume: ");scanf("%s",x[i].nume);

printf("Specie: ");scanf("%s",x[i].specie);

printf("Data: ");scanf("%s",x[i].data);

printf("Clasa (1-pesti, 2-pasari, 3-mamifere): ");

scanf("%d",&class[i]);

switch (class[i])

{

case 1: {printf("Temperatura apei: ");
scanf("%d",&x[i].clasa.peste.temp);

printf("Cantitatea de hrana: ");
scanf("%d",&x[i].clasa.peste.cantitatehrana);

break;}

case 2:{ printf("Numarul de mese pe zi: ");
scanf("%d",&x[i].clasa.pasare.nrmese);

break;}

case 3:{ printf("Cantitatea de hrana: ");
scanf("%d",&x[i].clasa.mamifer.cantitatehrana);

printf("Greutatea: ");scanf("%d",&x[i].clasa.mamifer.greutate);

printf("Numarul de mese pe zi: ");
scanf("%d",&x[i].clasa.mamifer.nrmese);

break;
}

}

i++;


break;
}

case '2' : {

printf("Clasa (1-pesti, 2-pasari, 3-mamifere): ");scanf("%d",&cl);

printf("Numele animalelor cu aceeasi clasa: ");

for(j=0;j<i;j++)

{

if(cl==class[j])

switch (cl)

{

case 1: printf("%s ",x[j].nume);

break;

case 2: printf("%s ",x[j].nume);

break;

case 3: printf("%s ",x[j].nume);

break;

}

}


break;}

case '3' :{
for(j=0;j<i;j++)

{

printf("Nume: %s ",x[j].nume);

printf("Rasa: %s ",x[j].specie);

printf("Data: %s ",x[j].data);

switch(class[j])

{

case 1: printf("Clasa: Pesti ");

printf("Temeperatura apei: %d ",x[j].clasa.peste.temp);

printf("Cantitatea de hrana: %d \n",x[j].clasa.peste.cantitatehrana);

break;

case 2: printf("Clasa: Pasari ");

printf("Numarul de mese pe zi: %d \n",x[j].clasa.pasare.nrmese);

break;

case 3: printf("Clasa: Mamifere ");

printf("Cantitatea de hrana: %d ",x[j].clasa.mamifer.cantitatehrana);

printf("Greutatea: %d ",x[j].clasa.mamifer.greutate);

printf("Numarul de mese pe zi: %d \n",x[j].clasa.mamifer.nrmese);

break;

}

}

break;}

case '4' : free(x);

return 0;

}

}
while ((c=='1')||(c=='2')||(c=='3')||(c=='4'));

}


}
