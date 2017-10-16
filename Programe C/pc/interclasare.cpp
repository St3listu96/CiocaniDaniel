//Se dau 2 siruri de m, respectiv n numere intregi sortate crescator. Sa se combine cele 2 siruri intr-un singur sir sortat crescator.
#include<stdio.h>
#include<stdlib.h>
int k=0,a[20],b[20],c[40],m,n;
void citire(int s[],int n){
int i;     
     for(i=0;i<n;i++){
                     printf("s[%d]= ",i);
                     scanf("%d",&s[i]);}}
                     
void afisare(int s[],int n){
     int i;
     for(i=0;i<n;i++)
                     printf("%d ",s[i]);
     printf("\n");}

void interclasare(){
     int i=0,j=0,x;
     while(i<m&&j<n)
                    if(a[i]<b[j])
                                  c[k++]=a[i++];
                    else
                        c[k++]=b[j++];
    for(x=i;x<m;x++)
                    c[k++]=a[i++];
    for(x=j;x<n;x++)
                    c[k++]=b[j++];}
     
int main(){    
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    citire(a,m);
    citire(b,n);
    printf("Sirul a: ");
    afisare(a,m);
    printf("\nSirul b: ");
    afisare(b,n);
    interclasare();    
    printf("\nSirul interclasat: ");
    afisare(c,k);
    system("pause");}
