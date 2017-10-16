//Se da un sir de n numere intregi alocate dinamic. Sortati crescator sirul.
#include<stdio.h>
#include<stdlib.h>
int *s,i,j,n,aux;
int main(){
    printf("n=");
    scanf("%d",&n);
    s=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
                     printf("s[%d]=",i);
                     scanf("%d",&*(s+i));
                     }
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(*(s+i)>*(s+j)){
                      aux=*(s+i);
                      *(s+i)=*(s+j);
                      *(s+j)=aux;}
    for(i=0;i<n;i++)
    printf("%d ",*(s+i));
    printf("\n");
    system("pause");}
