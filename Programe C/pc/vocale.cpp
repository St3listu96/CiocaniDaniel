//Se introduc caractere pana la intalnirea caracterului '*'. Numarati vocalele.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char c;
int k;
int main(){
    while((c=getchar())!='*')
                            switch(tolower(c)){
                                              case'a':case'e':case'i':case'o':case'u':k++;}                            
    printf("Sunt %d vocale\n",k);
    system("pause");}
