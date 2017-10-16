#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void oglindire(char *tab,int n){
    int i;
    int aux;
    for(i=0;i<n/2;i++){
        aux= tab[i];
        tab[i]= tab[n-1-i];
        tab[n-1-i] = aux;
    }
}

void preKmp( char* pattern , int pattern_length, int kmpNext[] ){
     int i , j;
     i = 0;
     j = -1;
     kmpNext[ 0 ] = -1;
     while ( i < pattern_length )
     {
         while ( j > -1 && pattern[ i ] != pattern[ j ] )
             j = kmpNext[ j ];
         i++;
         j++;
         if ( pattern[ i ] == pattern[ j ] )
             kmpNext[ i ] = kmpNext[ j ];
         else
             kmpNext[ i ] = j;
     }
 }


void knuth_morris_pratt(char* pattern , int pattern_length , char* source , int source_length){
     int i , j;
     int kmpNext[ 1024 ];
     preKmp( pattern , pattern_length , kmpNext );
     i = 0;
     j = 0;
     while ( j < source_length )
     {
         while ( i>-1 && pattern[i] != source[j] )
             i = kmpNext[i];
         i++;
         j++;
         if ( i >= pattern_length )
         {
             printf( "Gasit la pozitia %d\n" , j - i );
             i = kmpNext[i];
         }
     }
 }

int main(int nrArg,char *arg[]){
    FILE *f;
    char *numefisier = arg[1];
    char S0[10000];
    char S1[32];
    char c;
    f = fopen(numefisier,"r");
    if(!f){
        printf("Error opening file '%s'.\n",numefisier);
        exit(1);
    }
    int i=0;
    while(!feof(f)){
        c=fgetc(f);
        S0[i]=c;
        i++;
    }
    int nr_caractere = i;

    fclose(f);

    /*for(i=0;i<nr_caractere;i++){
        printf("%c",S0[i]);
    }*/

    printf("Introduceti modelul.\n");

    i=0;
    while((c=getchar())!='\n'){
        S1[i]=c;
        i++;
    }

    int nr_caractere2=i;

    printf("Oglinditul cuvantului '%s' este : '",S1);
    oglindire(S1,i);

     for(i=0;i<nr_caractere2;i++){
        printf("%c",S1[i]);
    }
    printf("'\n");

    printf("\nDaca vreti sa continuati apasati ENTER..\n");
    int buton;
    while((buton=getch())!=13)
        printf("Apasati ENTER pentru a continua..\n");

    knuth_morris_pratt(S1,nr_caractere2,S0,nr_caractere);


    return 0;
}
