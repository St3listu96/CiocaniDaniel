#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char produs[]="Produs";
    int ct=0;
    int aleator;
    int cantitate_produs;
    int pret_produs;
    FILE *f;

    f = fopen("info.txt","wb");

    if(!f){
        printf("Eroare deschidere fisier ! \n");
        exit(1);
    }

    while(ct<101){
        fwrite(produs,sizeof(char),1,f);
        aleator = rand();
        fwrite(&aleator,sizeof(char),1,f);
        cantitate_produs = aleator%100;
        fwrite(&cantitate_produs,sizeof(cantitate_produs),1,f);
        if(aleator<=100)
            pret_produs = aleator;
        else
            pret_produs = cantitate_produs/2;;
        fwrite(&pret_produs,sizeof(int),1,f);
        ct++;
    }

    fclose(f);

    return 0;
}
