//Se da o operatie de forma x/operator/y. Faceti operatia. (ex: 4/+/7 => 4+7=11)
#include<stdio.h>
#include<stdlib.h>
int a,b,r,corect;
char op;
int main(){
    printf("Dati operatia de forma nr/operator/nr:\n");
    scanf("%d/%c/%d",&a,&op,&b);
    corect=1;
    switch(op){
               case '+':r=a+b; break;
               case '-':r=a-b; break;
               case '*':r=a*b; break;
               case '%':r=a%b; break;
               case '/':if(b!=0)
                                r=a/b;
                        else
                             printf("Impartire imposibila\n");
                        break;                            
               default:corect=0;printf("Operatorul nu este corect\n");}
    if(corect)
    printf("%d %c %d = %d\n",a,op,b,r);
    system("PAUSE");
    return 0;}
