#include <stdio.h>
#include <stdlib.h>
int modulo(int n,int k){
    int m=n-((n/k)*k);
    return m;
}
int main()
{
    int nr,k;
    scanf("%d",&nr);
    scanf("%d",&k);
    printf("%d modulo %d este: %d",nr,k,modulo(nr,k));
    return 0;
}
