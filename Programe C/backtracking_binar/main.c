#include <stdio.h>
#include <stdlib.h>

void back(int k,int n,int biti[]){
    int i;
    if(k==n){
        for(i=0;i<n;i++){
            printf("%d ",biti[i]);
        }
        printf("\n");
    }
    else{
        biti[k]=0;
        back(k+1,n,biti);
        biti[k]=1;
        back(k+1,n,biti);

    }
}

int main()
{
    int biti[100];
    back(0,3,biti);
    return 0;
}
