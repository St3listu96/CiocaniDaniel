#include <stdio.h>
#include <stdlib.h>

void citireMatrice (int M[][100],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}

void afisareMatrice (int M[][100],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }
}

int afisareNrNegative(int M[][100],int n){
    int i,j,ct=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(M[i][j]<0)
                ct++;
        }
    }
    return ct;
}

int maxElement(int M[][100],int n,int k){
    int i,j,max=M[k][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(max<M[k][j])
                max=M[k][j];
        }
    }
    return max;

}

int maximElement(int M[][100],int n){
    int i,j,max=M[0][0];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(max<M[i][j])
                max=M[i][j];
        }
    }
    return max;
}
int main()
{
    int i,j,k,s=0,n,M[100][100];
    printf("Introduceti dimensiunea matricii\n");
    scanf("%d",&n);
    citireMatrice(M,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((j%2)==1)
                s=s+M[i][j];
        }
    }
    afisareMatrice(M,n);
    printf("\nSuma elementelor de pe coloane impare este: %d\n",s);
    printf("Exista %d numere negative\n",afisareNrNegative(M,n));
    printf("Introduceti linia k de pe care vreti sa aflati elementul maxim\n");
    scanf("%d",&k);
    while(k>n){
        printf("Introduceti un numar mai mic decat dimensiunea matricii!\n");
        scanf("%d",&k);
    }
    printf("Elementul maxim de pe linia k este : %d\n",maxElement(M,n,k));
    printf("Elementul maxim al matricii este : %d\n",maximElement(M,n));
    return 0;
}
