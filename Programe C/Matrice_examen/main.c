#include <stdio.h>
#include <stdlib.h>

void afisareMatrice (int M[][100],int n){
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
    int i,j,n,k,x=0,y=0,M[100][100];
    scanf("%d",&n);
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i>j && i==j+k){
                    M[k][x]=k+1;
                    k++;
                    x++;
                }
                else if(i<j && j==i+k){
                    M[y][k]=k+1;
                    y++;
                    k++;
                }
                else
                    M[i][j]=0;
            }
        }
    }
    afisareMatrice(M,n);
}
