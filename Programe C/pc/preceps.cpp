//Nu mai stiu exact ce facea asta. Parca era o metoda de a calcula sin(x) facand o suma. Prima valoare afisata este sin(x) prin acea metoda si a doua este sin(x) folosind functia sin din biblioteca math.h
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 0.0001
int n,i=1;
float x,t,s;
int main(){
    printf("x=");
    scanf("%f",&x);
    t=x;
    s=x;
    do{
        t=-t*((x*x)/((2*i)*(2*i+1)));
                      s=s+t;
                      i++;
                      }while(fabs(t)>=EPS);
    printf("Suma este %f\n",s);
    printf("sin(%4.2f)= %f",x,sin(x));
    system("pause");}
