#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<n;i++){
        if((n%i==0) && (i-(n/i)==1 || i-(n/i)==-1))
            printf("%dx%d,",i,(n/i));
    }
    return 0;
}
