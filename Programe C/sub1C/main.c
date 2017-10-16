#include <stdio.h>
#include <stdlib.h>

int reprezentareInterna (int n){
    int i;
    unsigned bit=0;
    for(i=0;i<32;i++){
        bit=(n<<i)>>31;
        printf("%u",bit);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    reprezentareInterna(n);
    return 0;
}
