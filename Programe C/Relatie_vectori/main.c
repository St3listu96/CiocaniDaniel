#include <stdio.h>
#include <stdlib.h>

int relatieLinii (int **M,int n,int lin1,int lin2 ){
    int i;
    for(i=0;i<n;i++){
        if(M[lin1][i]>M[lin2][i])
            return 0;
    }
    return 1;
}

void citireMatrice(int **M,int lin,int col){
    int i;
    int j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("A[%d][%d]= ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}

void afisareMatrice(int **M,int lin,int col){
    int i,j;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%3d",M[i][j]);
        }
        printf("\n");
    }
}

int diferentaLinii(int **M,int *R,int n,int lin1,int lin2){
    int i;
    for(i=0;i<n;i++){
        R[i]=M[lin1][i]-M[lin2][i];
    }
    return R;
}

int main()
{
    int lin,col;
    int i;
    int *D;
    printf("Introduceti numarul de linii!\n");
    scanf("%d",&lin);
    printf("Introduceti numarul de coloane!\n");
    scanf("%d",&col);
    int **M=malloc(lin*sizeof(int*));
    for(i=0;i<lin;i++){
        M[i]=malloc(col*sizeof(int));
    }
    citireMatrice(M,lin,col);
    afisareMatrice(M,lin,col);
    if(relatieLinii(M,col,2,3)== 1)
        printf("Liniile sunt in relatie <=!\n");
    else
        printf("Liniile nu se afla in relatia <=!\n");
    diferentaLinii(M,D,lin,2,3);
    for(i=0;i<col;i++){
        printf("%d\n",D[i]);
    }
    return 0;
}
