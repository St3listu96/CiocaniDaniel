//Se introduce o data de forma zi/luna. Calculati cate zile mai sunt pana la sfarsitul anului. (Anul nu e bisect)
#include<stdio.h>
#include<stdlib.h>
int z,l;
int main(){
    printf("Introduceti data de forma zi/luna: ");
    scanf("%d/%d",&z,&l);
    switch(l){
              case 1: printf("Mai sunt %d zile pana la sfarsitul anului\n",365-z); break;
              case 2: printf("Mai sunt %d zile pana la sfarsitul anului\n",334-z); break;
              case 3: printf("Mai sunt %d zile pana la sfarsitul anului\n",306-z); break;
              case 4: printf("Mai sunt %d zile pana la sfarsitul anului\n",275-z); break;
              case 5: printf("Mai sunt %d zile pana la sfarsitul anului\n",245-z); break;
              case 6: printf("Mai sunt %d zile pana la sfarsitul anului\n",214-z); break;
              case 7: printf("Mai sunt %d zile pana la sfarsitul anului\n",184-z); break;
              case 8: printf("Mai sunt %d zile pana la sfarsitul anului\n",153-z); break;
              case 9: printf("Mai sunt %d zile pana la sfarsitul anului\n",122-z); break;
              case 10: printf("Mai sunt %d zile pana la sfarsitul anului\n",92-z); break;
              case 11: printf("Mai sunt %d zile pana la sfarsitul anului\n",62-z); break;
              default: printf("Mai sunt %d zile pana la sfarsitul anului\n",31-z); break;}
    system("PAUSE");}
              
