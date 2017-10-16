#include <stdio.h>
#include <stdlib.h>
#define min(x,y) ((x) < (y) ?  (x) : (y))
#define max(x,y) ((x) > (y) ?  (x) : (y))
int creeareVector(int a,int b){
    int i;
    int x=0;
    int c=min(a,b);
    int *M=malloc((abs(a-b))*sizeof(int));
    for(i=c;i<=max(a,b);i++){
        M[x]=c++;
        x++;
    }
    return M;
}

int reverseVector(int *M,int n){
    int *R=malloc(n*sizeof(int));
    int i;
    for(i=0;i<=n;i++){
        R[i]=M[abs(n-i)];
    }
    return R;
}

int sumaVector(int *M,int *N,int n){
    int *S=malloc(n*sizeof(int));
    int i;
    for(i=0;i<=n;i++){
        S[i]=M[i]+N[i];
    }
    return S;
}

int main(){
    int a,b,i;
    printf("Introduceti intervalul pe care vreti sa creati vectorul!\n");
    scanf("%d",&a);
    scanf("%d",&b);
    int *M;
    int *R;
    int *S;
    M=creeareVector(a,b);
    printf("Vectorul este: \n");
    for(i=0;i<=abs(a-b);i++){
        printf("%d\n",M[i]);
    }
    printf("Vectorul in ordine inversa este : \n");
    R=reverseVector(M,abs(a-b));
    for(i=0;i<=abs(a-b);i++){
        printf("%d\n",R[i]);
    }
    printf("Suma vectorului cu inversa lui este :\n");
    S=sumaVector(M,R,abs(a-b));
    for(i=0;i<=abs(a-b);i++){
        printf("%d\n",S[i]);
    }
    return 0;
}
