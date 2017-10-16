#include <stdio.h>
#include <stdlib.h>

int pune_in_tablou(int numar,int tablou[]){
    int ct = 0;
    int i,j;
    int uc;
    while(numar){
        uc = numar %10;
        tablou[ct]=uc;
        ct++;
        numar = numar / 10;
    }
    int aux;
    for(i=0;i<ct-1;i++){
        for(j=i+1;j<ct;j++){
            if(tablou[j]<tablou[i]){
                aux = tablou[j];
                tablou[j] = tablou[i];
                tablou[i] = aux;
            }
        }
    }
    return tablou[100];
}

int lungime(int numar){
    int ct=0;
    while(numar){
        numar = numar/10;
        ct++;
    }
    return ct;
}

void backtracking(int k,int n,int numar,int biti[]){
    int i;
    int tablou[100];
    if(n==k){
        for(i=0;i<n;i++){
            printf("%d ",biti[i]);
        }
        printf("\n");
    }
    else{
        pune_in_tablou(numar,tablou);
        for(i=0;i<lungime(numar);i++){
            biti[k]= tablou[i];
            backtracking(k+1,n,numar,biti);
        }
    }

}

int main()
{
    int numar;
    int cifre[100];
    int n=0;
    int aux;
    int biti[100];
    printf("Introduceti numarul!\n");
    scanf("%d",&numar);
    aux = numar;
    while(aux){
        aux = aux/10;
        n++;
    }
    pune_in_tablou(numar,cifre);

    backtracking(0,3,numar,biti);


    return 0;
}
