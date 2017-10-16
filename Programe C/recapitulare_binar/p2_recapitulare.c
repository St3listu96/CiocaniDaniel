#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produs {
    char nume[100];
    float pret;
    int masa;
    struct produs* urm;
} produs_t;

produs_t* adauga_ordonat(produs_t* rad, char nume[100], float pret, int masa) {
    produs_t* nou = (produs_t*) malloc (sizeof(produs_t));
    strcpy(nou->nume, nume);
    nou->pret = pret;
    nou->masa = masa;

    if (rad == NULL || strcmp(nume, rad->nume) < 0) {
        nou->urm = rad;
        return nou;
    }

    produs_t* p;
    for (p = rad; p->urm != NULL && strcmp(p->urm->nume, nume) < 0; p = p->urm);

    nou->urm = p->urm;
    p->urm = nou;

    return rad;
}

void afisare(produs_t* rad) {
    produs_t* p;
    for (p = rad; p != NULL; p = p->urm) {
        printf("%s %f %d\n", p->nume, p->pret, p->masa);
    }
}

produs_t* sterge_tot(produs_t* rad) {
    produs_t *aux, *p;
    aux = rad;
    for (p = rad->urm; p != NULL; p = p->urm) {
        free(aux);
        aux = p;
    }
    free(aux);
    return NULL;
}

int main()
{
    produs_t *rad = NULL;
    char nume[100];
    float pret;
    int masa;

    FILE *f = fopen("fis.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        return 0;
    }

    while (fscanf(f, "%s%f%d", nume, &pret, &masa) == 3) {
        rad = adauga_ordonat(rad, nume, pret, masa);
    }

    rad = sterge_tot(rad);
    afisare(rad);


    return 0;
}
