#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <windows.h>

int orizontal=0,vertical=0;

void spatii(int orizontal){
    int i;
    for(i=0;i<orizontal;i++){
        printf(" ");
    }
}
void enter(int vertical){
    int i;
    for(i=0;i<vertical;i++){
        printf("\n");
    }
}

void afiseazaCuvant(){
printf( "       _________\n");spatii(orizontal);
printf( "       ____^____\n" );spatii(orizontal);
printf( " L   _/      [] \\ \n" );spatii(orizontal);
printf( " O ==_           \\ \n");spatii(orizontal);
printf( " L    \___________] \n");spatii(orizontal);
printf( "         I     I \n");spatii(orizontal);
printf( "       ----------/\n");spatii(orizontal);

}

int main()
{
    int buton;

    while(1){

        buton = getch();

        if(buton == 97)
            orizontal--;
        if(buton == 100)
            orizontal++;
        if(buton == 115)
            vertical++;
        if(buton == 119)
            vertical--;
        system("cls");
        enter(vertical);
        spatii(orizontal);
        afiseazaCuvant();
        if(buton == 13){
            printf("Speram ca v-ati distrat ! \n");
            break;
        }
    }

    return 0;
}
