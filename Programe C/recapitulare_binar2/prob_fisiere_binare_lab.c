#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = fopen("fis.dat", "wb");
    char nume_produs[100];
    float pret;

    // 4mere1.5

    while (1) {
        fflush(stdin);
        fgets(nume_produs, 100, stdin);

        if (strcmp(nume_produs, "\n") == 0) {
            break;
        }

        scanf("%f", &pret);

        int len = strlen(nume_produs);

        fwrite(&len, sizeof(int), 1, f);
        fwrite(nume_produs, sizeof(char), len, f);
        fwrite(&pret, sizeof(float), 1, f);
    }

    fclose(f);

    return 0;
}
