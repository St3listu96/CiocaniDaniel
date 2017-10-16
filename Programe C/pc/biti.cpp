//tiparirea in biti a unui numar hexa
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
unsigned int x,m;
int k,i;
int main(){
    printf("x=");
    scanf("%x",&x);
    m=1;
    k=0;
    
    for(i=31;i>=0;i--){
                      if((x>>i)&m)
                             printf("1");
                      else
                             printf("0");
                      if(i%4==0)
                      printf(" ");}
                      
    printf("\n");    
    system("pause");
    return 0;}
