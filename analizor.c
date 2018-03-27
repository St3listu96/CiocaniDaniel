#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define SAFEALLOC(var,Type) if((var=(Type*)malloc(sizeof(Type)))==NULL)err("Memorie insuficienta");

char *caracter;
enum{COMMA,SEMICOLON,LPAR,RPAR,LBRACKET,RBRACKET,LACC,RACC,ADD,SUB,MUL,DIV,DOT,AND,OR,NOT,NOTEQ,ASSIGN,EQUAL,LESS,LESSEQ,GREATER,GREATEREQ,CT_INT,CT_REAL,CT_STRING,CT_CHAR,END,BREAK,CHAR,DOUBLE,ELSE,FOR,IF,INT,RETURN,STRUCT,VOID,WHILE,ID};

typedef struct _Token{
	int code;
	union{
		char *text;
		long int i;
		double r;
	};
	
	struct _Token *next;
}Token;
Token *tokens=NULL;
Token *lastToken=NULL;

Token *addToken(int code){
	Token *tk;
	SAFEALLOC(tk,Token)
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
	int lungimeCuvant;
	char ch;
	const char *startCh;
	Token *tk;
	int line=1;
	while(1){
		ch=*caracter;
//printf("%d\n",stare);		
		printf("%c(%d) #%d\n",ch,ch,stare);
		switch(stare){
			case 0: if(ch==','){
					caracter++;
					stare=1;
				}
				else if(ch==';'){
					caracter++;
					stare=2;
				}
				else if(ch=='('){
					caracter++;
					stare=3;
				}
				else if(ch==')'){
					caracter++;
					stare=4;
				}
				else if(ch=='['){
					caracter++;
					stare=5;
				}
				else if(ch==']'){
					caracter++;
					stare=6;
				}
				else if(ch=='{'){
					caracter++;
					stare=7;
				}
				else if(ch=='}'){
					caracter++;
					stare=8;
				}
				else if(ch=='+'){
					caracter++;
					stare=9;
				}
				else if(ch=='-'){
					caracter++;
					stare=10;
				}
				else if(ch=='*'){

					caracter++;
					stare=11;
				}
				else if(ch=='.'){

					caracter++;
					stare=12;
				}
				else if(ch=='&'){

					caracter++;
					stare=13;
				}
				else if(ch=='|'){

					caracter++;
					stare=15;
				}
				else if(ch=='!'){

					caracter++;
					stare=17;
				}
				else if(ch=='='){

					caracter++;
					stare=20;
				}
				else if(ch=='<'){

					caracter++;
					stare=23;
				}
				else if(ch=='>'){

					caracter++;
					stare=26;
				}
				else if(isalpha(ch)||ch=='_'){
					startCh=caracter;
					caracter++;
					stare=29;
				}

				else if(ch=='\n'){
					line++;
					caracter++;
				}
				else if(ch==0){
					addToken(END);
					return END;
				}
				else if(ch==' '||ch=='\r'||ch=='\t'){
					caracter++;
				}
				else if(ch>='1'&&ch<='9'){
					caracter++;
					stare=31;
				}
				else if(ch=='0'){
					caracter++;
					stare=32;
				}
				else if(ch=='/'){
                    			caracter++;
                    			stare=53;
				}

				break;


			case 1:	addToken(COMMA);
				return COMMA;
				break;
			case 2: addToken(SEMICOLON);
				return SEMICOLON;
				break;
			case 3:	addToken(LPAR);
				return LPAR;
				break;
			case 4:	addToken(RPAR);
				return RPAR;
				break;
			case 5:	addToken(LBRACKET);
				return LBRACKET;
				break;
			case 6:	addToken(RBRACKET);
				return RBRACKET;
				break;
			case 7:	addToken(LACC);
				return LACC;
				break;
			case 8:	addToken(RACC);
				return RACC;
				break;
			case 9:	addToken(ADD);
				return ADD;
				break;
			case 10:addToken(SUB);
				return SUB;
				break;
			case 11:addToken(MUL);
				return MUL;
				break;
			case 12:addToken(DOT);
				return DOT;
				break;
			case 13: if(ch=='&'){
					stare=14;
					caracter++;
				}
				break;
			case 14:addToken(AND);
				return AND;
				break;
			case 15: if(ch=='|'){

					caracter++;
					stare=16;
				}
				break;
			case 16:addToken(OR);
				return OR;
				break;
			case 17: if(ch=='='){

					caracter++;
					stare=19;
				}
				else{
					stare=18;
				}
				break;
			case 18:addToken(NOT);
				return NOT;
				break;
			case 19:addToken(NOTEQ);
				return NOTEQ;
				break;
			case 20: if(ch=='='){

					caracter++;
					stare=22;
				}
				else{
					stare=21;
				}
				break;
			case 21:addToken(ASSIGN);
				return ASSIGN;
				break;
			case 22:addToken(EQUAL);
				return EQUAL;
				break;
			case 23: if(ch=='='){

					caracter++;
					stare=25;
				}
				else{
					stare=24;
				}
				break;
			case 24:addToken(LESS);
				return LESS;
				break;
			case 25:addToken(LESSEQ);
				return LESSEQ;
				break;
			case 26: if(ch=='='){

					caracter++;
					stare=28;
				}
				else{
					stare=27;
				}
				break;
			case 27:addToken(GREATER);
				return GREATER;
				break;
			case 28:addToken(GREATEREQ);
				return GREATEREQ;
				break;
			case 29: if(isalnum(ch)||ch=='_'){
						caracter++;
						stare=29;
					}
					else{
					stare=30;
					}
				break;

			case 30:

 					lungimeCuvant=caracter-startCh;
					if(lungimeCuvant==5 && !memcmp(startCh,"break",5))
						tk=addToken(BREAK);
					else if(lungimeCuvant==4 && !memcmp(startCh,"char",4))
						tk=addToken(CHAR);
					else if(lungimeCuvant==6 && !memcmp(startCh,"double",6))
						tk=addToken(DOUBLE);
					else if(lungimeCuvant==4 && !memcmp(startCh,"else",4))
						tk=addToken(ELSE);
					else if(lungimeCuvant==3 && !memcmp(startCh,"for",3))
						tk=addToken(FOR);
					else if(lungimeCuvant==2 && !memcmp(startCh,"if",2))
						tk=addToken(IF);
					else if(lungimeCuvant==3 && !memcmp(startCh,"int",3))
						tk=addToken(INT);
					else if(lungimeCuvant==6 && !memcmp(startCh,"return",6))
						tk=addToken(RETURN);
					else if(lungimeCuvant==6 && !memcmp(startCh,"struct",6))
						tk=addToken(STRUCT);
					else if(lungimeCuvant==4 && !memcmp(startCh,"void",4))
						tk=addToken(VOID);
					else if(lungimeCuvant==5 && !memcmp(startCh,"while",5))
						tk=addToken(WHILE);
					else{
						tk=addToken(ID);
						//tk->text = creezaString(startCh,caracter);
					}
					return tk->code;
					break;

			case 31 : if(isdigit(ch)){
						caracter++;
						stare=31;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					else{
						stare=36;
					}
					break;

			case 32: if(ch=='x'){
						caracter++;
						stare=34;
					}
					else{
						stare=33;
					}
					break;

			case 33: if(ch>='0'&&ch<='7'){
						caracter++;
						stare=33;
					}
					else if(ch=='8' || ch=='9'){
						caracter++;
						stare=37;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					else{
						stare=36;
					}
					break;

			case 34: if(isdigit(ch) || (ch>='a' && ch <='f') || (ch>='A' && ch <= 'F')){
						caracter++;
						stare=35;
					}
					break;

			case 35: if(isdigit(ch) || (ch>='a' && ch <='f') || (ch>='A' && ch <= 'F')){
						caracter++;
						stare=35;
					}
					else{
						stare=36;
					}
					break;

			case 36: addToken(CT_INT);
					return CT_INT;
					break;

			case 37: if(isdigit(ch)){
						caracter++;
						stare=37;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch =='E'){
						caracter++;
						stare=41;
					}
					break;

			case 39: if(isdigit(ch)){
						caracter++;
						stare=40;
					}
					break;

			case 40: if(isdigit(ch)){
						caracter++;
						stare=40;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					break;

			case 41: if(ch=='+' || ch=='-'){
						caracter++;
						stare=42;
					}
					else{
						stare=42;
					}
					break;

			case 42: if(isdigit(ch)){
						caracter++;
						stare=43;
					}
					break;

			case 43: if(isdigit(ch)){
						caracter++;
						stare=43;
					}
					else{
						stare=44;
					}
					break;

			case 44: addToken(CT_REAL);
					return CT_REAL;
					break;


            case 53: if(ch=='*'){
                        caracter++;
                        stare=55;
                    }
                    else if(ch=='/'){
                        caracter++;
                        stare=57;
                    }
                    else{
                        stare=54;
                    }
                    break;

            case 54: addToken(DIV);
                    return DIV;
                    break;

            case 55: if(ch!='*'){
                        caracter++;
                    }
                    else if(ch=='*'){
                        caracter++;
                        stare=56;
                    }
                    break;

            case 56: if(ch=='*'){
                        caracter++;
                    }
                    else if(ch!='*' && ch!='/'){
                        caracter++;
                        stare=55;
                    }
                    else if(ch=='/'){
                        caracter++;
                        stare=0;
                    }
                    break;

            case 57: if(ch!='\n' && ch!='\r' && ch!='\0'){
                        caracter++;
                    }
                    else{
                        stare=0;
                    }
			break;

		default: printf("Stare inexistenta.\n");
                    exit(1);
					break;

		}
	}

}

int main(){

	char buffer[30001];
	int n;

	FILE *fisier;
	fisier = fopen("8.c","r");
	if(!fisier){
		printf("Eroare deschidere fisier.\n");
		exit(1);
	}
	n = fread(buffer,1,30000,fisier);
	fclose(fisier);
	buffer[n]='\0';
	caracter=buffer;
	puts(caracter);
	while(getNextToken()!=END){


	}


	return 0;
}
