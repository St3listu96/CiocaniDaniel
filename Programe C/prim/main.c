#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nd=0;
    int n;
    int d;
    scanf("%d",&n);
    for(d=1;d<=n;d++)
        if(n%d==0)
        nd++;
    if(nd==2)
        printf("Numarul este prim");
    else
        printf("Numarul nu este prim");
    return 0;
}
