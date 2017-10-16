#include <stdio.h>
#include <stdlib.h>

int sumaNumarului(int n){
    int uc,s=0;
    while(n){
        uc=n%10;
        s=s+uc;
        n=n/10;
    }
    return s;
}
int main()
{
    int nr,i;
    scanf("%d",&nr);
    printf("\nSuma numarului %d este : %d",nr,sumaNumarului(nr));
    for(i=0;i<nr;i++){
        if(sumaNumarului(i)%2==1)
            printf("%d,",i);
    }
    return 0;
}
