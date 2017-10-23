#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int files=0;

void countFiles(char *file){
        
    DIR *folder;
    struct stat *info = (struct stat*)malloc(sizeof(struct stat));
    struct dirent *curent;
    
    if(lstat(file,info)<0){
        printf("Eroare.\n");
        exit(2);
    }
    
    if((folder = opendir(file)) == NULL)
        printf("Nu exista directorul specificat.\n");
    
    while((curent = readdir(folder)) != NULL){
        if(lstat(file,info)<0){
            printf("Eroare.\n");
            exit(2);
        }
        
        if(strcmp(curent->d_name, ".") == 0 || strcmp(curent->d_name, "..") == 0)
            continue;
        
        if(S_ISDIR(info->st_mode))
            countFiles(curent->d_name);
        if(S_ISREG(info->st_mode) && ((info->st_mode & S_IROTH)==0))
            files++;
    }
    
    closedir(folder);
}


int main(int nrArg, char *argument[]){

    
    
    if(nrArg<2){
        printf("Usage: %s dir\n",argument[0]);
        exit(1);
    }

    countFiles(argument[1]);
    
    printf("Exista %d fisiere. \n",files);
    
    
    
    
    return 0;
}
