#include <stdio.h>
#include <stdlib.h>

typedef struct vietuitoare{
    unsigned int tip_animal:2;
    union{
        struct insecta{
            int nr_picioare:10; ///miriapodul poate avea 750 de picioare
            int durata_de_viata:8; ///broastele testoase pot avea durata de viata
        }i;
        struct pasare{
            int nr_pui:8;
            int greutate:8;
        }p;
        struct mamifer{
            char specie[21];
            int
        }m;
        struct peste{
            int nr_solzi:12;

        }ps;
    }uniune;

}creatura;


int main()
{
    FILE *f;
    f = fopen("date.bin","rb");
    if(!f){
        printf("Eroare deschidere fisier!\n");
        exit(1);
    }

    unsigned int aux;

    while(fread(&aux,1,1,f)!=NULL){
        uniune.tip_animal = aux;

    switch(creatura.tip_animal){
    case 0:
        fread(&aux,1,1,f);
        uniune.insecta.nr_picioare = aux;
        fread(&aux,1,1,f);
        uniune.insecta.durata_de_viata = aux;


    }

    }

///  0  6 10 askdjasdad 9
/// 00 06 0A 61         00 00 00 09

    printf("Hello world!\n");
    return 0;
}
