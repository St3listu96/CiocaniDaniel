#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f;
    char echipa1[100];
    char echipa2[100];
    int gol_echipa1;
    int gol_echipa2;
    char linie[100];
    char ch;
    f = fopen("meciuri.txt","r");
    if(!f){
        printf("Eroare la deschiderea fisierului 'test.txt'!\n");
        exit(1);
    }

    ///Prima data citesc cu fscanf .. (citeste pana la primul spatiu)

    fscanf(f,"%s %s %d %d\n",echipa1,echipa2,&gol_echipa1,&gol_echipa2);
    printf("Scor final : %s %d - %d %s",echipa1,gol_echipa1,gol_echipa2,echipa2);

    ///Acum citesc cu fgets .. (citeste pana la primul \n sau cate caractere ii zici tu.. in cazul nostru  )
    fgets(linie,60,f); ///salvezi in "linie" 60 de caractere sau pana la intalnirea caracterului \n
    ///Ultimul caracter din "linie" este \n
    printf("\nScor final : %s",linie);
    ///Ca sa scoti caracterul \n inlocuiesti ultimul caracter cu '\0' (linie[strlen(linie)-1] = '\0')

    ///Acum citim cu fgetc
    int i=0;
    while(1){
       ch = fgetc(f);  ///citeste un caracter din fisierul 'f' si il pune in 'ch'

       if(ch != ' '){
            echipa1[i]= ch;
            i++;
        }
       else{
            echipa1[i]='\0';
            break;
       }
    }
    printf("%s",echipa1); ///am citit prima echipa cu fgetc


    return 0;
}
