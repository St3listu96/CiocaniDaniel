//se introduce o data curenta si o data de nastere. Determinati varsta persoanei.
#include<stdio.h>
#include<stdlib.h>
int x,zc,lc,ac,zn,ln,an;
int main(){
    printf("Dati data curenta de forma zi/luna/an: ");
    scanf("%d/%d/%d",&zc,&lc,&ac);
    printf("\nDati data nasterii de forma zi/luna/an : ");
    scanf("%d/%d/%d",&zn,&ln,&an);
    x=ac-an;
    if(lc<ln)
             x=x-1;
    else
        if(lc==ln&&zc<zn)
                  x=x-1;
    printf("\nVarsta este de %d ani\n",x);
    system("PAUSE");
    return 0;}
