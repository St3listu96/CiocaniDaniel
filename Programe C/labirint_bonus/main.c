#include <stdio.h>
#include <stdlib.h>

int best_bonus = -1;
int best_m[100][100];

void parcurge(int i,int j,int n,int m, int bonus){
    int i2,j2;
    if(m[i][j]='P'){
        return;
    }

    if(i==0 || j==0 || i == n-1 || j == m-1){
        if(bonus>best_bonus){
            best_bonus = bonus;
            for(i2=0;i2<n;i2++){
                for(j2=0;j2<m;j2++){
                    best_m[i2][j2]=

                }
            }
        }
    }

    if(m[i][j]>='0'||m[i][j]<='9'){
        bonus += m[i][j] - '0';
    }

    if(m[i][j]== '.')
        m[i][j] = 'x';

    parcurge(i-1,j,line,col,bonus);
    parcurge(i+1,j,line,col,bonus);
    parcurge(i,j-1,line,col,bonus);
    parcurge(i,j+1,line,col,bonus);
    parcurge(i-1,j-1,line,col,bonus);
    parcurge(i-1,j+1,line,col,bonus);
    parcurge(i+1,j-1,line,col,bonus);
    parcurge(i+1,j+1,line,col,bonus);

    if(bonus == 0){
        printf("Nu exista nici un drum de iesire!\n");
    }
}


int main()
{
    FILE *f;
    int m[100][100];
    f = fopen("labirint.dat","r");
    if(!f){
        printf("Eroare la deschidere fisier ! \n");
        exit(1);
    }
    int i = 0;
    while(fgets(m[i],60,f)!=NULL){
        i++;
    }



    return 0;
}
