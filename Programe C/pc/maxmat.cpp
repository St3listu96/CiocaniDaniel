//Se da o matrice de M x N numere reale. Construiti un vector avand N elemente, fiecare element i fiind maximul de pe coloana i a matricii.
#include<stdio.h>
#include<stdlib.h>
float b[20],max,a[20][20];
int i,j,m,n,k;
int main(){
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    for(i=0;i<m;i++)
    for(j=0;j<n;j++){
                     printf("a[%d][%d]=",i,j);
                     scanf("%f",&a[i][j]);}
    for(i=0;i<m;i++){
    for(j=0;j<n;j++)
                    printf("%8.2f",a[i][j]);
    printf("\n");}
    for(i=0;i<n;i++){
                     max=a[i][1];
                     for(j=0;j<m;j++)
                                     if(a[j][i]>max)
                                                    max=a[j][i];
                     b[k++]=max;}
    printf("\n");
    for(i=0;i<k;i++)
    printf("%8.2f",b[i]);
    system("pause");}
