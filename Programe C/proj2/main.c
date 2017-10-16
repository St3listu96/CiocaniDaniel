#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    unsigned n;
    scanf("%u",&n);
    printf("%d",(n<<1)|1);
    return 0;
}
