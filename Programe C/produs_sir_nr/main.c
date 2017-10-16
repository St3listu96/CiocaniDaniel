#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr,p=1;
    scanf("%d",&nr);
    while(nr!=0){
        p=p*nr;
        scanf("%d",&nr);
    }
    printf("\nProdusul numerelor este: %d",p);
    return 0;
}
