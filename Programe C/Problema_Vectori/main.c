#include <stdio.h>
#include <stdlib.h>
void afisareVector(int v[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ,",v[i]);
    }
}

int sumaVector(int v[],int n){
    int i,s=0;
    for(i=0;i<n;i++){
        s=s+v[i];
    }
    return s;
}

int under6(int v[],int n){
    int i,ct=0;
    for(i=0;i<n;i++){
        if(v[i]<6)
            ct++;
    }
    return ct;
}

int sumaCond(int v[],int n){
    int i,s=0;
    for(i=0;i<n;i++){
        if(v[i]%3==0)
            s=s+v[i];
    }
    return s;
}

float medieAritmeticaCond(int v[],int n){
    int i,ct=0,s=0;
    float m;
    for(i=0;i<n;i++){
        if(v[i]%3==0 || v[i]%4==2){
           s=s+v[i];
           ct++;
        }
    }
    m=(1.0*s)/ct;
    return m;
}
int main()
{
    int k=0,nr,v[100];
    float m;
    scanf("%d",&nr);
    while(nr!=4){
        v[k++]=nr;
        scanf("%d",&nr);
    }
    printf("\nNumerele sunt :");
    afisareVector(v,k);
    printf("\nSuma numerelor este : %d\n",sumaVector(v,k));
    m=(1.0*sumaVector(v,k))/k;
    printf("Media aritmetica a numerelor este : %.2f\n",m);
    printf("Sunt %d numere mai mici decat 6!\n",under6(v,k));
    printf("Suma numerelor divizibile cu 3 este : %d\n",sumaCond(v,k));
    printf("Media aritmetica a numerelor divizibile cu 3 sau care dau restul 2 la impartirea cu 4 este : %.2f ",medieAritmeticaCond(v,k));
    return 0;
}
