#include <stdio.h>
#include <stdlib.h>

struct fractie{
    float numarator;
    float numitor;
    float rezultat;
};

void citire(struct fractie *p){
    printf("Introduceti numaratorul!\n");
    scanf("%f",&(*p).numarator);
    printf("Introduceti numitorul!\n");
    scanf("%f",&(*p).numitor);
}

void afisare(struct fractie *p){
    printf("numaratorul este %f\n",(*p).numarator);
    printf("numitorul este %f\n",(*p).numitor);
}

void maximFractie(struct fractie *p,int n){
    int i;
    int aux;
    int max=p[0].rezultat;
    for(i=0;i<n;i++){
        p[i].rezultat=p[i].numarator/p[i].numitor;
    }
    for(i=0;i<n;i++){
        if(p[i].rezultat>max){
            aux=i;
            max=p[i].rezultat;
        }
    }
    printf("%.1f/\%.1f",p[aux].numarator,p[aux].numitor);
}

int main()
{
    struct fractie a[100];
    int i;
    int n;
    printf("Introduceti numarul de fractii dorite!\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        citire(&a[i]);
    }
    printf("Fractia cu valoarea maxima este: ");
    maximFractie(a,n);
    return 0;
}
