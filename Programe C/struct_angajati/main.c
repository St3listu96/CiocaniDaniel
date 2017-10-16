#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct data
{
	int luna, zi, an;
} data_t;

struct angajat
{
	char nume[MAX];
	unsigned int varsta:6;
	data_t data_angajarii;
	int tip_contract;
	union contract
	{
		struct det
		{
			data_t data_expirarii;
		}d;
		struct nedet
		{
			unsigned int concediu:6;
			unsigned int salariu:14;
		}n;
	}c;
}a[50];

void citire(int n)
{
	int i, aux;
	for(i=0;i<n;i++)
	{
		printf("Datele despre angajatul %d\n", i+1);
		puts("numele:");
		scanf("%s", &a[i].nume);
		puts("varsta:");
		scanf("%d", &aux);
		a[i].varsta=aux;
		puts("data angajarii sub forma zi/luna/an");
		scanf("%d/%d/%d", &a[i].data_angajarii.zi, &a[i].data_angajarii.luna, &a[i].data_angajarii.an);
		puts("Alege tipul de contract: 1 - determinat; 2 - nedeterminat");
		scanf("%d", &a[i].tip_contract);
		switch(a[i].tip_contract)
		{
			case 1:
				puts("data expirarii sub forma zi/luna/an");
				scanf("%d/%d/%d", &a[i].c.d.data_expirarii.zi, &a[i].c.d.data_expirarii.luna, &a[i].c.d.data_expirarii.an);
				break;
			case 2:
				puts("zile concediu");
				scanf("%d", &aux);
				a[i].c.n.concediu=aux;
				puts("salariu");
				scanf("%d", &aux);
				a[i].c.n.salariu=aux;
				break;
			default:
				printf("tip inexistent");
				break;
		}
	}
}

void ordonare(int n)
{
	struct angajat aux;
	int i, j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(strcmp(a[i].nume, a[j].nume)>0)
			{
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
}

void afisare(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Datele despre angajatul %d sunt: \n", i+1);
		printf("numele:");
		puts(a[i].nume);
		printf("varsta:");
		printf("%d\n", a[i].varsta);
		printf("data angajarii:");
		printf("%d/%d/%d\n", a[i].data_angajarii.zi, a[i].data_angajarii.luna, a[i].data_angajarii.an);
		printf("tipul de contract:");
		switch(a[i].tip_contract)
		{
			case 1:
				puts("contract determinat:\n data expirarii:");
				printf("%d/%d/%d\n", a[i].c.d.data_expirarii.zi, a[i].c.d.data_expirarii.luna, a[i].c.d.data_expirarii.an);
				break;
			case 2:
				printf("contract nedeterminat\n");
				printf("zile concediu:");
				printf("%d\n", a[i].c.n.concediu);
				printf("salariu:");
				printf("%d\n", a[i].c.n.salariu);
				break;
		}
		printf("\n\n");
	}
}

int main(void)
{
	int n;
	printf("Numarul de angajati?");
	scanf("%d", &n);
	citire(n);
	ordonare(n);
	afisare(n);
	return 0;
}
