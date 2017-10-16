#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int biti[100];

int ordonare_despartire(int numar){
    int i,j;
    int ct=0;
    int ultima_cifra;
    int cifre[100];
    int aux;
    while(numar!=0){
        ultima_cifra = numar %10;
        cifre[ct]=ultima_cifra;
        numar = numar /10;
        ct++;
    }

    for(i=0;i<3;i++){
        printf("%d-",cifre[i]);
    }

    for(i=0;i<ct;i++){
        for(j=i+1;j<=ct;j++){
            if(cifre[i]>cifre[j]){
                aux = cifre[i];
                cifre[i]= cifre[j];
                cifre[j]=aux;
            }
        }
    }
    return *cifre;

}

void generare(int k,int n,int numar){
  int i;
  int cifre[100];
  *cifre = ordonare_despartire(numar);
  if(k==n){
    for(i=0;i<n;i++){
      printf("%d ",biti[i]);
    }
       printf("\n");
  }else{
    for(i=0;i<3;i++){
        biti[k]=cifre[i];
        generare(k+1,n,numar);
    }
  }
}




int main()
{
    /*//generare(0,2,216);
    //int cifrele[100];
    int numar;
    int uc;
    scanf("%d",&numar);
    /**cifrele = ordonare_despartire(216);
    int i;
    for(i=0;i<3;i++){

        printf("%d-",cifrele[i]);
    }

    while(numar){
        uc = numar %10;
        printf("%d-",uc);
        numar = numar / 10;
    }*/
    generare(0,2,216);
    return 0;
}
