#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define FNAME "date.txt"
#define FADMINNAME "admin.txt"

typedef struct{
  int id;
  int pass;
  char nume[100];
  char prenume[100];
  double suma;
  int id_admin;
  int pass_admin;
  char nume_admin[100];
  char prenume_admin[100];
}banca_t;


int existaUser(banca_t *date,unsigned id,unsigned pass,int n){
    int i;
	for(i=0;i<n;i++){
		if(date[i].id == id && date[i].pass == pass){
		   		       return i;
		}
  	}
	return -1;
}

int existaAdmin(banca_t *date,unsigned id,unsigned pass,int n){
    int i;
	for(i=0;i<n;i++){
		if(date[i].id_admin == id && date[i].pass_admin == pass){
		   		       return i;
		}
  	}
	return -1;
}

/*int existaID(banca_t *date,unsigned id,int n){
  int i;
  if(verificaID(id))
    for(i=0;i<n;i++){
      if(date[i].id == id)
	return i;
    }
  return -1;
}*/

int main(){
  char ch;
  char id2[2];
  char pass2[4];
  unsigned int id;
  unsigned int pass;
  unsigned int i=0;
  unsigned linie=0;
  //int countLine=0;
  int optiune;
  int aux=-1;;
  int aux_admin=-1;
  int save=-1;
  int ct=0;
  int contor=0;
  double add;
  double rtgr;
  char nume[21];
  char prenume[21];
  char nume_cautat[21];
  char prenume_cautat[21];
  //char line[60];
  //banca_t *date=malloc(sizeof(*date));
  banca_t date[100];
  printf("Te rugam sa te loghezi!\n");
  printf("Introduceti ID-ul!\n");
  while(1){
    ch = getch();
    if((ch==ENTER && (i==1 || i==2)) || (ch == TAB && (i==1 || i==2))){
        id2[i] = '\0';
        break;
    }
    else if(ch == BKSP){
        if(i>0){
            i--;
            printf("\b \b");
        }
    }else if((ch>47 && ch<58) && i<2){
        id2[i++] = ch;
        printf("*");
    }
  }
  id = atoi(id2);
  printf("\nIntroduceti parola!\n");
  i=0;
  while(1){
    ch = getch();
    if((ch==ENTER && i==4) || (ch == TAB && i==4)){
        pass2[i] = '\0';
        break;
    }
    else if(ch == BKSP){
        if(i>0){
            i--;
            printf("\b \b");
        }
    }else if((ch>47 && ch<58) && i<4){
        if(i==0 && ch == 48)
            printf("\b");
        else{
        pass2[i++] = ch;
        printf("* \b");
        }
    }
  }
  pass = atoi(pass2);

  FILE *f;
  FILE *admin;
  //FILE *aux_file;
  f= fopen(FNAME,"r+");
  if(!f){
    printf("\nEroare deschidere fisier date.txt!\n");
    exit(EXIT_FAILURE);
  }
  admin=fopen(FADMINNAME,"r");
  if(!admin){
    printf("\nEroare deschidere fisier admin.txt!\n");
    exit(EXIT_FAILURE);
  }

  while(fscanf(admin,"%d %d %s %s",&date[ct].id_admin,&date[ct].pass_admin,date[ct].nume_admin,date[ct].prenume_admin) ==4){
    ct++;
    }

    fclose(admin);

  while(fscanf(f,"%d %d %s %s %lf",&date[linie].id,&date[linie].pass,date[linie].nume,date[linie].prenume,&date[linie].suma)==5){
    linie++;
    }

  if(existaUser(date,id,pass,linie)!=-1)
    aux = existaUser(date,id,pass,linie);
  if(existaAdmin(date,id,pass,linie)!=-1){
    aux_admin = existaAdmin(date,id,pass,linie);
  if(aux_admin != -1){
    printf("\nBun venit, admin %s %s!\n",date[aux_admin].nume_admin,date[aux_admin].prenume_admin);
    do{
      printf("\n1.Afiseaza toti userii\n2.Afiseaza userii cu un anumit nume\n3.Afiseaza userii cu un anumit prenume\n4.Afiseaza soldul unui anumit user\n5.Adaugare user nou\n6.Stergere user\n7.Alimentare sold user\n8.Retragere sold user\n\n\n9.Exit \n");
      printf("Alegeti optiunea!\n");
      linie = 0;
      f= fopen(FNAME,"r+");
      while(fscanf(f,"%d %d %s %s %lf",&date[linie].id,&date[linie].pass,date[linie].nume,date[linie].prenume,&date[linie].suma)==5){
        linie++;
      }
      fclose(f);
      scanf("%d",&optiune);

      switch(optiune){

      case 1:
        printf("Exista %d useri, iar acestia sunt : \n",linie);
        for(i=0;i<linie;i++){
            printf("%s %s\n",date[i].nume,date[i].prenume);
        }
         break;

      case 2:
	printf("Introduceti numele cautat!\n");
	scanf("%s",nume_cautat);
	for(i=0;i<strlen(nume_cautat);i++){
	  nume_cautat[i]=(char)toupper((char)nume_cautat[i]);
	}
	contor = 0;
	for(i=0;i<linie;i++){
        if(strcmp(date[i].nume,nume_cautat)!=0)
            contor++;
	}
	if(contor == linie)
        printf("Nu exista useri cu acest nume!\n");
    else{
	printf("Userii cu numele %s sunt : \n",nume_cautat);
	for(i=0;i<linie;i++){
	  if(strcmp(date[i].nume,nume_cautat)==0){
	    printf("%s %s\n",date[i].nume,date[i].prenume);
          }
	}
    }
	break;

      case 3:
	printf("Introduceti prenumele cautat!\n");
	scanf("%s",prenume_cautat);
	for(i=0;i<strlen(prenume_cautat);i++){
	  prenume_cautat[i]=(char)toupper((char)prenume_cautat[i]);
	}
    contor = 0;
	for(i=0;i<linie;i++){
        if(strcmp(date[i].prenume,prenume_cautat)!=0)
            contor++;
	}
	if(contor == linie)
        printf("Nu exista useri cu acest prenume!\n");
    else{
        printf("Userii cu prenumele %s sunt :\n",prenume_cautat);
        for(i=0;i<linie;i++){
            if(strcmp(date[i].prenume,prenume_cautat)==0){
                printf("%s %s\n",date[i].nume,date[i].prenume);
            }
        }
    }
	break;

      case 4:
    contor = 0;
	printf("Introduceti numele cautat!\n");
	scanf("%s",nume_cautat);
	printf("Introduceti prenumele cautat!\n");
	scanf("%s",prenume_cautat);
	for(i=0;i<strlen(nume_cautat);i++){
	  nume_cautat[i]=(char)toupper((char)nume_cautat[i]);
	}
	for(i=0;i<strlen(prenume_cautat);i++){
	  prenume_cautat[i]=(char)toupper((char)prenume_cautat[i]);
	}
	for(i=0;i<linie;i++){
	  if(strcmp(date[i].nume,nume_cautat)==0&&strcmp(date[i].prenume,prenume_cautat)==0)
	    printf("Soldul userului cautat este : %.2lf\n",date[i].suma);
	}
	for(i=0;i<linie;i++){
	  if(strcmp(date[i].nume,nume_cautat)!=0&&strcmp(date[i].prenume,prenume_cautat)!=0)
	    contor++;
	}
	if(contor==linie)
	  printf("Nu exista userul cautat!\n");
	break;

     case 5:

	printf("Introduceti ID-ul userului nou!\n");
	scanf("%d",&id);
	printf("Introduceti PASS-ul userului nou!\n");
	scanf("%d",&pass);
    printf("Introduceti numele userului nou!\n");
	scanf("%s",nume);
	printf("Introduceti prenumele userului nou!\n");
	scanf("%s",prenume);
	for(i=0;i<strlen(nume);i++){
            nume[i]=(char)toupper((char)nume[i]);
        }
    for(i=0;i<strlen(prenume);i++){
            prenume[i]=(char)toupper((char)prenume[i]);
        }
	fseek(f,0,SEEK_END);
	fprintf(f,"%2d %4d %5s %s 0\n",id,pass,nume,prenume);
	date[linie].id = id;
	date[linie].pass = pass;
	strcpy(date[linie].nume,nume);
	strcpy(date[linie].prenume,prenume);
	date[linie].suma = 0.0;
	linie++;
	f= fopen(FNAME,"w");
      for(i=0;i<linie;i++){
        fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
      }
    fclose(f);
    printf("Userul a fost adaugat cu succes!\n");

	break;
     case 6:
        save = -1;
        printf("Introduceti numele userului ce vreti sa fie sters !\n");
        scanf("%s",nume_cautat);
        printf("Introduceti prenumele userului ce vreti sa fie sters !\n");
        scanf("%s",prenume_cautat);
        for(i=0;i<strlen(nume_cautat);i++){
            nume_cautat[i]=(char)toupper((char)nume_cautat[i]);
        }
        for(i=0;i<strlen(prenume_cautat);i++){
            prenume_cautat[i]=(char)toupper((char)prenume_cautat[i]);
        }
        for(i=0;i<linie;i++){
            if(strcmp(date[i].nume,nume_cautat)==0 && strcmp(date[i].prenume,prenume_cautat)==0)
                save = i;
        }

        if(save != -1){
            f= fopen(FNAME,"w");
            for(i=0;i<linie;i++){
                if(save!=i)
                    fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
            }
            fclose(f);
            printf("Userul a fost sters cu succes!\n");
            }

        else
           printf("Userul nu a fost gasit! \n");
        break;

     case 7:
     contor = 0;
     printf("Introduceti numele userului pentru alimentare sold!\n");
     scanf("%s",nume);
     printf("Introduceti prenumele userului pentru alimentare sold!\n");
     scanf("%s",prenume);
     for(i=0;i<strlen(nume);i++){
        nume[i]=(char)toupper((char)nume[i]);
     }
     for(i=0;i<strlen(prenume);i++){
        prenume[i]=(char)toupper((char)prenume[i]);
     }
     for(i=0;i<linie;i++){
	  if(strcmp(date[i].nume,nume)!=0&&strcmp(date[i].prenume,prenume)!=0)
	    contor++;
	 }
    if(contor==linie)
        printf("Nu exista userul cautat!\n");
    else{
        printf("Introduceti suma cu care vreti sa alimentati soldul!\n");
        scanf("%lf",&add);
        if(add<0)
            add*=-1;
        for(i=0;i<linie;i++){
            if(strcmp(date[i].nume,nume)==0 && strcmp(date[i].prenume,prenume)==0)
                date[i].suma+=add;
     }
      f= fopen(FNAME,"w");
            for(i=0;i<linie;i++){
                fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
            }
            fclose(f);
      printf("Soldul userului a fost alimentat cu succes!\n");
    }
    break;

     case 8:
         contor = 0;
     printf("Introduceti numele userului pentru retragere sold!\n");
     scanf("%s",nume);
     printf("Introduceti prenumele userului pentru retragere sold!\n");
     scanf("%s",prenume);
     for(i=0;i<strlen(nume);i++){
        nume[i]=(char)toupper((char)nume[i]);
     }
     for(i=0;i<strlen(prenume);i++){
        prenume[i]=(char)toupper((char)prenume[i]);
     }
     for(i=0;i<linie;i++){
	  if(strcmp(date[i].nume,nume)!=0&&strcmp(date[i].prenume,prenume)!=0)
	    contor++;
	 }
    if(contor==linie)
        printf("Nu exista userul cautat!\n");
    else{
        printf("Introduceti suma pe care vreti sa o retrageti userului %s %s!\n",nume,prenume);
        scanf("%lf",&rtgr);
        if(rtgr<0)
            rtgr*=-1;
        for(i=0;i<linie;i++){
            if(strcmp(date[i].nume,nume)==0 && strcmp(date[i].prenume,prenume)==0)
                date[i].suma-=rtgr;
     }
      f= fopen(FNAME,"w");
            for(i=0;i<linie;i++){
                fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
            }
            fclose(f);
      printf("Ati retras cu succes suma ceruta de userul %s %s!\n",nume,prenume);
    }
    break;

     case 9:
        printf("Va dorim o zi buna, admin %s %s!\n",date[aux_admin].nume_admin,date[aux_admin].prenume_admin);
        break;
     default:
        printf("Ati introdus o optiune neexistenta!\n");
        printf("Incercati din nou!\n");
        break;
      }
    }while(optiune!=9);
    fclose(f);
    fclose(admin);
    return 0;
  }
  }

  if(aux!=-1){
    printf("\n\nBun venit, %s %s!\n",date[aux].nume,date[aux].prenume);
    do{
      printf("\n1.Interogare sold\n2.Alimentare\n3.Retragere numerar\n4.Schimbare pin\n\n\n9.Exit \n");
      printf("\nAlegeti optiunea!\n");
      f= fopen(FNAME,"r+");
      linie = 0;
      while(fscanf(f,"%d %d %s %s %lf",&date[linie].id,&date[linie].pass,date[linie].nume,date[linie].prenume,&date[linie].suma)==5){
        linie++;
      }
      fclose(f);
      scanf("%d",&optiune);

      switch(optiune){
      case 1:
        printf("\nIn momentul acesta, soldul dumneavoastra este %.2lf lei!\n",date[aux].suma);
        break;

      case 2:
      printf("Introduceti suma cu care vreti sa alimentati cardul!\n");
      scanf("%lf",&add);
      if(add<0)
        add*=-1;
      date[aux].suma += add;
      printf("\nCard alimentat cu succes!\n");
      f= fopen(FNAME,"w");
      for(i=0;i<linie;i++){
        fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
      }
      fclose(f);

      break;

      case 3:
      printf("Introduceti suma pe care vreti sa o retrageti!\n");
      scanf("%lf",&rtgr);
      if(rtgr<0)
	rtgr*=-1;
      if(date[aux].suma-rtgr<0){
        printf("\nFonduri insuficiente!\n");
	break;
      }
      else{
	date[aux].suma-=rtgr;
	printf("\nAti retras banii ceruti cu succes!\n");
	f= fopen(FNAME,"w");
      for(i=0;i<linie;i++){
        fprintf(f,"%2d %4d %5s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
      }
    fclose(f);
    }
      break;

    case 4:
        printf("Introduceti noua parola!\n");
        i=0;
        while(1){
            ch = getch();
            if((ch==ENTER && i==4) || (ch == TAB && i==4)){
                pass2[i] = '\0';
                break;
            }
            else if(ch == BKSP){
                if(i>0){
                    i--;
                    printf("\b \b");
                }
            }else if((ch>47 && ch<58) && i<4){
                    pass2[i++] = ch;
                    printf("* \b");
            }
        }
        pass = atoi(pass2);
        date[aux].pass = pass;
        printf("\nParola a fost modificata cu succes!\n");
        f= fopen(FNAME,"w");
        for(i=0;i<linie;i++){
            fprintf(f,"%2d %4d %s %s %.2lf\n",date[i].id,date[i].pass,date[i].nume,date[i].prenume,date[i].suma);
        }
        fclose(f);
        break;

    default:
        printf("\nAti introdus o optiune neexistenta!\n");
        printf("Incercati din nou!\n");
        break;

    case 9:
      printf("\nVa dorim o zi buna, %s %s!\n",date[aux].nume,date[aux].prenume);
      break;
      }
    }while(optiune!=9);
  }
  else
    printf("\n\nDin pacate nu aveti acces!\n");
    fclose(f);
  return 0;
}
