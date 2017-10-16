//Se da un numar n. Construiti un numar binar cu n 1-uri la final (Sau ceva de genul ala).
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
unsigned int m,x,m2;
int n,i;
int main(){
    printf("n=");
    scanf("%d",&n);
    x=1;
    m=0;
    for(i=1;i<=n;i++){
                      m=m|x;
                      x=x<<1;}
    m2=1;
    for(i=31;i>=0;i--){
                      if((m>>i)&m2)
                             printf("1");
                      else
                             printf("0");
                      if(i%4==0)
                      printf(" ");}                         
    printf("\n");    
    system("pause");
    return 0;}
