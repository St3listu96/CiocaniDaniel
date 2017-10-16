#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nume_produs[100];
    float pret;
    int len;
    FILE *f;
    f = fopen("produse.dat","wb");
    while(1){
        printf("Introduceti numele produsului!\n");
        fflush(stdin);
        fgets(nume_produs,255,stdin);
        if(strcmp(nume_produs,"\n")==0)
            break;
        else{
            len = strlen(nume_produs)-1;
            fwrite(&len,sizeof(char),1,f);
            fwrite(nume_produs,sizeof(char),len,f);
        }
        printf("Introduceti pretul produsului!\n");
        scanf("%f",&pret);
        fwrite(&pret,sizeof(float),1,f);
    }
    fclose(f);

    return 0;
}
