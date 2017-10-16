#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

int main(int nrArg, char *argument[]){
    char text[1024];
    float majuscule=0;
    float totalLitere=0;
    float raport;
    int desc;
    int i;
    int caractereCitite;
    char path[100];
    int newFile;
    char string[100];
    
    if(nrArg<3){
        printf("Usage: %s file dir\n",argument[0]);
        exit(1);
    }
        
    else{
        desc = open(argument[1],O_RDONLY);
        
        if(desc==-1){
            printf("'Desc' este : '%d'\n",desc);
            exit(2);
        }
        
        while((caractereCitite = read(desc,text,1024))>0){
            for(i=0;i<caractereCitite;i++){
                if(isalpha(text[i])){
                    if(text[i]>='A' && text[i]<='Z')
                        majuscule++;
                    totalLitere++;
                }
            }
        }

        sprintf("Litere mari : '%f' , Total Litere : '%f'\n",majuscule,totalLitere);
        
        if(totalLitere > 0)
            raport = majuscule / totalLitere;
        
        sprintf("Raportul majuscule-numarLitere este de '%f'\n",raport);
        
        strcpy(path,argument[2]);
        strcat(path,"/");
        strcat(path,argument[1]);
        
        printf("%s\n",path);
        
        newFile = creat(argument[2], S_IRUSR | S_IWUSR);
        
        write(newFile,string
        
    }
    
    return 0;
}
