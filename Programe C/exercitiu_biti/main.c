#include <stdio.h>
#include <stdlib.h>

int bit1(int nr){
    if((nr&15)==15)
        return 1;
    else
        return 0;
}
int main()
{
    int nr,v1[50],v2[50],k=0,l=0,i;
    scanf("%d",&nr);
    while(nr!=0){
        if(bit1(nr))
            v1[k++]=nr;
        else
            v2[l++]=15|nr;
        scanf("%d",&nr);
    }
    printf("\nAvem %d numere: ",k);
    for(i=0;i<k;i++){
        printf("%0x, ",v1[i]);
    }
    printf("\nNumerele setate sunt: ");
    for(i=0;i<l;i++){
        printf("%0x, ",v2[i]);
    }
    return 0;
}
