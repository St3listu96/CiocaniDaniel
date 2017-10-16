#include <stdio.h>
#include <stdlib.h>

int biti[100];

int verifica(int n,int v[100]){
    int i;
    int j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(v[i]==v[j]){
                return -1;
            }
    return 1;
}


void generare(int k,int x,int n){
    int i;
    if(k==n){
            if(verifica(n,biti)==1){
        for(i=0;i<n;i++){
                printf("%d ",biti[i]);
        }
    printf("\n");
            }
    }
    else{
        for(i=1;i<=x;i++){
            biti[k]=i;
            //if((k==0||biti[k]!=biti[k-1])&&biti[k]!=2)
            if(biti[k]!=2)
            generare(k+1,x,n);
        }
    }
}

int main()
{
    generare(0,9,3);
    return 0;
}
