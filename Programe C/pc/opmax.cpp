//Se dau 2 numere intregi. Comparati-le folosind "if"-ul ala special din C.
#include<stdio.h>
#include<stdlib.h>
int a,b;
char op;
int main(){
    printf("Dati cele 2 numere:\n");
    scanf("%d %d",&a,&b);
    op=a>b?'>':a<b?'<':'=';
    printf("Rezultatul comparatiei este %d %c %d\n",a,op,b);
    system("PAUSE");
    return 0;}
