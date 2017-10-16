#include <stdio.h>
#include <stdlib.h>

int suma(int a ,int b){
    return a+b;
}
main ()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d",suma(a,b));
}
