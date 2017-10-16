#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eliminareCifre(int n,int c){
    int uc,ct=0,nr=0;
    while(n){
        if(n%10!=c){
            uc=n%10;
            nr=nr+((int)(pow(10,ct)+0.5)*uc);
            ct++;
        }
        n=n/10;
    }
    return nr;
}
int main()
{
    int nr,c;
    printf("Introduceti numarul!\n");
    scanf("%d",&nr);
    printf("\nIntroduceti cifra care vreti sa fie eliminata!\n");
    scanf("%d",&c);
    printf("Numarul dupa ce eliminam cifra este : %d",eliminareCifre(nr,c));
    return 0;
}
