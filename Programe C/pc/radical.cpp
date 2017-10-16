//Se da un x si trebuia sa se rezolve ceva f(x) cu o formula naspa. Nu mai stiu formula, ar trebui sa se deduca din algoritm. Daca o gasiti sa mi-o ziceti si mie. E 23:55, eu doar astept sa treaca timpul, sa se faca dimineata ca sa plec in sfarsit acasa dupa 3 luni :))
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define eps 0.0001
float r,rv,x;
int main(){
    printf("x= ");
    scanf("%f",&x);
    r=1;
    do{
        rv=r;
        r=(2*rv+x/(rv*rv))/3;
        }while(fabs(r-rv)>eps);
    printf("Rezultatul este %4.2f\n",r);
    system("PAUSE");}
