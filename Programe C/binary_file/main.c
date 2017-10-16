#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nume[100];
    float pret;
    char len;

    FILE *f = fopen("fisier.dat", "wb");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului");
        exit(0);
    }

    while(1) {
        fflush(stdin);
        fgets(nume, 100, stdin);
        if (strcmp(nume, "\n") == 0) {
            break;
        }

        scanf("%f", &pret);

        len = strlen(nume) - 1;
        fwrite(&len, sizeof(char), 1, f);
        fwrite(nume, sizeof(char), len, f);
        fwrite(&pret, sizeof(float), 1, f);
    }

    fclose(f);

    f = fopen("fisier.dat", "rb");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului");
        exit(0);
    }



    while (fread(&len, sizeof(char), 1, f) == 1) {
        fread(nume, sizeof(char), len, f);
        nume[len] = '\0';
        fread(&pret, sizeof(float), 1, f);

        printf("%s %f\n", nume, pret);
    }

    fclose(f);

    return 0;
}
