#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a) < (b) ? (b) : (a))

int main(){
    int n,i,j,a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<j && i+j<n-1)
                a[i][j]=1;
            else if(i>j && i+j>n-1)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    printf("\nMatricea este : \n \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
