#include <stdio.h>
#include <stdlib.h>

int suma(int a,int b){
    return a*b;
}
main(){
    int a;
    int b;
    scanf("%d %d",a,b);
    printf("Suma este %d",suma(a,b));
    return 0;
}
