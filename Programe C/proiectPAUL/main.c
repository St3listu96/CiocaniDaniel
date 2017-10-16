#include <stdio.h>
#include <stdlib.h>
FILE *f;
#define SIZE 1000
struct meniu {
char a;
float cost;
};

int main()
{
    char z,q,w;
    int i,o,j,k,ok;
    float s;
    char linie[SIZE];
    struct meniu bautura[]={{"Cola",5},{"Pepsi",5}};
    struct meniu mancare[]={{"Supa de pui", 3,6 },{"Gulas,", 4,5}};
    struct meniu desert[]={{"Panna Cotta",5},{"Dobos",5}};

    printf("Bine ati venit!\n");
    printf("Ce zi este astazi?\n");
    scanf("%s", &z);

    switch(z){

    case  1:
        printf("Meniul pentru azi este: \n");
        f=fopen("luni","r");
        if (!f)
            {
                perror("Eroare la deschiderea fisierului");
                exit(EXIT_FAILURE);
            }
      for (i = 0; i < 2; i++)
        {
        if (!fgets(linie, SIZE, f))
            break;
        puts(linie);
        }
        printf("Meniul zilei costa 15 lei\n");

    printf("Doriti meniul zilei? (da sau nu)");
    scanf("%s", &q);
    if(q='da')
        {printf("cate meniuri doriti?");
        scanf("%d",&o);
        s=s+o*15;
        printf("Mai doriti altceva? (da sau nu)");
        scanf("%s", &w);
        if(w='nu')
            printf("Aveti de platit: %f lei", s);
            else
            {
                if(w='da')
                {for(i=0;i<2;i++)
                printf("Daca doriti mancarea %c, care costa %f, apasati tasta %d",mancare[i].a,mancare[i].cost,i);
                for(i=0;i<2;i++)
                 {
                     j=i+2;
                printf("Daca doriti bautura %c, care costa %f, apasati tasta %d",bautura[i].a,bautura[i].cost,j);
                }
                for(i=0;i<2;i++)
                {k=i+4;
                printf("Daca doriti desertul %c, care costa %f, apasati tasta %d",desert[i].a,mancare[i].cost,k);
                }
                printf("Tastati  numarul/nummerele pe care le doriti si incheiati comanda cu apasarea tastei 0");
                while(ok!=0)
                {
                scanf("%d",&ok);
                if(ok<i)
                s=s+mancare[ok].cost;
                if((ok>=i)&&(ok<j))
                    s=s+bautura[ok].cost;
                if((ok>=j)&&(ok<k))
                    s=s+desert[ok].cost;
                }
                printf("Aveti de platit: %f lei",s);}
                    else
                    printf("Nu ati introdus un raspuns corect");
            }


        }
    else
        {if (q='nu')
        {s=s+0;
        printf("Ce doriti?\n");
        for(i=0;i<2;i++)
                printf("Daca doriti mancarea %c, care costa %f, apasati tasta %d",mancare[i].a,mancare[i].cost,i);
                for(i=0;i<2;i++)
                 {
                     j=i+2;
                printf("Daca doriti bautura %c, care costa %f, apasati tasta %d",bautura[i].a,bautura[i].cost,j);
                }
                for(i=0;i<2;i++)
                {k=i+4;
                printf("Daca doriti desertul %c, care costa %f, apasati tasta %d",desert[i].a,mancare[i].cost,k);
                }
                printf("Tastati  numarul/nummerele pe care le doriti si incheiati comanda cu apasarea tastei 0");
                while(ok!=0)
                {
                scanf("%d",&ok);
                if(ok<i)
                s=s+mancare[ok].cost;
                if((ok>=i)&&(ok<j))
                    s=s+bautura[ok].cost;
                if((ok>=j)&&(ok<k))
                    s=s+desert[ok].cost;
                }
                printf("Aveti de platit: %f lei",s);}
        else
            printf("Nu ati introdus un raspuns corect");
        }













































        break;

    case  'marti':
        f=fopen("marti","r");
        break;
    case  'miercuri':
        f=fopen("miercuri","r");
        break;
    case  'joi':
        f=fopen("joi","r");
        break;
    case  'vineri':
        f=fopen("vineri","r");
        break;
    case  'sambata':
        printf("Nu este meniu sambata!\n");
        break;
    case  'duminica':
        printf("Nu este meniu duminica!\n");
        break;
    }

    return 0;
}
