#include <stdio.h>
#include <stdlib.h>

void reprezentareInterna (int n){
    int i;
    unsigned bit;
    for(i=0;i<32;i++){
        bit=(n<<i)>>31;
        printf("%u",bit*(-1));
    }
}

int main()
{
    unsigned a,b,aux1,aux2;
    unsigned c;
    printf("Introduceti numarul a :\n");
    scanf("%d",&a);
    printf("Introduceti numarul b :\n");
    scanf("%d",&b);
    aux1=a&0xF;
    aux2=(b<<4)&0xF0;
    c=aux1|aux2;
    printf("Reprezentarea interna a lui a este : \n");
    reprezentareInterna(a);
    printf("\n");
    printf("Reprezentarea interna a lui b este : \n");
    reprezentareInterna(b);
    printf("\n");
    printf("Reprezentarea interna a lui c este : \n");
    reprezentareInterna(c);
    printf("\n");
    return 0;
}
