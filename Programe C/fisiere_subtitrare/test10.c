#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AUXFILE "aux1.sub"

int main(int argc , char *argv[]){
  FILE *f;
  FILE *aux;
  //char linie[100];
  //char *p;
  char subtitrare[100];
  int nr_frame_inceput;
  int nr_frame_sfs;
  char ch;

  /*while(fgets(linie,100,f)!=NULL){
    p = strtok(linie,"}");
    fprintf(aux,"{");
    //    printf("\n%s\n",p);
    nr_frame_inceput = atoi(p+1) + 75;
    //printf("%d\n",nr_frame_inceput);
    fprintf(aux,"%d\n",nr_frame_inceput);
    fprintf(aux,"}");
    p = strtok(NULL,"{");
    p = strtok(NULL,"}");
    fprintf(aux,"{");
    nr_frame_sfs = atoi(p) + 75;
    fprintf(aux,"%d",nr_frame_sfs);
    fprintf(aux,"}");
    p = strtok(NULL,"\n");
    fprintf(aux,"%s\n",p);

    }*/

  while(1){
  f = fopen("info.sub","r");

  if(!f){
    printf("Eroare la deschiderea fisierului %s!\n",argv[1]);
    exit(1);
  }

  aux = fopen(AUXFILE,"w");
  fclose(aux);

  aux = fopen(AUXFILE,"r+");

  while(fscanf(f,"{%d}{%d}",&nr_frame_inceput,&nr_frame_sfs)==2){
    nr_frame_inceput+=25;
    nr_frame_sfs+=25;
    fgets(subtitrare,50,f);
    subtitrare[strlen(subtitrare)-1]='\0';
    fprintf(aux,"{%d}{%d}%s\n",nr_frame_inceput,nr_frame_sfs,subtitrare);
  }
  fclose(f);
  remove("info.sub");
  fclose(aux);
  rename("aux1.sub","info.sub");

  printf("Press Y to continue!\n");
  ch = getch();
  if(!(ch == 'y' || ch == 'Y'))
    break;
  else{
    printf("Subtitrarea a fost decalata cu 1 secunda!\n");
  }

  }

  return 0;
}
