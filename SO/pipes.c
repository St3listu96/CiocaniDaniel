#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int pipefd[2];
int pipefd2[2];


void childOne(){
    char character;
    int litere=0;
    
    close(pipefd[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);
    while(read(pipefd[0],&character,1)>0){
        litere++;
    }
    close(pipefd[0]);
    printf("Numarul literelor este: %d.\n",litere);
}

void childTwo(){
    char character;
    int litereMici=0;
    close(pipefd[1]);
    close(pipefd[0]);
    close(pipefd2[1]);
    while(read(pipefd2[0],&character,1)>0){
        litereMici++;
    }
    close(pipefd2[0]);
    printf("Numarul literelor mici este : %d.\n",litereMici);
    
}

/*void childThree(){
    
    
    
}*/

int main(int nrArgumente,char *argument[]){
    
        int i;
        int status;
    
        if(nrArgumente != 2){
            printf("Usage: %s file.\n",argument[0]);
            exit(0);
        }
    
        pid_t child[3];
        char caracter;
        int fisier;
        
        if(pipe(pipefd) < 0){
            printf("Eroare la pipe.\n");
            exit(1);
        }
        
        if(pipe(pipefd2) < 0){
            printf("Eroare la pipe.\n");
            exit(20);
            
        }
        
        for(i=0;i<2;i++){
            child[i]=fork();
            if(child[i]<0){
                printf("Eroare fork.\n");
                exit(i+2);
            }
            if(i==0 && child[i]==0){
                childOne(pipefd2);
                exit(6);
                
            }
            
            if(i==1 && child[i]==0){
                childTwo(pipefd);
                exit(7);
            }
            
            /*if(i==2 && child==0){
                childThree();
                exit(8);
            }*/
        }
        
        fisier = open(argument[1],O_RDONLY);
        if(fisier < 0){
            printf("Eroare deschidere fisier.\n");
            exit(9);
        }
        
        close(pipefd[0]);
        close(pipefd2[0]);
        while(read(fisier,&caracter,1)>0){
            write(pipefd[1], &caracter, 1);
            if(caracter >= 'a' && caracter <= 'z')
                write(pipefd2[1],&caracter,1);
        }
        
        close(pipefd[1]);
        close(pipefd2[1]);
        
        /*int status1;
        int status2;
  
  waitpid(child[0], &status1, 0);
  waitpid(child[1], &status2, 0);
  
  
  
  if(WIFEXITED(status))
    return WEXITSTATUS(status);*/
             
    
    
    return 0;
}
