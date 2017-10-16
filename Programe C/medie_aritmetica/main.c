#include <stdio.h>
#include <stdlib.h>

float medieAritmetica (int n, int *v){
    float ma=0;
    int i;
    for(i=0;i<n;i++){
        ma=(ma+v[i])*0.5;
    }
    return ma;
}


int main()
{
    int v[]={8,8,8,6};
    printf("Media aritmetica este %f",medieAritmetica(4,v));
    return 0;
    }
