//Se dau 2 numere intregi. Comparati-le!
#include<stdio.h>
#include<stdlib.h>
int a,b;
char op;
int main(){
    printf("Dati numerele:\n");
    scanf("%d %d",&a,&b);
    if(a>b)
    op='>';
    else
        if(a<b)
        op='<';
        else
            op='=';
    printf("Rezultatul comparatiei este %d %c %d\n",a,op,b);
    system("PAUSE");
    return 0;}
