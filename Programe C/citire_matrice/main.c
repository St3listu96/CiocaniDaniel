#include <stdio.h>
#include <stdlib.h>
void citireMatrice(int M[][100],int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}
void afisareMatrice(int M[][100],int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }


}
int main(){
    int m,n,M[100][100];
    printf("Introduceti numarul de linii\n");
    scanf("%d",&n);
    printf("Acum numarul de coloane\n");
    scanf("%d",&m);
    citireMatrice(M,n,m);
    afisareMatrice(M,n,m);
}
