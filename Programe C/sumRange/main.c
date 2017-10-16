#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int sumRange(int M[100],int k,int l){
    int s=0;
    int i;
    for(i=min(k,l);i<=max(k,l);i++){
        s=s+M[i];
    }
    return s;
}

int main()
{
    int i,j,M[100]={1,2,3,4,5,6,7};
    printf("Introduceti capetii!\n");
    scanf("%d %d",&i,&j);
    printf("%d",sumRange(M,i,j));
    return 0;
}
