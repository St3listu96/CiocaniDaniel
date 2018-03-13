#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define SAFEALLOC(var,Type) if((var=(Type*)malloc(sizeof(Type)))==NULL)err("Memorie insuficienta");

char *caracter;
enum{COMMA,SEMICOLON,LPAR,RPAR,LBRACKET,RBRACKET,LACC,RACC,ADD,SUB,MUL,DOT,AND,OR,NOT,NOTEQ,ASSIGN,EQUAL,LESS,LESSEQ,GREATER,GREATEREQ,CT_INT,CT_REAL,CT_STRING,CT_CHAR};

typedef struct _Token{
	int code;
	union{
		char *text;
		long int i;
		double r;
	};
	int line;
	struct _Token *next;
}Token;

Token *addToken(int code){ //trebuie bagat si numarul liniei, ca si parametru
	Token *tk;
	Token *tokens=NULL;
	Token *lastToken=NULL;
	SAFEALLOC(tk,Token);
	tk->code = code;
	//tk->line = line;
	tk->next = NULL;
	if(lastToken){
		lastToken->next=tk;
	}
	else{
		tokens=tk;
	}
	lastToken=tk;
	return tk;
}

void err(const char *text,...){
	va_list va;
	va_start(va,text);
	fprintf(stderr,"Eroare: ");
	vfprintf(stderr,text,va);
	fputc('\n',stderr);
	va_end(va);
	exit(-1);
}
int getNextToken(){

	int stare=0;
	char ch;
	while(1){
		ch=*caracter;
		switch(stare){
			case 0: if(ch==','){
					stare=1;
					caracter++;
				}
				else if(ch==';'){
					stare=2;
					caracter++;
				}
				else if(ch=='('){
					stare=3;
					caracter++;
				}
				else if(ch==')'){
					stare=4;
					caracter++;
				}
				else if(ch=='['){
					stare=5;
					caracter++;
				}
				else if(ch==']'){
					stare=6;
					caracter++;
				}
				else if(ch=='{'){
					stare=7;
					caracter++;
				}
				else if(ch=='}'){
					stare=8;
					caracter++;
				}
				else if(ch=='+'){
					stare=9;
					caracter++;
				}
				else if(ch=='-'){
					stare=10;
					caracter++;
				}
				else if(ch=='*'){
					stare=11;
					caracter++;
				}
				else if(ch=='.'){
					stare=12;
					caracter++;
				}
				else if(ch=='&'){
					stare=13;
					caracter++;
				}
				else if(ch=='|'){
					stare=15;
					caracter++;
				}
				else if(ch=='!'){
					stare=17;
					caracter++;
				}
				else if(ch=='='){
					stare=20;
					caracter++;
				}
				else if(ch=='<'){
					stare=23;
					caracter++;
				}
				else if(ch=='>'){
					stare=26;
					caracter++;
				}
				


			case 1:	addToken(COMMA);
				return COMMA;
			case 2: addToken(SEMICOLON);
				return SEMICOLON;
			case 3:	addToken(LPAR);
				return LPAR;
			case 4:	addToken(RPAR);
				return RPAR;
			case 5:	addToken(LBRACKET);
				return LBRACKET;			
			case 6:	addToken(RBRACKET);
				return RBRACKET;
			case 7:	addToken(LACC);
				return LACC;
			case 8:	addToken(RACC);
				return RACC;
			case 9:	addToken(ADD);
				return ADD;
			case 10:addToken(SUB);
				return SUB;
			case 11:addToken(MUL);
				return MUL;
			case 12:addToken(DOT);
				return DOT;
			case 13: if(ch=='&'){
					stare=14;
					caracter++;
				}
			case 14:addToken(AND);
				return AND;
			case 15: if(ch=='|'){
					stare=16;
					caracter++;
				}
			case 16:addToken(OR);
				return OR;
			case 17: if(ch=='='){
					stare=19;
					caracter++;
				}
				else{
					stare=18;
				}
			case 18:addToken(NOT);
				return NOT;
			case 19:addToken(NOTEQ);
				return NOTEQ;
			case 20: if(ch=='='){
					stare=22;
					caracter++;
				}
				else{
					stare=21;
				}
			case 21:addToken(ASSIGN);
				return ASSIGN;
			case 22:addToken(EQUAL);
				return EQUAL;
			case 23: if(ch=='='){
					stare=25;
					caracter++;
				}
				else{
					stare=24;
				}
			case 24:addToken(LESS);
				return LESS;
			case 25:addToken(LESSEQ);
				return LESSEQ;
			case 26: if(ch=='='){
					stare=28;
					caracter++;
				}
				else{
					stare=27;
				}
			case 27:addToken(GREATER);
				return GREATER;
			case 28:addToken(GREATEREQ);
				return GREATEREQ;
		}
	}
		
}

int main(){
	
	char buffer[30001];
	int n;

	FILE *fisier;
	fisier = fopen("fisier.txt,"r");
	if(!fisier){
		printf("Eroare deschidere fisier.\n");
		exit(1);
	}

	n = fread(buffer,1,30000,fisier);
	
	while(getNextToken()!=END){
		
	
	}
	

	




	return 0;
}
