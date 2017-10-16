#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int suma(int nr, ...){
    va_list ap;
    int i;
    int sum=0;
    va_start(ap,nr);
    for(i=0;i<nr;i++){
        sum= sum + va_arg(ap,int);
    }
    va_end(ap);
    return sum;
}


int main()
{
    printf("Suma este : %d",suma(6,1,2,3,4,2,1));
    return 0;
}
