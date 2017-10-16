#include <stdio.h>
#include <stdlib.h>
void afisareMatrice(int **M,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",M[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j,n;
    printf("Introduceti dimensiunea matricii!\n");
    scanf("%d",&n);
    int **M=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        M[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i+j==n-1)
                M[i][j]=2;
            else if(i+j<n-1)
                M[i][j]=1;
            else
                M[i][j]=3;
        }
    }
    printf("\nMatricea este:\n");
    afisareMatrice(M,n);
    return 0;
}
