#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<2*n;i++){
        for(j=0;j<2*n;j++){
            if(i>=j)
                printf("*");
            if(j>=n/2 && j<=i)
                printf("*");
        }
    printf("\n");
}
}
