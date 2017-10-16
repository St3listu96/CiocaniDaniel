#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));
    int numar;
    int i;
    int contor=0;
    int suma=0;
    for(i=0;i<8;i++){
    while(1){
        numar = rand();
        if(numar==0){
            break;
        }
        else{
            contor++;
        }
    }
    numar = contor%2;
    printf("%d",numar);
    suma = suma + ((int)pow(2,7-i))*numar;
    //printf("%d",numar);
    }
    printf("\nNumarul aleator (0-256) este: %d\n",suma);
    return 0;
}
