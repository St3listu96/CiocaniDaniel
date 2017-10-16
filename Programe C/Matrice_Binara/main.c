#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void afisareMatrice(int **M,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,k,n;
    printf("Introduceti dimensiunea matricii:\n");
    scanf("%d",&n);
    int**M=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        M[i]=(int*)malloc(n*sizeof(int));
    }
    if(*M==NULL)
        printf("Eroare alocare memorie!");
    else
        printf("Memorie suficienta!\n");
    for(k=0;k<n;k++){
        for(i=k;i<n-k;i++){
            M[k][i]=(k+1)%2;
        }
        for(i=k+1;i<n-k;i++){
            M[i][n-k-1]=(k+1)%2;
        }
        for(i=n-k-2;i>=k;i--){
            M[n-k-1][i]=(k+1)%2;
        }
        for(i=n-k-2;i>k;i--){
            M[i][k]=(k+1)%2;
        }
    }
    afisareMatrice(M,n);
    return 0;
}
