//Se citeste un sir de n numere intregi. Sa se verifice daca este sortat si daca nu, sa se sorteze.
#include<stdio.h>
#include<stdlib.h>
void citire(int s[],int n){
int i;     
     for(i=0;i<n;i++){
                     printf("s[%d]= ",i);
                     scanf("%d",&s[i]);}}
                     
void sortare(int s[],int n){
     int i,j,aux;
     for(i=0;i<n-1;i++)
     for(j=i+1;j<n;j++)
     if(s[i]>s[j]){
                   aux=s[i];
                   s[i]=s[j];
                   s[j]=aux;}}
     
int verificare(int s[],int n){
    int i,j;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(s[i]>s[j])
                 return 0;
    return 1;}
     
void afisare(int s[],int n){
     int i;
     printf("Sirul a fost sortat: ");
     for(i=0;i<n;i++)
                     printf("%d ",s[i]);
     printf("\n");}

     
int main(){
    int n,s[20];
    printf("n=");
     scanf("%d",&n);
     citire(s,n);
     if(verificare(s,n))
                          printf("Sirul este sortat\n");
     else{
         sortare(s,n);
         afisare(s,n);}
     system("pause");}
