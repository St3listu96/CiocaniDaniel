//Se da o matrice patratica de N x N numere intregi. Verificati daca este simetrica si calculati suma elementelor de deasupra diagonalei principale.
#include<stdio.h>
#include<stdlib.h>
int n,a[20][20],s,i,j,sim=1;
int main(){
    printf("n=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
                     printf("a[%d][%d]=",i,j);
                     scanf("%d",&a[i][j]);}
    for(i=1;i<n&&sim==1;i++)
    for(j=0;j<i&&sim==1;j++)
    if(a[i][j]!=a[j][i])
                         sim=0;
    for(i=0;i<n;i++){
    for(j=0;j<n;j++)
                    printf("%4d ",a[i][j]);
    printf("\n");}
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    s=s+a[i][j];
    if(sim==0)
    printf("Matricea nu este simetrica\n");
    else
    printf("Matricea este simetrica\n");
    printf("Suma este egala cu %d\n",s);
    system("pause");}                     
