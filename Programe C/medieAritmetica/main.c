#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ct=0;
    float medie;
    float nota;
    float suma;
    float teza;
    printf("Introduceti nota %d!\n",ct+1);
    scanf("%f",&nota);
    while(nota!=0){
            //if(nota<=10)
        suma = suma + nota;
        ct++;
        printf("Introduceti nota %d!\n",ct+1);
        scanf("%f",&nota);
    }
    printf("Introduceti nota de la teza!\n");
    scanf("%f",&teza);
    if(teza==0){
        medie = suma/ct;
        printf("Media celor %d note este : %.2f!",ct,medie);
    }
    else{
        medie = ((suma/ct)*3+teza)/4;
        printf("Media celor %d note + teza este : %.2f!",ct,medie);
    }
    if(medie <5)
        printf("\nFraiere.. iar ai picat, iar mergi la lucru!");
    else
        printf("\nBravo, Costi! De acum vei fi inginer tehnician!");

    return 0;
}
