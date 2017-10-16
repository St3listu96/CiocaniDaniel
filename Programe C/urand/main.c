#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int urand(){
    int u;
    u = rand();
    u = u%2;
    return u;
}

int main()
{
    int u;
    int ch;
    while(1){
       ch = getch();
       if( ch == 13)
        break;
       else{
        u = urand();
        printf("%d",u);
       }
    }

    return 0;
}
