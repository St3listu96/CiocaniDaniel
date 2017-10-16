#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cota1,cota2,cota3;
    float cot1[20],cot2[20],cot3[20];
    float cotafinala;
    float cotaDorita;
    float aux;
    int ct=0;
    int i,j,z;
    FILE *f;
    f = fopen("cote.txt","r");
    if(!f){
        printf("Eroare deschidere fisier.\n");
        exit(1);
    }

    fscanf(f,"%f",&cotaDorita);

    while(!feof(f)){
        fscanf(f,"%f %f %f",&cota1,&cota2,&cota3);
        cot1[ct]=cota1;
        cot2[ct]=cota2;
        cot3[ct]=cota3;
        ct++;
    }

    for(i=0;i<ct;i++){
        for(j=0;j<ct;j++){
            for(z=0;z<ct;z++){
                if(i!=j){
                    cotafinala=cot1[i]*cot2[j];
                    aux=cotafinala;
                    cotafinala-=cotaDorita;
                    if(cotafinala<0)
                        cotafinala*=-1;
                    if(cotafinala < 0.5)
                        printf("%4f (%d %d) - (i,j)\n",aux,i,j);
                }
                if(j!=z){
                    cotafinala=cot2[j]*cot3[z];
                    aux = cotafinala;
                    cotafinala-=cotaDorita;
                    if(cotafinala<0)
                        cotafinala*=-1;
                    if(cotafinala < 0.5)
                        printf("%4f (%d %d) - (j,z)\n",aux,j,z);
                }
                if(i!=z){
                    cotafinala=cot1[i]*cot3[z];
                    aux = cotafinala;
                    cotafinala-=cotaDorita;
                    if(cotafinala<0)
                        cotafinala*=-1;
                    if(cotafinala < 0.5)
                        printf("%4f (%d %d) - (i,z)\n",aux,i,z);
                }

            }
        }
    }

    return 0;
}
