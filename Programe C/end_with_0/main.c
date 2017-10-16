#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr,ct=0;
    printf("Introduceti numarul!\n");
    scanf("%d",&nr);
    while(nr>999999999){
        printf("\nIntroduceti un numar de maxim 9 cifre!\n");
        scanf("%d",&nr);
    }
    while(nr!=0 && nr%10==0){
        nr=nr/10;
        ct++;
    }
    if(ct==0)
        printf("\nNumarul nu are zerouri la capat!");
    else
        printf("\nNumarul de zerouri de la sfarsitul numarului este : %d",ct);
    return 0;
}
