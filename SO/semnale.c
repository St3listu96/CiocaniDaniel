#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t child_pid =0;
char caracter;

void procesParinte_trimite(int sig){	
	p='*';
}

void proceParinte_end(){
	int status;
	wait(&status);
	printf("PID fiu : %d.\n",status);
	printf("Procesul parinte s-a terminat.\n");
}

void procesParinte(){
	
	caracter='+';
	struct sigaction paction;
	pact.sa_flags = 0;
	pact.sa_handler= procesParinte_trimite;

	if(sigaction(SIGUSR1,&paction,NULL)==SIG_ERR){
		printf("Eroare.\n");
		exit(5);
	}

	struct sigaction paction2;
	paction2.sa_flags = 0;
	paction2.sa_handler= procesParinte_end;
	
	if(sigaction(SIGCHLD,&paction,NULL)==SIG_ERR){
		printf("Eroare.\n");
		exit(5);
	}

	while(1){
		printf("%c",caracter);
	}
}

void procesFiu_trimite(int sig){
	if(kill(getppid(),SIGUSR1)!=0){
		printf("Eroare la trimiterea semnalului.\n");
		exit(2);
	}
}

void procesFiu(int a0,int r, int n){
	int i;
	double rezultat=a0;

	struct sigaction faction;
	faction.sa_flags = 0;
	faction.sa_handler= procesFiu_trimite;
	if(sigaction(SIGALARM,&act,NULL) == SIG_ERR){
		printf("Eroare SIGALARM.\n");
		exit(3);
	}	
	alarm(1);

	for(i=1;i<n;i++){
		rezultat = rezultat +1/r;
	}
}






int main(int nrArgumente, char *argument[]){
	if(nrArgumente != 4)
		printf("Usage: %s a0 r n.\n",argument[0]);
	signal(SIGUSR1, SIG_IGN);
  	
	if((child_pid = fork()) <0){
		printf("Eroare creare fiu.\n");
		exit(1);
	}

	if(child_pid == 0){
		procesFiu(atoi(argument[1]),atoi(argument[2]),atoi(argument[3]));
	}
	else{
		procesParinte();
	}

	while(1){
		printf("+");
	}

	return 0;
}
