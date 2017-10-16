//Se dau 3 numere intregi. Gasiti maximul dintre ele folosind "if"-ul specific C-ului.
#include<stdio.h>
#include<stdlib.h>
int a,b,c,max;
int main(){
    printf("Dati cele 3 numere:\n");
    scanf("%d %d %d",&a,&b,&c);
    max=a>b?max=a>c?a:c:max=b>c?b:c;
    printf("Maximul este egal cu %d\n",max);
    system("PAUSE");
    return 0;}
