#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numar_fibo {
    int numar;
    struct numar_fibo *urm;
} numar_fibo_t;

int este_fibo(int numar) {
    int fib[50];
    int i;

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < 40; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }

    for (i = 0; i < 40; i++) {
        if (numar == fib[i])
            return 1;
    }

    return 0;
}

numar_fibo_t* adauga_ordonat(numar_fibo_t* rad, int numar) {
    numar_fibo_t* nou = (numar_fibo_t*) malloc (sizeof(numar_fibo_t));
    nou->numar = numar;

    if (rad == NULL || nou->numar < rad->numar) {
        nou->urm = rad;
        return nou;
    }

    numar_fibo_t* p = rad;
    while (p->urm != NULL && nou->numar > p->urm->numar) {
        p = p->urm;
    }

    nou->urm = p->urm;
    p->urm = nou;
    return rad;
}

int exista(numar_fibo_t* rad, int numar) {
    numar_fibo_t *p = rad;
    while (p != NULL) {
        if (p->numar == numar) {
            return 1;
        }
        p = p->urm;
    }
    return 0;
}

void afisare(numar_fibo_t* p) {
    while (p != NULL) {
        printf("%d ", p->numar);
        p = p->urm;
    }
}

int main()
{
    numar_fibo_t* rad = NULL;
    char linie[1000];

    FILE *f = fopen("fisier.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschidere lui fisier.txt");
        exit(0);
    }

    while(fgets(linie, 100, f) != NULL) {
        linie[strlen(linie)-1] = '\0';

        char *cuvant = strtok(linie, ".");
        while (cuvant != NULL) {
            int numar = atoi(cuvant);
            if (este_fibo(numar)) {
                if (exista(rad, numar) == 0) {
                    rad = adauga_ordonat(rad, numar);
                }
            }
            cuvant = strtok(NULL, ".");
        }
    }

    afisare(rad);

    return 0;
}
