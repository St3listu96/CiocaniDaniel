#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define MAX 5000

typedef struct magazin{
    char nume[36];
    int cod;
}mag_t;

mag_t produse[MAX];


void cautare(char *elem,int n){
      int s,d,m;
      int gasit;
      s=0; d=n-1; gasit=0;
      while((s<=d)&&(!gasit))
      {
        m=(s+d)/2; /*sau orice valoare cuprinsă între s şi d*/
        if(strcmp(produse[m].nume,elem)==0)
            gasit=1;
          else
            if(strcmp(produse[m].nume,elem)<0)
                s=m+1;
              else
                d=m-1;
      }
      if(gasit) {
            printf("Codul produsului '%s' este : %d\n",produse[m].nume,produse[m].cod);
      }
             else {
            printf("Elementul nu a fost gasit!\n");
      }
}

void bubblesort(mag_t a[], int n){
    int i,j; mag_t temp;
    for( i= 0; i < n; i ++){
      for( j= n-1; j>i; j--)
        if (strcmp(a[j-1].nume,a[j].nume)>0)
          {
            temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          }
    }
}

void bubblesort_asc(mag_t a[], int n){
    int i,j; mag_t temp;
    for( i= 0; i < n; i ++){
      for( j= n-1; j>i; j--)
        if (a[j-1].cod>a[j].cod)
          {
            temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          }
    }
}

void bubblesort_desc(mag_t a[], int n){
    int i,j; mag_t temp;
    for( i= 0; i < n; i ++){
      for( j= n-1; j>i; j--)
        if (a[j-1].cod<a[j].cod)
          {
            temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          }
    }
}

void aranjare_sortare(mag_t a[], int n)
{
	int i=0;
	int k =n-1;
	mag_t temp;
	for (i=0; i<k; i++) {
		while (k && (a[k].cod % 2))k--;
		if (a[i].cod % 2) {
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			k--;
		}
	}
	int j;
	for (i=0; i<k - 1; i++){
        for (j=k-1;j>i+1;j--){
			if (a[j-1].cod>a[j].cod) {
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
        }
	}


    for (i=k; i<n - 1; i++){
        for (j=n; j>i; j--){
            if (a[j-1].cod<a[j].cod) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
			}
        }
    }
}

void afisare(mag_t a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s - %d\n",a[i].nume,a[i].cod);
    }
}


int main()
{
    FILE *f;
    char name[36];
    f = fopen("produse.txt","r");
    if(!f){
        printf("Eroare deschidere fisier!\n");
        exit(1);
    }
    int i=0;
    int n;
    while(fgets(name,36,f)!= NULL){
        name[strlen(name)-1]='\0';
        strcpy(produse[i].nume,name);
        fscanf(f,"%d\n",&produse[i].cod);
        i++;
    }

    n = i;

    printf("Sortare dupa nume(crescator)!\n\n");
    bubblesort(produse,n);
    afisare(produse,n);

    printf("\nIntroduceti numele produsului pe care il cautati: ");
    fgets(name,36,stdin);
    name[strlen(name)-1]='\0';
    cautare(name,n);

    printf("\nDaca vreti sa continuati apasati ENTER..\n");
    int buton;
    while((buton=getch())!=13)
        printf("Apasati ENTER pentru a continua..\n");
    aranjare_sortare(produse,n);
    afisare(produse,n);

    return 0;
}
