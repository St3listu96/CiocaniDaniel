#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union User
{
    int nume[100];
    int parola[100];
};

int main(int argc, char *argv[])
{
    union User user;
    int k=0;
    int i;
    if (argc==5)
    {
        if (strcmp(argv[1], "-u")==0 && strcmp(argv[3], "-p")!=0)
        {
            printf("Ati introdus comanda gresita.\n");
        }
        else if(strcmp(argv[1], "-u")!=0)
        {
            printf("Argumente incorecte.\n");
        }
        else
        {
            for (i=1;i<=k;i++)
            {
                if (strcmp(argv[2], user.nume[i])==0 && strcmp(argv[4], user.parola[i])==0)
                {
                    printf("Logare reusita.\n");
                }
            }

        }
    }
    else if (argc==6)
    {
        if (strcmp(argv[1],"-a")==0 && strcmp(argv[2],"-u")!=0 || strcmp(argv[4], "-p")!=0)
        {
            printf("Comanda de adaugare este gresita.\n");
        }
        else if(strcmp(argv[1], "-a")!=0)
        {
            printf("Argumente incorecte.\n");
        }
        else
        {
            k++;
            user.nume[k]=atoi(argv[3]);
            printf("Numele introdus:%d\n", user.nume[k]);
            user.parola[k]=atoi(argv[5]);
            printf("Parola introdusa:%d\n", user.parola[k]);
            printf("\n");
            for (i=1;i<=k;i++)
            {
                printf("Nume:%d;    Parola:%d.\n",user.nume[i],user.parola[i]);
            }
        }
    }
    else if (argc==4)
    {
        if (strcmp(argv[1], "-d")==0 && strcmp(argv[2], "-u")!=0)
        {
            printf("Comanda de sterge este gresita.\n");
        }
        else if(strcmp(argv[1], "-d")!=0)
        {
            printf("Argumente incorecte.\n");
        }
        else
        {

        }
    }
    else
    {
        printf("Numar incorect de argumente introduse.\n");
    }
}
