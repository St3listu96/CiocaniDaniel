#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int nr_biti=0;
    unsigned n;
    scanf("%u",&n);
    for(i=0;i<(sizeof n)*4;i++){
        if((n>>((sizeof n-1)*4-i)&1)==1)
            nr_biti++;
    }
    printf("%d",nr_biti);
    return 0;
}
