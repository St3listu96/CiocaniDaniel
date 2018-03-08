#include <stdio.h>
#include <stdlib.h>

char *caracter;

int getNextToken(){

	int stare=0;
	char ch;
	while(1){
		ch=*caracter;
		switch(stare){
			case 0: if(ch==','){
					s=1;
					caracter++;
				}
				else if(ch==';'){
					s=2;
					caracter++;
				}
				else if(ch=='('){
					s=3;
					caracter++;
				}
				else if(ch==')'){
					s=4;
					caracter++;
				}
				else if(ch=='['){
					s=5;
					caracter++;
				}
				else if(ch==']'){
					s=6;
					caracter++;
				}
				else if(ch=='{'){
					s=7;
					caracter++;
				}
				else if(ch=='}'){
					s=8;
					caracter++;
				}
				else if(ch=='+'){
					s=9;
					caracter++;
				}
				else if(ch=='-'){
					s=10;
					caracter++;
				}
				else if(ch=='*'){
					s=11;
					caracter++;
				}
				else if(ch=='.'){
					s=12;
					caracter++;
				}
				else if(ch=='&'){
					s=13;
					caracter++;
				}
				else if(ch=='|'){
					s=15;
					caracter++;
				}
				else if(ch=='!'){
					s=17;
					caracter++;
				}
				else if(ch=='='){
					s=20;
					caracter++;
				}
				else if(ch=='<'){
					s=23;
					caracter++;
				}
				else if(ch=='>'){
					s=26;
					caracter++;
				}

				break;

			case 1:	addToken(ID);
				return ID;
			case 2: addToken(ID);
				return ID;
			case 3:	addToken(ID);
				return ID;
			case 4:	addToken(ID);
				return ID;
			case 5:	addToken(ID);
				return ID;			
			case 6:	addToken(ID);
				return ID;
			case 7:	addToken(ID);
				return ID;
			case 8:	addToken(ID);
				return ID;
			case 9:	addToken(ID);
				return ID;
			case 10:addToken(ID);
				return ID;
			case 11:addToken(ID);
				return ID;
			case 12:addToken(ID);
				return ID;
			case 13: if(ch=='&'){
					s=14;
					caracter++;
				}
			case 14:addToken(ID)
				return ID;
			case 15: if(ch=='|'){
					s=16;
					caracter++;
				}
			case 16:addToken(ID);
				return ID;
			case 17: if(ch=='='){
					s=19;
					caracter++;
				}
				else{
					s=18;
				}
			case 18:addToken(ID);
				return ID;
			case 19:addToken(ID);
				return ID;
			case 20: if(ch=='='){
					s=22;
					caracter++;
				}
				else{
					s=21;
				}
			case 21:addToken(ID);
				return ID;
			case 22:addToken(ID);
				return ID;
			case 23: if(ch=='='){
					s=25;
					caracter++;
				}
				else{
					s=24;
				}
			case 24:addToken(ID);
				return ID;
			case 25:addToken(ID);
				return ID;
			case 26: if(ch=='='){
					s=28;
					caracter++;
				}
				else{
					s=27;
				}
			case 27:addToken(ID);
				return ID;
			case 28:addToken(ID);
				return ID;












		
}

int main(int nrArg,char *argument[]){
	
	char buffer[30001];
	int n;

	FILE *fisier;
	fisier = fopen(argument[1],"r");
	if(!fisier){
		printf("Eroare deschidere fisier.\n");
		exit(1);
	}

	n = fread(buffer,1,30000,fisier);
	

	

	




	return 0;
}
