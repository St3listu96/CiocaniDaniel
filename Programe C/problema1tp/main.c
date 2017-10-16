#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct animale{
    char nume[21];
    char boala[21];
    char tratament[21];
};


void citire(struct animale *p){
    printf("Introduceti numele animalului!\n");
    scanf("%s",(*p).nume);
    printf("Introduceti boala animalului!\n");
    scanf("%s",(*p).boala);
    printf("Introduceti tratamentul animalului!\n");
    scanf("%s",(*p).tratament);
}

int main()
{
    struct animale *a=(struct animale*)malloc(sizeof(struct animale));
    int nr;
    int i;
    int optiune;
    int nr_animale;
    char boala[100];
    printf("Introduceti numarul de animale!\n");
    scanf("%d",&nr);
    int aux;
    for(i=0;i<nr;i++){
        citire(&a[i]);
    }

    do{
        printf("1.Afiseaza numele animalelor.\n2.Afiseaza animalele care au o anumita boala.\n3.Adaugati animale.\n9.Exit\n");
        printf("Alegeti optiunea!\n");
        scanf("%d",&optiune);
        switch(optiune){
        case 1:
            printf("Lista animalelor:\n");
            for(i=0;i<nr;i++){
                printf("%s\n",a[i].nume);
            }
            break;
        case 2:
            printf("Introduceti boala!\n");
            scanf("%s",boala);
            printf("Animalele cu aceeasi boala sunt:\n");
            for(i=0;i<nr;i++){
                if(strcmp(boala,a[i].boala)==0)
                    printf("%s\n",a[i].nume);
            }
            break;
        case 3:
            printf("Introduceti numarul de animale care vor fi adaugate!\n");
            scanf("%d",&nr_animale);
            aux=nr;
            for(i=0;i<nr_animale;i++){
                citire(&a[i+aux]);
                nr++;
            }
            break;
        }
    }while(optiune!=9);
    return 0;
}
