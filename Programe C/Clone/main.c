#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char posibilitati[] = {'a','e','i','o','u'};

int lungime(char a[]){
    int i=0;
    while(a[i]!='\0')
        i++;
    return i;
}
int main()
{
    char cuvant[20];
    char solutie[20];
    int contor=0;
    printf("Introduceti cuvantul!\n");
    scanf("%s",cuvant);

    int i,j;

    printf("\n\nClonele cuvantului '%s' sunt: \n\n",cuvant);

    for(i=0;i<lungime(posibilitati);i++){
        for(j=0;j<lungime(cuvant);j++){
            if(posibilitati[i]!=cuvant[j]){
                solutie[contor]=cuvant[j];
                contor++;
            }
        }
        solutie[contor]='\0';
        if(lungime(cuvant)!= lungime(solutie))
            printf("%s - dupa ce am scos vocala '%c',\n",solutie,posibilitati[i]);
        contor=0;
    }

    return 0;
}
