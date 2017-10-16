#include <stdio.h>
#include <stdlib.h>

int conditie(int biti[],int n){
    int i;
    for(i=0;i<n-1;i++){
        if(biti[i]>biti[i+1])
            return 0;
    }
    return 1;
}

int conditie_unice(int biti[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(biti[i]==biti[j])
                return 0;
        }
    }
    return 1;
}

void generare(int k,int n,int x,int y,int biti[]){
  int i;
  if(k==n){
    if(conditie(biti,n)==1 && conditie_unice(biti,n)==1){
        for(i=0;i<n;i++){
            printf("%d ",biti[i]);
        }
        printf("\n");
    }
  }else{
    for(i=x;i<=y;i++){
        biti[k]=i;
        generare(k+1,n,x,y,biti);
    }
  }
}

int main()
{
    int biti[100];
    generare(0,2,3,6,biti);
    return 0;
}
