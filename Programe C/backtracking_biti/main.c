#include <stdio.h>
#include <stdlib.h>

/*int conditie(int biti[],int n){ ///sa existe doar doua cifre de 1 alaturate
    int i;
    int ct=0;
    for(i=0;i<n-1;i++){
        if(biti[i]==1 && biti[i+1]==1)
            ct++;
    }
    if(ct<=2)
        return 1;
    else
        return 0;
}*/

int conditie(int biti[],int n){ ///sa existe doar doua cifre de 1 alaturate
    int i;
    for(i=0;i<n-1;i++){
        if(biti[i]==1 && biti[i+1]==1 && biti[i+2]==1)
            return 0;
    }
    return 1;
}

/*int conditie(int biti[],int n){ ///sa fie unice
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(biti[i]==biti[j])
                return 0;
        }
    }
    return 1;
}

int conditie(int biti[],int n){ ///sa aibe suma egala cu ...
    int i,suma=0;
    for(i=0;i<n;i++){
        suma=suma+biti[i];
    }
    return suma;
}
*/

void backtracking(int k,int n,int biti[]){
    int i;
    if (k==n){
       if(conditie(biti,n)==1){
            for(i=0;i<n;i++)
                printf("%d ",biti[i]);
            printf("\n");
       }
    }
    else{
        biti[k]=0;
        backtracking(k+1,n,biti);
        biti[k]=1;
        backtracking(k+1,n,biti);
    }
}


int main()
{
    int biti[100];
    backtracking(0,5,biti);
    return 0;
}
