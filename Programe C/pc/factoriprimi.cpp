//Se da un numar. Descompuneti-l in factori primi.
#include<stdlib.h>
#include<stdio.h>
int n,i,j,k;
int main(){
    printf("n= ");
    scanf("%d",&n);
    for(i=2;n>1;i++)
    for(j=0;n%i==0;j++,n=n/i){
                              k++;
                              if(k>1)
                                     printf("* ");
                              printf("%d ",i);}                              
    printf("\n");
    system("PAUSE");}
