#include <stdio.h>
#include <stdlib.h>

void matriceBinara (int a[][100],int n){
    unsigned i,j,k;
    for(k=0;k<=n/2;k++){
        for(j=k;j<n-k;j++)
            a[k][j]= 1;
        for(i=k+1;i<n-k;i++)
            a[i][n-k-1]=0;
        for(j=n-k-1;j>k;j--)
            a[n-k-1][j]=1;
        for(i=n-k-1;i>k;i--)
            a[i][k]=0;
}
void afisare (int a[100][100],int n,int m){ //n - linii , m - coloane
    int i,j;//i - pt linii , j-col
    for(i=0;i<n;i++){ //trecere pe linii
        for(j=0;j<n;j++){ //trecere pe coloane
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
}








}
