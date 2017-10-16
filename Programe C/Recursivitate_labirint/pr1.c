#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char matr[100][100],best_matr[100][100];
int best_bonus=-1;

void parcurge(int i,int j,int bonus,int n,int m){
  if(matr[i][j]=='p' || matr[i][j]=='x')
    return;

  if(matr[i][j]>='0' &&  matr[i][j] <='9')
    bonus+=matr[i][j]-'0';

  char aux = matr[i][j];
  matr[i][j]='x';
  
  if(i==0 || j==0 || i==n-1 || j==m-1){
    if(bonus>best_bonus){
      best_bonus=bonus;
      
      for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	  best_matr[i][j]=matr[i][j];
    }
  }
  else {
    parcurge(i-1,j,bonus,n,m);
    parcurge(i-1,j+1,bonus,n,m);
    parcurge(i-1,j-1,bonus,n,m);
    parcurge(i,j-1,bonus,n,m);
    parcurge(i,j+1,bonus,n,m);
    parcurge(i+1,j+1,bonus,n,m);
    parcurge(i+1,j-1,bonus,n,m);
    parcurge(i+1,j,bonus,n,m);
  }
  if(matr[i][j]=='x')
    matr[i][j]=aux;
}
  int main(){
  FILE *f;
  int i,j,n,m,bonus=0;
 f=fopen("matrice.txt","rt");
  if(!f){
    printf("Eroare la deschidere.");
    exit(EXIT_FAILURE);
  }
  i=0;
  while(fgets(matr[i],100,f)!=NULL){
    i++;
    n=i;
    m=strlen(matr[0])-1;
  }
  printf("%d ",n);
  printf("%d ",m);
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(matr[i][j]=='s')
	parcurge(i,j,bonus,n,m);
  fclose(f);
  printf("\n");
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)
      printf("%c",best_matr[i][j]);
    printf("\n");
  }
  printf("%d",best_bonus);
  return 0;
}
