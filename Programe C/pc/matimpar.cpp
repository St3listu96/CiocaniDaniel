//Se da o matrice M x N numere intregi. Numarati cate elemente au toti vecinii numere pare (vecinul de deasupra, de sub, din stanga si dreapta).
#include<stdio.h>
#include<stdlib.h>
int m,n,k,i,j,a[20][20];
int main(){
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++){
                      printf("a[%d][%d]=",i,j);
                      scanf("%d",&a[i][j]);}
    for(i=1;i<=m;i++){
                      for(j=1;j<=n;j++)
                                       printf("%4d ",a[i][j]);
                      printf("\n");}
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(!(a[i][j-1]%2||a[i][j+1]%2||a[i-1][j]%2||a[i+1][j]%2))
    k++;
    printf("Sunt %d elemente cu toti vecinii numere pare\n",k);
    system("pause");}
