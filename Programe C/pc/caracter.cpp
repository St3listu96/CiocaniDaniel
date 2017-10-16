//se da un caracter. Determinati daca este cifra, majuscula, minuscula sau operator aritmetic.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char x;
int main(){
    printf("Dati caracterul: ");
    scanf("%c",&x);
    switch(x){
              case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':printf("\nEste cifra\n");break;
              case'+':case'-':case'*':case'%':case'/':printf("\nEste operator aritmetic\n");break;
              default: if(x>='A'&&x<='Z'){
                                          printf("\nEste majuscula\n");
                                          break;}
                                          else
                                          if(x>='a'&&x<='z'){
                                                              printf("\nEste minuscula\n");
                                                              break;}
                                                              else {
                                                              printf("\nEste alt caracter\n");  
                                                              break; }}
    system("PAUSE");}
