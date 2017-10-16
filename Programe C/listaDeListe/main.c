#include <stdio.h>
#include <stdlib.h>

typedef struct jucatori{
    char numeJucator[50];
    double salar;
    struct jucatori *urmJ;
}Jucatori_t;

typedef struct echipa{
    char numeEchipa[20];
    Jucatori_t *urmJ;
    struct echipa *urmE;
}Echipa_t;





int main()
{
    printf("Hello world!\n");
    return 0;
}
