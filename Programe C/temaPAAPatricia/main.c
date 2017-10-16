#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int zi;
	int luna;
	int an;
}data_nasterii;

typedef struct
{
	char nume[100];
	data_nasterii dn;
	struct nod* stang;
	struct nod* drept;
}nod;

nod* rad;
FILE *f;
char nume_tanar[100];
data_nasterii data_tanar;
int gasit;

void initializare()
{
	rad = malloc(sizeof(nod));
	if(!feof(f))
	{
		fgets(rad->nume, 100, f);
		rad->nume[strlen(rad->nume) - 1] = '\0';
		//printf("%s\n", rad->nume);
		fscanf(f, "%d/%d/%d\n", &rad->dn.zi, &rad->dn.luna, &rad->dn.an);
		//printf("%d/%d/%d\n", rad->dn.zi, rad->dn.luna, rad->dn.an);
	}
	rad->drept = NULL;
	rad->stang = NULL;
}

nod* adauga(nod* p, char nume[], int an, int luna, int zi)
{
	nod* q;
	if (strcmp(p->nume,nume)==0 && p->dn.an==an && p->dn.luna==luna && p->dn.zi==zi)
	{
		printf("Persoana %s exista deja\n",nume);
		return NULL;
	}
	if (strcmp(nume,p->nume)<0)
	{
		if (p->stang == NULL)
		{
			q = malloc(sizeof(nod));
			strcpy(q->nume, nume);
			q->dn.an = an;
			q->dn.luna = luna;
			q->dn.zi = zi;
			q->drept = NULL;
			q->stang = NULL;
			p->stang = q;
			return q;
		}
		else
			adauga(p->stang,nume,an,luna,zi);
	}
	else
	{
		if (p->drept == NULL)
		{
			q = malloc(sizeof(nod));
			strcpy(q->nume, nume);
			q->dn.an = an;
			q->dn.luna = luna;
			q->dn.zi = zi;
			q->drept = NULL;
			q->stang = NULL;
			p->drept = q;
			return q;
		}
		else
			adauga(p->drept,nume,an,luna,zi);
	}

}


void inordine(nod* p)
{
	if (p)
	{
		inordine(p->stang);
		printf("%s\n%d/%d/%d\n", p->nume,p->dn.zi,p->dn.luna,p->dn.an);
		inordine(p->drept);
	}
}

void nascut_pe_data(nod* p,int an, int luna, int zi)
{
	if (p)
	{
		nascut_pe_data(p->stang, an, luna, zi);
		if (p->dn.an == an && p->dn.luna == luna && p->dn.zi == zi)
			printf("%s\n", p->nume);
		nascut_pe_data(p->drept, an, luna, zi);
	}

}

void nascut_inainte_de_data(nod* p, int an, int luna, int zi)
{
	if (p)
	{
		nascut_inainte_de_data(p->stang, an, luna, zi);
		if (p->dn.an<an)
			printf("%s\n", p->nume);
		else
		{
			if (p->dn.an == an)
			{
				if (p->dn.luna<luna)
					printf("%s\n", p->nume);
				else
				{
					if (p->dn.luna == luna)
					{
						if (p->dn.zi<zi)
							printf("%s\n", p->nume);
					}
				}
			}
		}
		nascut_inainte_de_data(p->drept, an, luna, zi);
	}
}

int inaltime(nod* p)
{
	int k = 0;
	if (p)
	{
		int st = inaltime(p->stang);
		int dr = inaltime(p->drept);
		k++;
		if (st > dr)
			k = k + st;
		else
			k = k + dr;
	}
	return k;
}

void cel_mai_tanar(nod* p)
{
	if (p)
	{
		if (p->dn.an > data_tanar.an)
		{
			strcpy(nume_tanar, p->nume);
			data_tanar = p->dn;
		}
		else
		{
			if (p->dn.an == data_tanar.an)
			{
				if (p->dn.luna > data_tanar.luna)
				{
					strcpy(nume_tanar, p->nume);
					data_tanar = p->dn;
				}
				else
				{
					if (p->dn.luna == data_tanar.luna)
					{
						if (p->dn.zi>data_tanar.zi)
						{
							strcpy(nume_tanar, p->nume);
							data_tanar = p->dn;
						}
					}
				}
			}
		}
		cel_mai_tanar(p->stang);
		cel_mai_tanar(p->drept);
	}
}

nod* min_alfabetic(nod* p)
{
	nod* curent=p;

	//frunza cea mai din stanga
	while (curent->stang != NULL)
		curent = curent->stang;

	return curent;
}

nod* max_alfabetic(nod* p)
{
	nod* curent = p;

	//frunza cea mai din dreapta
	while (curent->drept != NULL)
		curent = curent->drept;

	return curent;
}

nod* sterge_student(nod* p, char nume[])
{

	if (p == NULL)
		return p;


	if (strcmp(nume,p->nume)<0)
		p->stang = sterge_student(p->stang,nume);
	else
		if (strcmp(nume, p->nume)>0)
			p->drept= sterge_student(p->drept, nume);
		else
		{
			//nod terminal sau cu un fiu
			if (p->stang == NULL)
			{
				nod* tmp = p->drept;
				free(p);
				gasit = 1;
				return tmp;
			}
			else
				if (p->drept == NULL)
				{
					nod* tmp = p->stang;
					free(p);
					gasit = 1;
					return tmp;
				}

			//nod cu 2 fii (se cauta succesorul nodului in ordonarea arborelui in inordine - cel mai mic din subarborele drept)
			nod *tmp = min_alfabetic(p->drept);
			//nod *tmp = max_alfabetic(p->stang);
			gasit = 1;
			//se asigneaza toate campurile de informatie (nu de inlantuire) ale nodului de suprimat cu cele ale succesorului sau
			strcpy(p->nume, tmp->nume);
			p->dn = tmp->dn;

			//se suprima succesorul
			p->drept = sterge_student(p->drept,tmp->nume);
			//p->stang = sterge_student(p->stang, tmp->nume);
		}
	return p;
}

int main()
{
	char nume[100];
	int an, luna, zi;

	data_tanar.zi = 1;
	data_tanar.luna = 1;
	data_tanar.an = 1900;

	f = fopen("FisierTest.txt", "r");
	if (!f)
	{
		printf("Eroare deschidere fisier!\n");
		exit(EXIT_FAILURE);
	}
	initializare();
	while(!feof(f))
	{
		fgets(nume, 100, f);
		nume[strlen(nume) - 1] = '\0';
		fscanf(f, "%d/%d/%d\n", &zi, &luna, &an);
		adauga(rad, nume, an, luna, zi);
	}
	inordine(rad);
	printf("\n\n");
	printf("Dati o data in formatul zz/ll/aaaa: ");
	scanf("%d/%d/%d", &zi, &luna, &an);
	nascut_pe_data(rad, an, luna, zi);
	printf("\n\n");
	nascut_inainte_de_data(rad, an, luna, zi);
	printf("\n\n");
	printf("Inaltime arbore: %d\n",inaltime(rad));
	cel_mai_tanar(rad);
	printf("Cel mai tanar student: %s\n", nume_tanar);
	printf("Dati numele studentului de sters: ");
	getchar(); //pt cand avem scanf activ inainte
	scanf("%s",nume);
	printf("%s\n", nume);
	rad = sterge_student(rad, nume);
	printf("\n\n");
	if (!gasit)
		printf("Student inexistent!\n");
	else
		inordine(rad);
	fclose(f);
	return 0;
}
