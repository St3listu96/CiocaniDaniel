#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int nrArgumente,char *argument[]){
        
        int i,j;
        pid_t pid;
        int status;
    
        if(nrArgumente<3){
            printf("Usage: %s file number",argument[0]);
            exit(1);
        }
        
        for(i=2;i<nrArgumente;i++){
        if((pid = fork())<0){
            printf("Eroare fork.\n");
        }
            if(pid == 0){
                    printf("PID %d -> ",getpid());
                    for(j=1;j<=atoi(argument[i]);j++){
                            printf("%d ",j);
                    }
                    printf("\n");
                    exit(atoi(argument[i]));
                    printf("\n");
            }
        }
        if((pid = fork())<0){
            printf("Eroare fork.\n");
        }
        
        if(pid == 0){
                if(execlp("grep","grep","if",argument[1],NULL))
                    printf("Eroare execlp.\n");
                
                
        }
        
        
        for(i=1;i<nrArgumente;i++){
                wait(&status);
                printf("Status -> %d\n",status);
        }
        
        
        
    
        return 0;
}
