//Se da un vector de n numere intregi. Stergeti toate elementele impare si inserati 1 dupa fiecare element egal cu 0.
#include<stdio.h>
#include<stdlib.h>
int n,s[20],s2[20];

void citire(int s[],int n){
int i;     
     for(i=0;i<n;i++){
                     printf("s[%d]= ",i);
                     scanf("%d",&s[i]);
                     s2[i]=s[i];}}
                     
                 
void afisare(int n,int a[]){
     int i;
     
     for(i=0;i<n;i++)
                     printf("%d ",a[i]);}
                     
void eliminare(int n, int a[]){
     int i,j;
     for(i=0;i<n;)
     if(a[i]%2==1){
     for(j=i;j<n-1;j++)
     a[j]=a[j+1];
     n--;}
     else
         i++;
     printf("\nSirul eliminat: ");
     afisare(n,a);}
     
void inserare(int n, int a[]){
     int i,j;
     for(i=0;i<n;i++)
     if(a[i]==0){
                 n++;
                 for(j=n-2;j>i;j--)
                 a[j+1]=a[j];
                 a[i+1]=1;}
     printf("\nSirul inserat: ");
     afisare(n,a);}
                     

int main(){
    printf("n=");
    scanf("%d",&n);
    citire(s,n);
    eliminare(n,s);
    inserare(n,s2);
    system("pause");}
