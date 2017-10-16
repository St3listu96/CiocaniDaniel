#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int info;
    struct Nod *urm;
}Nod_t;


Nod_t* adauga_inceput(Nod_t*l , int x){
    Nod_t *nou = (Nod_t*)malloc(sizeof(Nod_t));
    nou->info=x;
    nou->urm = l;
    return nou;
}

Nod_t* adauga_ordonat(Nod_t*l , int x){
    Nod_t *nou = (Nod_t*)malloc(sizeof(Nod_t));
    nou->info=x;
    if(l==NULL || l->info > nou->info){
        nou->urm = l;
        return nou;
    }
    Nod_t*p = l;
    while(p->urm != NULL && p->urm->info < nou->info)
        p=p->urm;
    nou->urm = p->urm;
    p->urm = nou;
    return l;
}

Nod_t* adauga_final(Nod_t *l , int x){
    Nod_t *p = l;
    Nod_t *nou = (Nod_t*)malloc(sizeof(Nod_t));
    nou->info = x;
    if(l == NULL){
        nou->urm = NULL;
        return nou;
    }
    while(p->urm !=NULL)
        p=p->urm;
    nou->urm = NULL;
    p->urm = nou;
    return l;
}

Nod_t* sterge_noduri(Nod_t *l, int x){
    Nod_t *p = l;
    if(l == NULL)
        printf("Nu poti sterge un element dintr-o lista vida ! \n");
    if(l->info == x){
        Nod_t*aux = l;
        l=l->urm;
        free(aux);
        return l;
    }

    while(p->urm != NULL){
        if(p->urm->info == x){
            Nod_t*aux = p->urm;
            p->urm = aux->urm;
            free(aux);
        } else {
        p=p->urm;
        }
    }
    return l;
}

Nod_t* cautare(Nod_t*l , int x){
    Nod_t*p = l;
    if(l==NULL)
        return NULL;
    else{
            while(p->info != x && p->urm != NULL)
                p=p->urm;
            if(p->info == x)
                return p;
            else
                return NULL;
    }
}

void afiseazaLista(Nod_t*l){
    while(l!=NULL){
        printf("%d ",l->info);
        l=l->urm;
    }
}



int main()
{
    Nod_t *rad = NULL;
    rad=adauga_inceput(rad,9);
    rad=adauga_inceput(rad,7);
    rad=adauga_inceput(rad,1);
    rad=adauga_final(rad,8);
    rad=adauga_ordonat(rad,3);
    rad=adauga_ordonat(rad,5);
    rad=adauga_ordonat(rad,8);
    rad=adauga_final(rad,100);
    rad=sterge_noduri(rad,8);
    afiseazaLista(rad);
    Nod_t* n=cautare(rad,100);
    printf("%d \n",n->info);
    return 0;
}
