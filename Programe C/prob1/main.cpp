#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct produs {
    char nume[100];
    float pret;
    int kg;
    struct produs *urm;
} produs_t;

int cmp (const void* a, const void* b) {
    produs_t* p1 = (produs_t *)a;
    produs_t* p2 = (produs_t *)b;
    return strcmp(p1->nume, p2->nume);
}

produs_t* adauga_ordonat(produs_t* rad, char nume[], float pret, int kg) {
    produs_t* nou = (produs_t*) malloc (sizeof(produs_t));
    strcpy(nou->nume, nume);
    nou->pret = pret;
    nou->kg = kg;

    if (rad == NULL || strcmp(nou->nume, rad->nume) < 0) {
        nou->urm = rad;
        return nou;
    }

    produs_t* p = rad;
    while (p->urm != NULL && strcmp(nou->nume,p->urm->nume) > 0) {
        p = p->urm;
    }

    nou->urm = p->urm;
    p->urm = nou;
    return rad;
}

int main(void)
{
    produs_t* rad = NULL;

    FILE *f = fopen("fisier.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschidere lui fisier.txt");
        exit(0);
    }

    int i = 0;
    char nume[100];
    float pret;
    int kg;

    int kg_sacosa = 25;

    while (fscanf(f, "%s %f %d", nume, &pret, &kg) == 3) {
        if (kg <= kg_sacosa) {
            rad = adauga_ordonat(rad, nume, pret, kg);
            kg_sacosa = kg_sacosa - kg;
            i++;
        }
    }
    int n = i;

    //qsort(p, n, sizeof(produs_t), cmp);


    produs_t* p = rad;
    for (i = 0; i < n; i++) {
        printf("%s %d\n", p->nume, p->kg);
        p = p->urm;
    }

    fclose(f);

	return 0;
}
