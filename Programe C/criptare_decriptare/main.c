#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main()
{
FILE *fp,*fp1;
int choi;
char name[20],temp[20]={"Temp.txt"},c;
system("cls");
printf("Press 1 to Encrypt:Press 2 to Decrypt");
printf("Enter your Choice:");
scanf("%d",&choi);
switch(choi)
{
case 1:
printf("Enter the filename to Encrypt:");
scanf("%s",name);
fp=fopen(name,"r+");
if(fp==NULL)
  {
     printf("The file %s can't be open",name);
     getch();
     exit(1);
  }
fp1=fopen(temp,"w+");
if(fp1==NULL)
 {
   printf("The file Temp can't be open");
   getch();
   exit(1);
 }
 c=fgetc(fp);
while(c!=EOF)
 {
 fputc((c+name[0]),fp1);
 c=fgetc(fp);
 }
 fclose(fp);
 fclose(fp1);
remove(name);
rename(temp,name);
printf("The file is Encrypted:");
getch();
break;
case 2:
     printf("Enter the Filename to Decrypt:");
     scanf("%s",name);
     fp=fopen(name,"r+");
     fp1=fopen(temp,"w+");
     c=fgetc(fp);
     while(c!=EOF)
                {
                fputc(c-name[0],fp1);
                c=fgetc(fp);
                }
                fclose(fp);
                fclose(fp1);
                remove(name);
                rename(temp,name);
                printf("The file is decrypted:");
                getch();
  }
}
