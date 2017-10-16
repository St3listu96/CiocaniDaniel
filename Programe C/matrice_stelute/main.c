#include <stdio.h>
#include <stdlib.h>

void afisareMatrice (char M[][100],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3c",M[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    char M[100][100],i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                M[i][j]="*";
            else if(i<j && i>=n/2)
                M[i][j]="*";
            else if(i>j && i<n/2)
                M[i][j]="*";
            else
                M[i][j]='\0';
        }
    }
    afisareMatrice(M,n);
}
